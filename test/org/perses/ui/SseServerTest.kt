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

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import java.net.InetSocketAddress
import java.net.Socket
import java.net.URI
import java.net.http.HttpClient
import java.net.http.HttpRequest
import java.net.http.HttpResponse
import java.nio.charset.StandardCharsets

/**
 * Exercises [SseServer] over a real loopback connection: page serving, the SSE frame format,
 * replay of buffered history to a late client, live streaming, and fan-out to multiple clients.
 * Everything runs in-process against an OS-assigned port (requestedPort = 0).
 */
@RunWith(JUnit4::class)
class SseServerTest {
  private val server = SseServer(requestedPort = 0, pageHtml = "<html>PAGE-MARKER</html>")
  private val openClients = mutableListOf<SseClient>()

  @After
  fun teardown() {
    openClients.forEach { it.close() }
    server.close()
  }

  /** A minimal SSE client: opens `/events` and accumulates the streamed text. */
  private inner class SseClient : AutoCloseable {
    private val socket = Socket().apply { soTimeout = READ_TIMEOUT_MILLIS }
    private val received = StringBuilder()
    private val buffer = ByteArray(8192)

    init {
      socket.connect(InetSocketAddress("127.0.0.1", server.port), READ_TIMEOUT_MILLIS)
      socket.getOutputStream().apply {
        write("GET /events HTTP/1.1\r\nHost: localhost\r\n\r\n".toByteArray(StandardCharsets.UTF_8))
        flush()
      }
      openClients.add(this)
    }

    /** Reads until [marker] appears or the socket times out; returns everything seen so far. */
    fun awaitContains(marker: String): String {
      val input = socket.getInputStream()
      while (!received.contains(marker)) {
        val n =
          try {
            input.read(buffer)
          } catch (_: java.net.SocketTimeoutException) {
            break
          }
        if (n < 0) break
        received.append(String(buffer, 0, n, StandardCharsets.UTF_8))
      }
      return received.toString()
    }

    override fun close() {
      try {
        socket.close()
      } catch (_: Exception) {
        // best effort
      }
    }
  }

  @Test
  fun servesTheDashboardPage() {
    val client = HttpClient.newHttpClient()
    val response =
      client.send(
        HttpRequest.newBuilder(URI.create("http://127.0.0.1:${server.port}/")).build(),
        HttpResponse.BodyHandlers.ofString(),
      )
    assertThat(response.statusCode()).isEqualTo(200)
    assertThat(response.body()).contains("PAGE-MARKER")
  }

  @Test
  fun replaysHistoryThenStreamsLiveFrames() {
    // Broadcast before any client connects: the start frame plus one rolling frame must be
    // replayed to a client that arrives afterwards.
    server.broadcast("reduction-start", "{\"initialTokens\":100}")
    server.broadcast("progress", "{\"executions\":7}")

    val client = SseClient()
    val replayed = client.awaitContains("\"executions\":7")
    assertThat(replayed).contains("event: reduction-start")
    assertThat(replayed).contains("data: {\"initialTokens\":100}")
    assertThat(replayed).contains("event: progress")

    // A frame broadcast while connected is delivered live.
    server.broadcast("best-update", "{\"tokens\":42}")
    val live = client.awaitContains("\"tokens\":42")
    assertThat(live).contains("event: best-update")
  }

  @Test
  fun broadcastsToMultipleClients() {
    val a = SseClient()
    val b = SseClient()
    server.broadcast("best-update", "{\"tokens\":5}")
    assertThat(a.awaitContains("\"tokens\":5")).contains("event: best-update")
    assertThat(b.awaitContains("\"tokens\":5")).contains("event: best-update")
  }

  companion object {
    private const val READ_TIMEOUT_MILLIS = 4000
  }
}
