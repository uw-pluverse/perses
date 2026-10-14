#!/usr/bin/env bash
#
# Cross-distro check for a built Perses snap.
#
#   snap/local/verify-distros.sh [path/to/perses_*.snap]
#
# A classic snap runs against the host's root filesystem, so nothing stops a
# bundled binary from picking up the host's loader and libc; it then breaks on
# every distro whose glibc is older than the base's. This script checks that
# the payload is self-contained in two ways:
#
#   1. Static: every ELF executable names the base snap's loader, and every ELF
#      file carries a RUNPATH, so no lookup falls through to the host.
#   2. Dynamic: the unpacked snap is mounted at /snap/<name>/current, with the
#      base at /snap/<base>/current, inside a container of each distro below,
#      where `perses --version`, the bundled javac and an end-to-end reduction
#      must all work.
#
# The containers have no snapd, so this covers the payload, not the install
# path; verify-snap.sh covers a real `snap install` on the host. Needs docker,
# unsquashfs, and the base snap installed on the host. No sudo.
#
# Override the distro list with DISTROS="debian:11 fedora:42".
set -uo pipefail

ROOT="$(git -C "$(dirname "$0")" rev-parse --show-toplevel)"
SNAP_NAME="$(awk '/^name:/{print $2; exit}' "$ROOT/snap/snapcraft.yaml")"
BASE="$(awk '/^base:/{print $2; exit}' "$ROOT/snap/snapcraft.yaml")"
BASE_DIR="/snap/$BASE/current"

# Chosen to span glibc from older than the base's (the case that breaks an
# unpatched payload) to newer, across the deb, rpm and pacman families.
DISTROS="${DISTROS:-ubuntu:18.04 ubuntu:20.04 ubuntu:22.04 ubuntu:24.04 \
debian:10 debian:11 debian:12 debian:13 fedora:42 centos:7 rockylinux:8 \
rockylinux:9 amazonlinux:2 amazonlinux:2023 opensuse/leap:15.6 \
opensuse/tumbleweed archlinux:latest}"

SNAP_FILE="${1:-}"
if [ -z "$SNAP_FILE" ]; then
  SNAP_FILE="$(ls -t "$ROOT/${SNAP_NAME}"_*.snap 2>/dev/null | head -1)"
fi

for tool in docker unsquashfs readelf; do
  command -v "$tool" >/dev/null 2>&1 || { echo "error: '$tool' not found." >&2; exit 2; }
done
[ -n "$SNAP_FILE" ] && [ -f "$SNAP_FILE" ] || {
  echo "error: no snap file. Build one first or pass a path." >&2; exit 2
}
[ -d "$BASE_DIR" ] || { echo "error: $BASE_DIR missing; sudo snap install $BASE." >&2; exit 2; }

pass=0 fail=0
ok()  { printf '  \033[32mPASS\033[0m %s\n' "$1"; pass=$((pass + 1)); }
bad() { printf '  \033[31mFAIL\033[0m %s\n' "$1"; fail=$((fail + 1)); }

work="$(mktemp -d)"
trap 'rm -rf "$work"' EXIT
echo ">> Verifying: $SNAP_FILE"
unsquashfs -q -d "$work/snap" "$SNAP_FILE" >/dev/null || { echo "error: unsquashfs failed." >&2; exit 2; }

echo ">> Static ELF audit"
expected_interp="$BASE_DIR/lib64/ld-linux-x86-64.so.2"
bad_interp=() no_runpath=()
while IFS= read -r -d '' f; do
  [ "$(head -c4 "$f" | od -An -c | tr -d ' ')" = '177ELF' ] || continue
  interp="$(readelf -l "$f" 2>/dev/null | sed -n 's/.*program interpreter: \(.*\)\]/\1/p')"
  [ -z "$interp" ] || [ "$interp" = "$expected_interp" ] || bad_interp+=("${f#"$work/snap/"} -> $interp")
  readelf -d "$f" 2>/dev/null | grep -Eq '\((RUNPATH|RPATH)\)' || no_runpath+=("${f#"$work/snap/"}")
done < <(find "$work/snap" -type f -print0)
if [ ${#bad_interp[@]} -eq 0 ]; then
  ok "every executable uses $expected_interp"
else
  bad "${#bad_interp[@]} executables use another loader, e.g. ${bad_interp[0]}"
fi
if [ ${#no_runpath[@]} -eq 0 ]; then
  ok "every ELF file has an RPATH/RUNPATH"
else
  bad "${#no_runpath[@]} ELF files have no RPATH/RUNPATH, e.g. ${no_runpath[0]}"
fi

mkdir "$work/case"
cat > "$work/case/t.c" <<'EOF'
int main() {
  int KEEP = 0;
  int unused_variable = 12345;
  return 0;
}
EOF
cat > "$work/case/r.sh" <<'EOF'
#!/bin/sh
grep -q 'KEEP' t.c
EOF
cat > "$work/probe.sh" <<'EOF'
#!/bin/sh
export SNAP="$1"
cp -r /case /tmp/case && cd /tmp/case || exit 1
"$SNAP/bin/perses" --version >/tmp/log 2>&1 || { echo "perses --version: $(head -1 /tmp/log)"; exit 1; }
"$SNAP"/usr/lib/jvm/java-17-openjdk-*/bin/javac -version >/tmp/log 2>&1 || { echo "javac: $(head -1 /tmp/log)"; exit 1; }
"$SNAP/bin/perses" --test-script r.sh --input-file t.c >/tmp/log 2>&1 || { echo "reduction: $(tail -1 /tmp/log)"; exit 1; }
[ "$(wc -c < perses_result/t.c)" -lt "$(wc -c < t.c)" ] && grep -q KEEP perses_result/t.c \
  || { echo "reduction: result not smaller or no longer interesting"; exit 1; }
EOF
chmod +x "$work/case/r.sh" "$work/probe.sh"

echo ">> Running in containers"
for distro in $DISTROS; do
  out="$(docker run --rm \
    -v "$work/snap:/snap/$SNAP_NAME/current:ro" \
    -v "$BASE_DIR:$BASE_DIR:ro" \
    -v "$work/case:/case:ro" \
    -v "$work/probe.sh:/probe.sh:ro" \
    "$distro" /probe.sh "/snap/$SNAP_NAME/current" 2>&1)"
  if [ $? -eq 0 ]; then ok "$distro"; else bad "$distro: $(tail -1 <<<"$out")"; fi
done

echo ">> Result: $pass passed, $fail failed"
[ "$fail" -eq 0 ]
