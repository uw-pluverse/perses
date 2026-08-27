#!/usr/bin/env bash
#
# Semi-automatic smoke test for a built Perses snap.
#
#   snap/local/verify-snap.sh [path/to/perses_*.snap]
#
# Installs the snap (needs sudo — the "semi" part), runs functional checks, and
# removes it again. Pass KEEP=1 to leave it installed:
#
#   KEEP=1 snap/local/verify-snap.sh
#
# Checks:
#   1. `perses --help` launches (bundled JDK runs the fat jar).
#   2. The bundled runtime is a JDK: javac works and the jdk.compiler module is
#      present (the reason we bundle a JDK, not a JRE).
#   3. End-to-end out-of-place reduction produces a smaller result that still
#      satisfies a self-contained interestingness test.
set -uo pipefail

ROOT="$(git -C "$(dirname "$0")" rev-parse --show-toplevel)"
SNAP_NAME="$(awk '/^name:/{print $2; exit}' "$ROOT/snap/snapcraft.yaml")"

SNAP_FILE="${1:-}"
if [ -z "$SNAP_FILE" ]; then
  SNAP_FILE="$(ls -t "$ROOT/${SNAP_NAME}"_*.snap 2>/dev/null | head -1)"
fi

pass=0 fail=0
ok()   { printf '  \033[32mPASS\033[0m %s\n' "$1"; pass=$((pass + 1)); }
bad()  { printf '  \033[31mFAIL\033[0m %s\n' "$1"; fail=$((fail + 1)); }
info() { printf '  ---- %s\n' "$1"; }

# --- Preflight -------------------------------------------------------------
command -v snap >/dev/null 2>&1 || { echo "error: 'snap' not found; install snapd." >&2; exit 2; }
[ -n "$SNAP_FILE" ] && [ -f "$SNAP_FILE" ] || {
  echo "error: no snap file. Build one first (snap/local/build-snap.sh) or pass a path." >&2
  exit 2
}
echo ">> Verifying: $SNAP_FILE (snap name: $SNAP_NAME)"

# --- Install (sudo) --------------------------------------------------------
echo ">> Installing (sudo may prompt) ..."
sudo snap remove "$SNAP_NAME" >/dev/null 2>&1 || true
if ! sudo snap install --classic --dangerous "$SNAP_FILE"; then
  echo "error: install failed." >&2; exit 2
fi
cleanup() {
  if [ "${KEEP:-0}" = 1 ]; then
    echo ">> KEEP=1 set; leaving '$SNAP_NAME' installed."
  else
    echo ">> Removing '$SNAP_NAME' ..."
    sudo snap remove "$SNAP_NAME" >/dev/null 2>&1 || true
  fi
}
trap cleanup EXIT

BIN="/snap/bin/$SNAP_NAME"
echo ">> Running checks"

# --- 1. Launcher + JVM + jar load ------------------------------------------
help_out="$("$BIN" --help 2>&1)"
if [ $? -eq 0 ] && grep -q "org.perses.Main" <<<"$help_out"; then
  ok "perses --help runs and reports org.perses.Main"
else
  bad "perses --help failed or output unexpected"
fi

# --- 2. Bundled runtime is a JDK (compiler present) ------------------------
JAVAC="$(ls "/snap/$SNAP_NAME/current"/usr/lib/jvm/*/bin/javac 2>/dev/null | head -1)"
JAVA="$(ls "/snap/$SNAP_NAME/current"/usr/lib/jvm/*/bin/java 2>/dev/null | head -1)"
if [ -n "$JAVAC" ] && "$JAVAC" -version >/dev/null 2>&1; then
  ok "bundled javac works ($("$JAVAC" -version 2>&1))"
else
  bad "bundled javac missing or broken (would break the in-process compiler API)"
fi
if [ -n "$JAVA" ] && "$JAVA" --list-modules 2>/dev/null | grep -q '^jdk.compiler'; then
  ok "bundled runtime exposes the jdk.compiler module"
else
  bad "jdk.compiler module absent (ToolProvider.getSystemJavaCompiler() would return null)"
fi

# --- 3. End-to-end out-of-place reduction ----------------------------------
work="$(mktemp -d)"
cat > "$work/t.c" <<'EOF'
int main() {
  int KEEP = 0;
  int unused_variable = 12345;
  return 0;
}
EOF
cat > "$work/r.sh" <<'EOF'
#!/usr/bin/env bash
grep -q 'KEEP' t.c
EOF
chmod +x "$work/r.sh"
orig_size="$(wc -c < "$work/t.c")"

( cd "$work" && "$BIN" --test-script r.sh --input-file t.c ) >"$work/run.log" 2>&1
rc=$?
result="$work/perses_result/t.c"
if [ $rc -eq 0 ] && [ -f "$result" ]; then
  new_size="$(wc -c < "$result")"
  if [ "$new_size" -lt "$orig_size" ] && grep -q 'KEEP' "$result"; then
    ok "reduction produced a smaller result ($orig_size -> $new_size bytes) that still passes the test"
  elif grep -q 'KEEP' "$result"; then
    bad "reduction ran but did not shrink the input ($orig_size -> $new_size bytes)"
  else
    bad "reduced result no longer satisfies the interestingness test"
  fi
  info "input t.c untouched? $([ "$(wc -c < "$work/t.c")" = "$orig_size" ] && echo yes || echo NO)"
else
  bad "reduction failed (exit $rc); see $work/run.log"
  work=""   # keep the dir for debugging
fi
[ -n "$work" ] && rm -rf "$work"

# --- Summary ---------------------------------------------------------------
echo ">> Result: $pass passed, $fail failed"
[ "$fail" -eq 0 ]
