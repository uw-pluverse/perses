#!/usr/bin/env python3

import os
import unittest
import tempfile
import check_copyright


TINY_COPYRIGHT = ["This is a sample message.\n"] *3
TINY_COPYRIGHT_CMTBLK = "/*\n" + " * This is a sample message.\n" *3 + ' */\n'


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
        l = check_copyright.get_files(self.folder, 'cpp')
        self.assertEqual(l, [])


    def test_check_copyright(self):
        self.assertFalse(check_copyright.check_copyright(self.java_temp_file.name, TINY_COPYRIGHT))
        with open(self.java_temp_file.name, 'r+') as java_file:
            old_content = java_file.read()
            new_content = TINY_COPYRIGHT_CMTBLK + old_content
            java_file.write(new_content)
        self.assertTrue(check_copyright.check_copyright(self.java_temp_file.name, TINY_COPYRIGHT))

    def test_check_folder(self):
        l = check_copyright.check_folder(self.folder, 'java', TINY_COPYRIGHT)
        self.assertTrue(self.java_temp_file.name in l)


    def test_comment_block_factory(self):
        self.assertEqual(check_copyright.comment_block_factory(TINY_COPYRIGHT), TINY_COPYRIGHT_CMTBLK)


    def test_update_files(self):
        with open(self.java_temp_file.name) as java_file:
            old_content = java_file.read()
        check_copyright.update_files([self.java_temp_file.name], TINY_COPYRIGHT)
        with open(self.java_temp_file.name) as java_file:
            new_content = java_file.read()
        self.assertEqual(new_content, TINY_COPYRIGHT_CMTBLK + old_content)


if __name__ == '__main__':

    unittest.main()
