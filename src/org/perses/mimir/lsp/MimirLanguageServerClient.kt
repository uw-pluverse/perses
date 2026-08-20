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
package org.perses.mimir.lsp

import org.eclipse.lsp4j.MessageParams
import org.eclipse.lsp4j.PublishDiagnosticsParams
import org.eclipse.lsp4j.RegistrationParams
import org.eclipse.lsp4j.ShowMessageRequestParams
import org.eclipse.lsp4j.UnregistrationParams
import org.eclipse.lsp4j.services.LanguageClient
import java.util.concurrent.CompletableFuture

class MimirLanguageServerClient : LanguageClient {
  override fun telemetryEvent(obj: Any?) {}

  override fun publishDiagnostics(params: PublishDiagnosticsParams) {}

  override fun showMessage(messageParams: MessageParams) {
  }

  override fun showMessageRequest(params: ShowMessageRequestParams) = null

  override fun logMessage(message: MessageParams) {
  }

  /**
   * JLS (Java Language Server) sends dynamic registration requests during initialization.
   * We implement these as no-ops to satisfy the protocol and prevent crashes.
   */
  override fun registerCapability(params: RegistrationParams) =
    CompletableFuture.completedFuture(null as Void?)

  override fun unregisterCapability(params: UnregistrationParams) =
    CompletableFuture.completedFuture(null as Void?)
}
