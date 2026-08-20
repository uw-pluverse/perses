/*
 * Copyright (C) 2018-2026 University of Waterloo.
 *
 * This file is part of Perses.
 *
 * Perses is free software; you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 3, or (at your option) any later version.
 *
 * Perses is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * Perses; see the file LICENSE.  If not see <http://www.gnu.org/licenses/>.
 */
package org.perses.ui

import com.google.common.util.concurrent.ThreadFactoryBuilder
import com.sun.net.httpserver.HttpExchange
import com.sun.net.httpserver.HttpServer
import java.io.IOException
import java.net.InetSocketAddress
import java.nio.charset.StandardCharsets
import java.util.ArrayDeque
import java.util.concurrent.CopyOnWriteArrayList
import java.util.concurrent.Executors
import java.util.concurrent.LinkedBlockingQueue

/**
 * The sink [WebUiListener] pushes SSE frames to. [SseServer] is the production implementation;
 * tests substitute a capturing fake so the listener's event-to-JSON logic can be exercised
 * without binding a socket.
 */
interface ReductionEventSink : AutoCloseable {
  fun broadcast(eventName: String, jsonData: String)
}

/**
 * A minimal Server-Sent-Events broadcaster over the JDK's built-in [HttpServer], so the
 * live UI needs no third-party HTTP/WebSocket dependency.
 *
 * Serves the dashboard at `/` and an event stream at `/events`. Recent frames are buffered
 * and replayed to each newly-connected client so a browser opened mid-reduction is brought
 * up to date rather than seeing only the tail of the run.
 *
 * Binds to loopback only: the stream exposes the program under reduction, so it must not be
 * reachable off-host. Remote viewing is expected to go through an SSH tunnel.
 */
class SseServer(
  requestedPort: Int,
  private val pageHtml: String,
) : ReductionEventSink {
  private val server: HttpServer = HttpServer.create()

  /** One queue per open `/events` connection; the connection's handler thread drains it. */
  private val clients = CopyOnWriteArrayList<LinkedBlockingQueue<Any>>()

  /**
   * Frames replayed to late-connecting clients. Guarded by [historyLock]. The start frame is
   * kept separately and never evicted so a late client always learns the initial size (needed
   * for the reduction-ratio baseline), while the high-volume frames stay in a bounded ring.
   */
  private val historyLock = Any()
  private var startFrame: String? = null
  private val rollingHistory = ArrayDeque<String>()

  val port: Int
    get() = server.address.port

  init {
    bindToLoopback(requestedPort)
    server.executor =
      Executors.newCachedThreadPool(
        ThreadFactoryBuilder().setNameFormat("perses-ui-http-%d").setDaemon(true).build(),
      )
    server.createContext("/", ::handleRoot)
    server.createContext("/events", ::handleEvents)
    server.start()
  }

  private fun bindToLoopback(requestedPort: Int) {
    try {
      server.bind(InetSocketAddress(LOOPBACK, requestedPort), 0)
    } catch (_: IOException) {
      // The requested port is taken; fall back to an OS-assigned ephemeral port. Callers read
      // the actual port from [port].
      server.bind(InetSocketAddress(LOOPBACK, 0), 0)
    }
  }

  private fun handleRoot(exchange: HttpExchange) {
    exchange.use {
      if (exchange.requestURI.path != "/") {
        exchange.sendResponseHeaders(404, -1)
        return
      }
      val bytes = pageHtml.toByteArray(StandardCharsets.UTF_8)
      exchange.responseHeaders.add("Content-Type", "text/html; charset=utf-8")
      exchange.sendResponseHeaders(200, bytes.size.toLong())
      exchange.responseBody.write(bytes)
    }
  }

  private fun handleEvents(exchange: HttpExchange) {
    exchange.responseHeaders.add("Content-Type", "text/event-stream; charset=utf-8")
    exchange.responseHeaders.add("Cache-Control", "no-cache")
    exchange.responseHeaders.add("Connection", "keep-alive")
    exchange.sendResponseHeaders(200, 0)

    val queue = LinkedBlockingQueue<Any>()
    synchronized(historyLock) {
      startFrame?.let { queue.offer(it) }
      rollingHistory.forEach { queue.offer(it) }
    }
    clients.add(queue)

    val out = exchange.responseBody
    try {
      while (true) {
        val item = queue.take()
        if (item === POISON) break
        out.write((item as String).toByteArray(StandardCharsets.UTF_8))
        out.flush()
      }
    } catch (_: IOException) {
      // Client disconnected; drop it below.
    } catch (_: InterruptedException) {
      Thread.currentThread().interrupt()
    } finally {
      clients.remove(queue)
      exchange.close()
    }
  }

  override fun broadcast(eventName: String, jsonData: String) {
    val frame = "event: $eventName\ndata: $jsonData\n\n"
    synchronized(historyLock) {
      if (eventName == START_EVENT) {
        startFrame = frame
      } else {
        rollingHistory.addLast(frame)
        while (rollingHistory.size > MAX_ROLLING_HISTORY) rollingHistory.removeFirst()
      }
    }
    for (queue in clients) queue.offer(frame)
  }

  override fun close() {
    // Frames already enqueued are FIFO-ahead of POISON, so the final reduction-end frame is
    // delivered before each handler unblocks and closes.
    for (queue in clients) queue.offer(POISON)
    server.stop(1)
  }

  companion object {
    private const val LOOPBACK = "127.0.0.1"
    private const val START_EVENT = "reduction-start"
    private const val MAX_ROLLING_HISTORY = 4096
    private val POISON = Any()
  }
}
