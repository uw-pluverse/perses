#!/usr/bin/env python3

import os
import unittest
import tempfile
import check_copyright as c


EXT = ['java', 'kt']
SAMPLE_MSG = ["This is a sample message.\n"] *3
SAMPLE_MSG_CMTBLK = "/*\n" + " * This is a sample message.\n" *3 + ' */\n'


class TestCheckCopyright(unittest.TestCase):

    ## Temp java, kt files
    j1 = None
    k1 = None
    j1_base = None
    k1_base = None
    folder = None
    
    def setUp(self):
        with tempfile.NamedTemporaryFile(suffix='.java', delete=False) as self.j1:
            print(self.j1.name)
            self.j1.write(b"import java.util.*;")
        with tempfile.NamedTemporaryFile(suffix='.kt', delete=False) as self.k1:
            print(self.k1.name)
            self.k1.write(b"import platform.posix.*;")

        self.j1_base = os.path.basename(self.j1.name)
        self.k1_base = os.path.basename(self.k1.name)
        
        self.folder = os.path.dirname(self.j1.name)
        print(self.folder)
        

    def tearDown(self):
        os.unlink(self.j1.name)
        os.unlink(self.k1.name)
        print(os.path.exists(self.j1.name))

        
    def test_get_files(self):
        ## get_files(directory: str, extension: str) -> List[str]:
        l = list()
        for e in EXT:
            l += c.get_files(self.folder, e)
        self.assertTrue(self.j1.name in l)
        self.assertTrue(self.k1.name in l)


    def test_check_copyright(self):
        ## check_copyright(sourcefile: str, rawtext: list) -> bool:
        self.assertFalse(c.check_copyright(self.j1.name, SAMPLE_MSG))
        self.assertFalse(c.check_copyright(self.k1.name, SAMPLE_MSG))


    def test_check_folder(self):
        ## check_folder(folder: str, extension: str, rawtext: list)->list:
        l = list()
        for e in EXT:
            l += c.check_folder(self.folder, e, SAMPLE_MSG)
        self.assertTrue(self.j1.name in l)
        self.assertTrue(self.k1.name in l)


    def test_comment_block_factory(self):
        ## comment_block_factory(rawtext: list)->str:
        self.assertEqual(c.comment_block_factory(SAMPLE_MSG), SAMPLE_MSG_CMTBLK)


    def test_update_files(self):
        ## update_files(files: list, rawtext: list):
        c.update_files([self.j1.name, self.k1.name], SAMPLE_MSG)
        self.assertTrue(c.check_copyright(self.j1.name, SAMPLE_MSG))
        self.assertTrue(c.check_copyright(self.k1.name, SAMPLE_MSG))


if __name__ == '__main__':

    unittest.main()
