#!/usr/bin/env python3

import os
import unittest
import tempfile
import check_copyright as c


SAMPLE_MSG = ["This is a sample message.\n"] *3
SAMPLE_MSG_CMTBLK = "/*\n" + " * This is a sample message.\n" *3 + ' */\n'


class TestCheckCopyright(unittest.TestCase):

    java_temp_file = None
    folder = None

    def setUp(self):
        with tempfile.NamedTemporaryFile(suffix='.java', delete=False) as self.java_temp_file:
            self.java_temp_file.write(b"import java.util.*;")
        self.folder = os.path.dirname(self.java_temp_file.name)


    def tearDown(self):
        os.unlink(self.java_temp_file.name)


    def test_get_files(self):
        l = c.get_files(self.folder, 'java')
        self.assertTrue(self.java_temp_file.name in l)


    def test_check_copyright(self):
        self.assertFalse(c.check_copyright(self.java_temp_file.name, SAMPLE_MSG))


    def test_check_folder(self):
        l = c.check_folder(self.folder, 'java', SAMPLE_MSG)
        self.assertTrue(self.java_temp_file.name in l)


    def test_comment_block_factory(self):
        self.assertEqual(c.comment_block_factory(SAMPLE_MSG), SAMPLE_MSG_CMTBLK)


    def test_update_files(self):
        c.update_files([self.java_temp_file.name], SAMPLE_MSG)
        self.assertTrue(c.check_copyright(self.java_temp_file.name, SAMPLE_MSG))


if __name__ == '__main__':

    unittest.main()
