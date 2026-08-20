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

/**
 * The single, self-contained dashboard page served by [SseServer].
 *
 * Kept as a resource-free string literal (no external CSS/JS/fonts/images) so the
 * page renders with the reducer offline and behind an SSH tunnel, and so the UI has
 * no build-time asset-packaging step. The client consumes the `/events` SSE stream
 * whose frame contract is produced by [WebUiListener].
 */
object DashboardHtml {
  // Avoid Kotlin string-template syntax: this literal contains no unescaped '$'. JS below uses
  // string concatenation instead of template literals for the same reason.
  val PAGE: String =
    """
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>Perses Reduction</title>
<style>
  :root {
    --bg: #f6f7f9; --panel: #ffffff; --border: #e2e5ea; --text: #1c1f24;
    --muted: #6b7280; --accent: #2563eb; --good: #15803d; --bad: #b91c1c;
    --grid: #e8ebef; --line: #2563eb; --area: rgba(37,99,235,0.12);
    --line2: #d97706; --area2: rgba(217,119,6,0.12); --rowalt: #f9fafb;
  }
  @media (prefers-color-scheme: dark) {
    :root {
      --bg: #0f1115; --panel: #171a21; --border: #262b34; --text: #e6e8ec;
      --muted: #9aa2af; --accent: #60a5fa; --good: #4ade80; --bad: #f87171;
      --grid: #232833; --line: #60a5fa; --area: rgba(96,165,250,0.16);
      --line2: #fbbf24; --area2: rgba(251,191,36,0.16); --rowalt: #1c202884;
    }
  }
  * { box-sizing: border-box; }
  body {
    margin: 0; background: var(--bg); color: var(--text);
    font: 14px/1.5 -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, Helvetica, Arial, sans-serif;
  }
  header {
    display: flex; align-items: center; gap: 12px; padding: 16px 24px;
    border-bottom: 1px solid var(--border); background: var(--panel);
  }
  header h1 { font-size: 18px; margin: 0; font-weight: 650; }
  .badge {
    margin-left: auto; padding: 4px 12px; border-radius: 999px; font-weight: 600;
    font-size: 12px; letter-spacing: .02em;
  }
  .badge.waiting { background: var(--grid); color: var(--muted); }
  .badge.running { background: rgba(37,99,235,0.15); color: var(--accent); }
  .badge.done { background: rgba(21,128,61,0.16); color: var(--good); }
  main { padding: 24px; max-width: 1180px; margin: 0 auto; }
  .tiles {
    display: grid; grid-template-columns: repeat(auto-fit, minmax(140px, 1fr));
    gap: 14px; margin-bottom: 22px;
  }
  .tile {
    background: var(--panel); border: 1px solid var(--border); border-radius: 12px;
    padding: 14px 16px;
  }
  .tile .label { color: var(--muted); font-size: 12px; text-transform: uppercase; letter-spacing: .04em; }
  .tile .value { font-size: 24px; font-weight: 680; margin-top: 4px; font-variant-numeric: tabular-nums; }
  .tile .sub { color: var(--muted); font-size: 12px; margin-top: 2px; }
  .charts { display: grid; grid-template-columns: 1fr 1fr; gap: 22px; }
  @media (max-width: 780px) { .charts { grid-template-columns: 1fr; } }
  .panel {
    background: var(--panel); border: 1px solid var(--border); border-radius: 12px;
    padding: 16px; margin-bottom: 22px;
  }
  .panel h2 { font-size: 13px; text-transform: uppercase; letter-spacing: .04em; color: var(--muted); margin: 0 0 12px; }
  .chart-wrap { width: 100%; overflow-x: auto; }
  canvas { width: 100%; height: 240px; display: block; }
  #log { max-height: 220px; overflow-y: auto; font: 12.5px/1.6 ui-monospace, SFMono-Regular, Menlo, Consolas, monospace; }
  #log div { padding: 1px 0; color: var(--muted); white-space: pre-wrap; word-break: break-word; }
  #log .hi { color: var(--text); }
  #log .best { color: var(--good); }
  .tbl-wrap { overflow-x: auto; max-height: 340px; overflow-y: auto; }
  table { border-collapse: collapse; width: 100%; font-size: 12.5px; }
  th, td { text-align: right; padding: 5px 10px; white-space: nowrap; font-variant-numeric: tabular-nums; }
  th { position: sticky; top: 0; background: var(--panel); color: var(--muted); font-weight: 600;
       border-bottom: 1px solid var(--border); }
  td.lft, th.lft { text-align: left; }
  tbody tr:nth-child(even) { background: var(--rowalt); }
  td.neg { color: var(--good); }
  .empty { color: var(--muted); font-style: italic; padding: 4px 0; }
</style>
</head>
<body>
<header>
  <h1>Perses Reduction</h1>
  <span id="status" class="badge waiting">waiting</span>
</header>
<main>
  <div class="tiles">
    <div class="tile"><div class="label">Tokens</div><div class="value" id="tokens">&mdash;</div><div class="sub" id="tokensSub">of &mdash; initial</div></div>
    <div class="tile"><div class="label">Reduced</div><div class="value" id="ratio">&mdash;</div><div class="sub">of original size</div></div>
    <div class="tile"><div class="label">Elapsed</div><div class="value" id="elapsed">0s</div><div class="sub">wall clock</div></div>
    <div class="tile"><div class="label">Avg speed</div><div class="value" id="speed">&mdash;</div><div class="sub">tokens / sec</div></div>
    <div class="tile"><div class="label">Test runs</div><div class="value" id="execs">0</div><div class="sub" id="cacheSub">0 cache hits</div></div>
    <div class="tile"><div class="label">Iteration</div><div class="value" id="iter">&mdash;</div><div class="sub" id="reducer">&mdash;</div></div>
  </div>

  <div class="charts">
    <div class="panel">
      <h2>Token count over time</h2>
      <div class="chart-wrap"><canvas id="tokenChart"></canvas></div>
    </div>
    <div class="panel">
      <h2>Average reduction speed (tokens/s)</h2>
      <div class="chart-wrap"><canvas id="speedChart"></canvas></div>
    </div>
  </div>

  <div class="panel">
    <h2>Reducer summary</h2>
    <div class="tbl-wrap"><div id="summary"></div></div>
  </div>

  <div class="panel" id="transformsPanel" style="display:none">
    <h2>Transformations</h2>
    <div class="tbl-wrap"><div id="transforms"></div></div>
  </div>

  <div class="panel">
    <h2>Reducer invocation history <span id="histCount" style="color:var(--muted);font-weight:400"></span></h2>
    <div class="tbl-wrap"><div id="history"></div></div>
  </div>

  <div class="panel">
    <h2>Activity</h2>
    <div id="log"></div>
  </div>
</main>
<script>
"use strict";
(function () {
  var initialTokens = null, currentTokens = null, startMillis = null;
  var serverOffset = 0, ended = false;
  var tokenPoints = [], speedPoints = [];
  var invocations = [];          // reducer-invocation records
  var transforms = {};           // key "reducer.transformation" -> stats
  var HISTORY_RENDER_CAP = 500;

  var el = function (id) { return document.getElementById(id); };
  function fmt(n) { return n == null ? "—" : Math.round(n).toLocaleString(); }
  function setStatus(cls, txt) { var s = el("status"); s.className = "badge " + cls; s.textContent = txt; }

  function nowServer() { return Date.now() - serverOffset; }
  function elapsedMs() { return startMillis == null ? 0 : nowServer() - startMillis; }

  function fmtElapsed(ms) {
    if (ms == null || ms < 0) ms = 0;
    var s = Math.floor(ms / 1000);
    var h = Math.floor(s / 3600), m = Math.floor((s % 3600) / 60), sec = s % 60;
    if (h > 0) return h + "h " + m + "m " + sec + "s";
    if (m > 0) return m + "m " + sec + "s";
    return sec + "s";
  }

  function log(text, kind) {
    var box = el("log");
    var d = document.createElement("div");
    if (kind) d.className = kind;
    d.textContent = text;
    box.appendChild(d);
    while (box.childElementCount > 400) box.removeChild(box.firstChild);
    box.scrollTop = box.scrollHeight;
  }

  function avgSpeed() {
    var sec = elapsedMs() / 1000;
    if (initialTokens == null || currentTokens == null || sec <= 0) return null;
    return (initialTokens - currentTokens) / sec;
  }

  function refreshStats() {
    el("tokens").textContent = fmt(currentTokens);
    el("tokensSub").textContent = "of " + fmt(initialTokens) + " initial";
    if (initialTokens && currentTokens != null && initialTokens > 0) {
      var pct = (100 * (initialTokens - currentTokens) / initialTokens);
      el("ratio").textContent = pct.toFixed(1) + "%";
    }
    var sp = avgSpeed();
    el("speed").textContent = sp == null ? "—" : sp.toFixed(1);
    if (startMillis != null && !ended) el("elapsed").textContent = fmtElapsed(elapsedMs());
  }

  // ---- charts -------------------------------------------------------------
  function drawChart(canvas, points, opts) {
    var css = getComputedStyle(document.documentElement);
    var colLine = css.getPropertyValue(opts.line).trim();
    var colArea = css.getPropertyValue(opts.area).trim();
    var colGrid = css.getPropertyValue("--grid").trim();
    var colMuted = css.getPropertyValue("--muted").trim();
    var ctx = canvas.getContext("2d");
    var dpr = window.devicePixelRatio || 1;
    var w = canvas.clientWidth, h = canvas.clientHeight;
    canvas.width = w * dpr; canvas.height = h * dpr;
    ctx.setTransform(dpr, 0, 0, dpr, 0, 0);
    ctx.clearRect(0, 0, w, h);
    if (points.length < 1) return;
    var padL = 60, padR = 12, padT = 12, padB = 26;
    var maxT = 0, maxV = 0;
    for (var i = 0; i < points.length; i++) {
      if (points[i].t > maxT) maxT = points[i].t;
      if (points[i].v > maxV) maxV = points[i].v;
    }
    if (maxT <= 0) maxT = 1;
    if (maxV <= 0) maxV = 1;
    var x = function (t) { return padL + (t / maxT) * (w - padL - padR); };
    var y = function (v) { return padT + (1 - v / maxV) * (h - padT - padB); };

    ctx.strokeStyle = colGrid; ctx.fillStyle = colMuted;
    ctx.lineWidth = 1; ctx.font = "11px sans-serif"; ctx.textBaseline = "middle";
    for (var g = 0; g <= 4; g++) {
      var v = maxV * g / 4, yy = y(v);
      ctx.beginPath(); ctx.moveTo(padL, yy); ctx.lineTo(w - padR, yy); ctx.stroke();
      ctx.textAlign = "right";
      ctx.fillText((opts.fixed ? v.toFixed(1) : Math.round(v).toLocaleString()), padL - 8, yy);
    }

    ctx.beginPath(); ctx.moveTo(x(0), y(points[0].v));
    for (var j = 0; j < points.length; j++) ctx.lineTo(x(points[j].t), y(points[j].v));
    ctx.lineTo(x(points[points.length - 1].t), y(0)); ctx.lineTo(x(0), y(0)); ctx.closePath();
    ctx.fillStyle = colArea; ctx.fill();

    ctx.beginPath();
    for (var k = 0; k < points.length; k++) {
      var px = x(points[k].t), py = y(points[k].v);
      if (k === 0) ctx.moveTo(px, py); else ctx.lineTo(px, py);
    }
    ctx.strokeStyle = colLine; ctx.lineWidth = 2; ctx.stroke();

    ctx.fillStyle = colMuted; ctx.textAlign = "center"; ctx.textBaseline = "top";
    ctx.fillText("0s", x(0), h - padB + 8);
    ctx.fillText(Math.round(maxT) + "s", w - padR, h - padB + 8);
  }
  function drawTokenChart() {
    drawChart(el("tokenChart"), tokenPoints, { line: "--line", area: "--area", fixed: false });
  }
  function drawSpeedChart() {
    drawChart(el("speedChart"), speedPoints, { line: "--line2", area: "--area2", fixed: true });
  }
  window.addEventListener("resize", function () { drawTokenChart(); drawSpeedChart(); });

  // ---- tables -------------------------------------------------------------
  function td(v, cls) { return "<td class='" + (cls || "") + "'>" + v + "</td>"; }
  function tokCls(n) { return n < 0 ? "neg" : ""; }

  function renderHistory() {
    var start = Math.max(0, invocations.length - HISTORY_RENDER_CAP);
    var html = "<table><thead><tr>" +
      "<th>ID</th><th class='lft'>Reducer</th><th>Worked</th><th>#NonDel</th>" +
      "<th>#Tokens</th><th>#NonBlank</th><th>Queries</th><th>Dur(s)</th></tr></thead><tbody>";
    for (var i = start; i < invocations.length; i++) {
      var r = invocations[i];
      html += "<tr>" + td(r.id) + td(r.reducer, "lft") + td(fmt(r.worked)) +
        td(fmt(r.nonDeletions)) + td(fmt(r.tokens), tokCls(r.tokens)) +
        td(fmt(r.nonBlankChars), tokCls(r.nonBlankChars)) + td(fmt(r.queries)) +
        td(Math.floor(r.durationMillis / 1000)) + "</tr>";
    }
    html += "</tbody></table>";
    el("history").innerHTML = html;
    var extra = start > 0 ? " (showing last " + HISTORY_RENDER_CAP + ")" : "";
    el("histCount").textContent = "— " + invocations.length + " invocation(s)" + extra;
    var wrap = el("history").parentElement;
    wrap.scrollTop = wrap.scrollHeight;
  }

  function renderSummary() {
    var by = {};
    invocations.forEach(function (r) {
      var s = by[r.reducer] || (by[r.reducer] =
        { times: 0, worked: 0, nonDel: 0, tokens: 0, nonBlank: 0, queries: 0, dur: 0 });
      s.times++; s.worked += r.worked; s.nonDel += r.nonDeletions;
      s.tokens += r.tokens; s.nonBlank += r.nonBlankChars; s.queries += r.queries;
      s.dur += r.durationMillis;
    });
    var rows = Object.keys(by).map(function (name) { return { name: name, s: by[name] }; });
    rows.sort(function (a, b) { return a.s.tokens - b.s.tokens || (a.name < b.name ? -1 : 1); });
    if (rows.length === 0) { el("summary").innerHTML = "<div class='empty'>No reducer has run yet.</div>"; return; }
    var html = "<table><thead><tr>" +
      "<th class='lft'>Reducer</th><th>Times</th><th>Worked</th><th>#NonDel</th>" +
      "<th>#Tokens</th><th>#NonBlank</th><th>Queries</th><th>Dur(s)</th></tr></thead><tbody>";
    rows.forEach(function (row) {
      var s = row.s;
      html += "<tr>" + td(row.name, "lft") + td(fmt(s.times)) + td(fmt(s.worked)) +
        td(fmt(s.nonDel)) + td(fmt(s.tokens), tokCls(s.tokens)) +
        td(fmt(s.nonBlank), tokCls(s.nonBlank)) + td(fmt(s.queries)) +
        td(Math.floor(s.dur / 1000)) + "</tr>";
    });
    html += "</tbody></table>";
    el("summary").innerHTML = html;
  }

  function renderTransforms() {
    var keys = Object.keys(transforms);
    if (keys.length === 0) return;
    el("transformsPanel").style.display = "";
    var rows = keys.map(function (k) { return { k: k, s: transforms[k] }; });
    rows.sort(function (a, b) { return a.s.tokens - b.s.tokens || (a.k < b.k ? -1 : 1); });
    var html = "<table><thead><tr>" +
      "<th class='lft'>Transformation</th><th>Worked</th><th>#NonDel</th>" +
      "<th>#Tokens</th><th>#NonBlank</th></tr></thead><tbody>";
    rows.forEach(function (row) {
      var s = row.s;
      html += "<tr>" + td(row.k, "lft") + td(fmt(s.worked)) + td(fmt(s.nonDel)) +
        td(fmt(s.tokens), tokCls(s.tokens)) + td(fmt(s.nonBlank), tokCls(s.nonBlank)) + "</tr>";
    });
    html += "</tbody></table>";
    el("transforms").innerHTML = html;
  }

  // ---- SSE ----------------------------------------------------------------
  var es = new EventSource("/events");

  es.addEventListener("reduction-start", function (e) {
    var d = JSON.parse(e.data);
    initialTokens = d.initialTokens; currentTokens = d.initialTokens;
    startMillis = d.timeMillis; serverOffset = Date.now() - d.timeMillis;
    tokenPoints = [{ t: 0, v: d.initialTokens }]; speedPoints = [{ t: 0, v: 0 }];
    invocations = []; transforms = {};
    setStatus("running", "running");
    log("Reduction started — " + fmt(d.initialTokens) + " tokens", "hi");
    refreshStats(); drawTokenChart(); drawSpeedChart(); renderSummary(); renderHistory();
  });

  es.addEventListener("fixpoint", function (e) {
    var d = JSON.parse(e.data);
    el("iter").textContent = d.iteration;
    el("reducer").textContent = d.reducer;
    log("Fixpoint " + d.iteration + " — " + d.reducer + " (" + fmt(d.tokens) + " tokens)");
  });

  es.addEventListener("best-update", function (e) {
    var d = JSON.parse(e.data);
    currentTokens = d.tokens;
    if (d.reducer) el("reducer").textContent = d.reducer;
    if (d.iteration != null) el("iter").textContent = d.iteration;
    if (startMillis != null) tokenPoints.push({ t: (d.timeMillis - startMillis) / 1000, v: d.tokens });
    var key = d.reducer + "." + d.transformation;
    var s = transforms[key] || (transforms[key] = { worked: 0, nonDel: 0, tokens: 0, nonBlank: 0 });
    var tokenDelta = -d.deleted;   // #Tokens column is after-before (negative when reduced)
    s.worked++; if (tokenDelta >= 0) s.nonDel++;
    s.tokens += tokenDelta; s.nonBlank += d.nonBlankDelta;
    drawTokenChart(); renderTransforms();
    log("New minimal — " + fmt(d.tokens) + " tokens (-" + fmt(d.deleted) + ")", "best");
    refreshStats();
  });

  es.addEventListener("reducer-invocation", function (e) {
    var d = JSON.parse(e.data);
    invocations.push(d);
    renderHistory(); renderSummary();
  });

  es.addEventListener("progress", function (e) {
    var d = JSON.parse(e.data);
    el("execs").textContent = fmt(d.executions);
    el("cacheSub").textContent = fmt(d.cacheHits) + " cache hits";
  });

  es.addEventListener("log", function (e) { log(JSON.parse(e.data).message); });

  es.addEventListener("reduction-end", function (e) {
    var d = JSON.parse(e.data);
    ended = true;
    currentTokens = d.finalTokens;
    el("execs").textContent = fmt(d.executions);
    el("elapsed").textContent = fmtElapsed(d.elapsedMillis);
    if (startMillis != null) {
      tokenPoints.push({ t: (d.timeMillis - startMillis) / 1000, v: d.finalTokens });
      var sec = d.elapsedMillis / 1000;
      if (sec > 0) speedPoints.push({ t: sec, v: (d.initialTokens - d.finalTokens) / sec });
    }
    setStatus("done", "complete");
    log("Reduction complete — " + fmt(d.finalTokens) + " tokens in " + fmtElapsed(d.elapsedMillis), "hi");
    refreshStats(); drawTokenChart(); drawSpeedChart();
    es.close();
  });

  // Sample the average-speed curve on a timer so it advances even between commits.
  setInterval(function () {
    refreshStats();
    if (!ended && startMillis != null) {
      var sp = avgSpeed();
      if (sp != null) { speedPoints.push({ t: elapsedMs() / 1000, v: sp }); drawSpeedChart(); }
    }
  }, 1000);
})();
</script>
</body>
</html>
""".trimIndent()
}
