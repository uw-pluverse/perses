#!/usr/bin/env python3

import os
import unittest
import tempfile
import check_copyright


TINY_COPYRIGHT = ["This is a sample message.\n"] *3
TINY_COPYRIGHT_CMTBLK = "/*\n" + " * This is a sample message.\n" *3 + ' */\n'


class TestCheckCopyright(unittest.TestCase):

    temp_dir = None
    java_temp_file = None
    copyright_checker = check_copyright.CopyrightChecker(TINY_COPYRIGHT)

    def setUp(self):
        self.temp_dir = tempfile.mkdtemp()
        full_path = os.path.join(self.temp_dir, "tmp_file.java")
        with open(full_path, 'w+') as self.java_temp_file:
            self.java_temp_file.write("import java.util.*;")

    def tearDown(self):
        os.unlink(self.java_temp_file.name)
        os.rmdir(self.temp_dir)

    def test_locate_files(self):
        ## Test if locate_files() returns correct list
        file_list = self.copyright_checker.locate_files(self.temp_dir, 'java')
        self.assertEqual(file_list, [self.java_temp_file.name])
        file_list = self.copyright_checker.locate_files(self.temp_dir, 'cpp')
        self.assertEqual(file_list, [])

    def test_check_files(self):
        ## Test for check_files()
        missing_list = self.copyright_checker.check_files([self.java_temp_file.name])
        self.assertEqual(missing_list, [self.java_temp_file.name])

        self.copyright_checker.update_files([self.java_temp_file.name])
        missing_list = self.copyright_checker.check_files([self.java_temp_file.name])
        self.assertEqual(missing_list, [])

    def test_check_copyright(self):
        ## Test check_copyright() with & without comment block
        self.assertFalse(self.copyright_checker.check_copyright(self.java_temp_file.name))
        with open(self.java_temp_file.name, 'r+') as java_file:
            old_content = java_file.read()
            new_content = TINY_COPYRIGHT_CMTBLK + old_content
            java_file.write(new_content)
        self.assertTrue(self.copyright_checker.check_copyright(self.java_temp_file.name))

    def test_update_files(self):
        with open(self.java_temp_file.name) as java_file:
            old_content = java_file.read()
        self.copyright_checker.update_files([self.java_temp_file.name])
        with open(self.java_temp_file.name) as java_file:
            new_content = java_file.read()
        self.assertEqual(new_content, TINY_COPYRIGHT_CMTBLK + old_content)

    def test_update_files_existingcopyright(self):
        with open(self.java_temp_file.name, 'r+') as java_file:
            old_content = java_file.read()
            comment_block = "/* \n * Copyright (C)...\n */\n"
            java_file.seek(0, 0)
            java_file.write(comment_block + old_content)
        self.copyright_checker.update_files([self.java_temp_file.name])
        with open(self.java_temp_file.name) as java_file:
            new_content = java_file.read()
        self.assertEqual(new_content, TINY_COPYRIGHT_CMTBLK + old_content)


if __name__ == '__main__':
    unittest.main()
