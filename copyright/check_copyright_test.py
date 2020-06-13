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
    copyright_checker = check_copyright.Copyright(TINY_COPYRIGHT)
    
    def setUp(self):
        with tempfile.NamedTemporaryFile(suffix='.java', delete=False) as self.java_temp_file:
            self.java_temp_file.write(b"import java.util.*;")
        self.folder = os.path.dirname(self.java_temp_file.name)
        

    def tearDown(self):
        os.unlink(self.java_temp_file.name)


    def test_check_copyright(self):
        self.assertFalse(self.copyright_checker.check_copyright(self.java_temp_file.name))
        with open(self.java_temp_file.name, 'r+') as java_file:
            old_content = java_file.read()
            new_content = TINY_COPYRIGHT_CMTBLK + old_content
            java_file.write(new_content)
        self.assertTrue(self.copyright_checker.check_copyright(self.java_temp_file.name))


    def test_check_folder(self):
        l = self.copyright_checker.check_folder(self.folder, 'java')
        self.assertEqual(l, [self.java_temp_file.name])
        l = self.copyright_checker.check_folder(self.folder, 'cpp')
        self.assertEqual(l,[])


    def test_update_files(self):
        with open(self.java_temp_file.name) as java_file:
            old_content = java_file.read()
        self.copyright_checker.update_files([self.java_temp_file.name])
        with open(self.java_temp_file.name) as java_file:
            new_content = java_file.read()
        self.assertEqual(new_content, TINY_COPYRIGHT_CMTBLK + old_content)


if __name__ == '__main__':

    unittest.main()
