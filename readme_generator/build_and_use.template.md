### Obtain and Run

There are three ways to obtain Perses.

- Download a prebuilt release JAR file from our [release page](https://github.com/perses-project/perses/releases),
  for example,

  ```bash
  wget https://github.com/uw-pluverse/perses/releases/download/v{majorVersion}.{minorVersion}/perses_deploy.jar
  java -jar perses_deploy.jar [options]? --test-script <test-script.sh> --input-file <program file>
  ```

- Clone the repo and build Perses from the source.

  ```bash
  git clone https://github.com/perses-project/perses.git
  cd perses
  bazelisk build //src/org/perses:perses_deploy.jar
  java -jar bazel-bin/src/org/perses/perses_deploy.jar [options]? \
      --test-script <test-script.sh> --input-file <program file>
  ```

- If you want to always use the trunk version of Perses, [perses-trunk](https://github.com/perses-project/perses/blob/master/scripts/perses-trunk) automatically downloads and builds the latest version.

  NOTE: [Bazelisk](https://github.com/bazelbuild/bazelisk) is the prerequisite to run perses-trunk successfully.

  ```bash
  wget https://raw.githubusercontent.com/perses-project/perses/master/scripts/perses-trunk
  chmod +x perses-trunk
  ./perses-trunk [options]? --test-script <test-script.sh> --input-file <program file>
  ```

#### Important Flags

- --test-script **&lt;test-script.sh&gt;**:
  The script encodes the constraints that both of the original program file and the reduced version should satisfy. It should return **0** if the constraints are satisfied.

- --input-file **&lt;program-file&gt;**: the program needs to be reduced. Currently, Perses
  supports C, Rust, Java and Go. Note that we can easily support any other languages,
  if the specific language can be parsed by an Antlr parser.

#### Writing a Robust Test Script

The test script is the oracle that drives the entire reduction: Perses copies the
current candidate program into a fresh working directory, runs the script there,
and keeps the candidate only if the script exits **0** (the property of interest
still holds); otherwise the candidate is discarded. The script
must be deterministic and self-contained — read the program from the working
directory (not an absolute path), avoid side effects outside that directory (or
use temp directories and then clean them up), and never block on interactive input.
Reduced variants routinely provoke compiler crashes, infinite loops, and runaway memory,
so the script must defend against a single candidate hanging the whole run.

Guard every external tool with a wall-clock **`timeout`** (e.g.
`timeout -s KILL 10 cc small.c`) so no single invocation can run forever. This
alone is not enough, though: `timeout` signals only the process it launches, not
that process's descendants. Compiler *drivers* such as `gcc` (which forks `cc1`)
or `ccomp` spawn the real worker as a child, and when the driver is killed that
worker is orphaned to `init`/`systemd` and can keep spinning at 100% CPU
indefinitely — leaking one runaway per bad variant until the machine is starved
(dead-but-unreaped descendants pile up as zombies). To close this gap, also set a
per-process CPU cap with **`ulimit -t <seconds>`** near the top of the script:
unlike `timeout`, `RLIMIT_CPU` is inherited by every descendant and enforced by the
kernel regardless of reparenting, so orphaned runaways are reaped automatically.
Pick the cap above the largest per-tool `timeout` (roughly 2×) so legitimate runs
finish while runaways die, and optionally add `ulimit -v` to bound memory. One last
caveat: if a timed-out tool's output feeds a pipe or `$(...)`, the shell can still
block waiting for EOF because a leaked descendant keeps the pipe's write end open —
redirect tool output to a file rather than a pipe when in doubt.

```bash
#!/bin/bash
# CPU-time cap in seconds, inherited by every descendant: an orphaned compiler
# that escaped `timeout` is still reaped by the kernel via RLIMIT_CPU.
ulimit -t 20
# Wall-clock guard on each tool; -s KILL force-kills a wedged process. Redirect to
# a file (not a pipe) so a leaked descendant cannot stall the script on EOF.
timeout -s KILL 10 clang -O2 -c small.c > log.txt 2>&1
grep -q "internal compiler error" log.txt && exit 0   # property holds
exit 1                                                 # property broken
```

#### Live Web Dashboard

Perses can serve a live web dashboard that visualizes a reduction as it runs: the shrinking
token count, the average reduction speed over time, per-reducer statistics, and the history
of reducer invocations (the same statistics Perses prints at the end of a run, but updated in
real time).

Enable it with `--enable-web-ui true`. Perses prints a `http://127.0.0.1:<port>` URL to open in
a browser. Use `--web-ui-port <port>` to pick the port (default `9000`; if it is already in use,
an ephemeral port is chosen and the actual URL is printed).

```bash
java -jar perses_deploy.jar --enable-web-ui true \
    --test-script <test-script.sh> --input-file <program file>
```

The dashboard binds to localhost only. To watch a reduction that is running on a remote machine,
forward the port over SSH, e.g. `ssh -L 9000:127.0.0.1:9000 <remote-host>`, then open
`http://127.0.0.1:9000` locally.

![Perses live web dashboard](readme_generator/webui_screenshot.png)

Check all available command line arguments

```bash
java -jar perses_deploy.jar  --help
```

The following is the complete list of command line arguments.

