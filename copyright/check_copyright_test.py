#!/usr/bin/env python3

import os
import unittest
import check_copyright as c


SAMPLE_MSG = ["This is a sample message.\n"] *3
SAMPLE_MSG_CMTBLK = "/*\n" + " * This is a sample message.\n" *3 + ' */\n'

FOLDERS = ["dum_dir1", "dum_dir2"]
FILES = ['dum_dir1\dummy1.java', 'dum_dir2\dummy2.java']


class test_check_copyright(unittest.TestCase):

    def test_get_files(self):
        for i, val in enumerate(FOLDERS):
            l = c.get_files(val, "java")
            self.assertEqual(l[0], FILES[i])

    def test_check_copyright(self):
        for file in FILES:
            self.assertFalse(c.check_copyright(file, SAMPLE_MSG))

    def test_check_folder(self):
        l = c.check_folder(os.getcwd(), "java", SAMPLE_MSG)
        for i, val in enumerate(l):
            self.assertTrue(FILES[i] in val)

    def test_comment_block_factory(self):
        self.assertEqual(c.comment_block_factory(SAMPLE_MSG), SAMPLE_MSG_CMTBLK)

    def test_update_files(self):
        c.update_files(FILES, SAMPLE_MSG)
        for file in FILES:
            self.assertTrue(c.check_copyright(file, SAMPLE_MSG))


if __name__ == '__main__':

    for file in FILES:
        os.makedirs(os.path.dirname(file), exist_ok = True)
        with open(file, "w+") as f:
            f.write("import java.util.*;")
    with open("dummy3.txt", 'w+') as f:
        f.write(''.join(SAMPLE_MSG))

    unittest.main(exit=False)

    for file in FILES:
        os.remove(file)
    os.remove("dummy3.txt")
