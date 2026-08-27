"""Tests for make_jar_self_executable.sh, whose job is to prepend a shebang to a deploy jar.

The staging must be *atomic*. It is not a theoretical concern: benchmark_v2's sweep runs N
benchmarks concurrently, every worker restages the same four ~80MB jars, and bin/ is
bind-mounted into the container each worker reads them from. The original implementation did

    echo header | cat - "$SRC" > "$TARGET"

which truncates TARGET and then streams 80MB into it. A reader that opened TARGET during that
window got a valid-looking but truncated jar and died with a ClassNotFoundException on a class
that simply had not been written yet -- which took down every subject in a 20-benchmark sweep.

test_a_concurrent_reader_never_sees_a_partial_jar is the regression: it fails against the
truncate-in-place version and passes against the temp-file-plus-rename one.
"""
import os
import shutil
import subprocess
import tempfile
import threading
import unittest
from pathlib import Path

SCRIPT = Path("scripts/make_jar_self_executable.sh").resolve()

HEADER = b'#!/usr/bin/env bash \nexec java -jar "$0" "$@"\n'

# Big enough that a non-atomic write cannot complete between a reader's open() and read().
PAYLOAD = b"x" * (8 * 1024 * 1024)


class MakeJarSelfExecutableTest(unittest.TestCase):

    def setUp(self):
        self.tmp = Path(tempfile.mkdtemp())
        self.source = self.tmp / "source.jar"
        self.source.write_bytes(PAYLOAD)
        self.target = self.tmp / "target.jar"

    def tearDown(self):
        shutil.rmtree(self.tmp, ignore_errors=True)

    def stage(self):
        subprocess.run([str(SCRIPT), str(self.source), str(self.target)], check=True)

    def test_the_staged_jar_is_the_header_followed_by_the_source(self):
        self.stage()
        self.assertEqual(self.target.read_bytes(), HEADER + PAYLOAD)

    def test_the_staged_jar_is_executable(self):
        self.stage()
        self.assertTrue(os.access(self.target, os.X_OK))

    def test_restaging_over_an_existing_jar_replaces_it_exactly(self):
        self.target.write_bytes(b"stale content")
        self.stage()
        self.assertEqual(self.target.read_bytes(), HEADER + PAYLOAD)

    def test_no_temp_files_are_left_behind(self):
        self.stage()
        self.assertEqual(sorted(p.name for p in self.tmp.iterdir()),
                         ["source.jar", "target.jar"])

    def test_a_concurrent_reader_never_sees_a_partial_jar(self):
        """THE regression. While the script restages, a reader must see either the whole old
        jar or the whole new one -- never a prefix of the new one."""
        expected = HEADER + PAYLOAD
        old = b"o" * len(expected)
        self.target.write_bytes(old)

        torn = []
        stop = threading.Event()

        def read_until_stopped():
            while not stop.is_set():
                try:
                    seen = self.target.read_bytes()
                except FileNotFoundError:
                    # Also a torn state: the target must never vanish, even briefly.
                    torn.append("missing")
                    continue
                if seen not in (old, expected):
                    torn.append(f"partial read of {len(seen)} bytes")

        reader = threading.Thread(target=read_until_stopped)
        reader.start()
        try:
            for _ in range(5):
                self.stage()
        finally:
            stop.set()
            reader.join()

        self.assertEqual(torn, [], f"reader observed a torn jar: {torn[:3]}")


if __name__ == "__main__":
    unittest.main()
