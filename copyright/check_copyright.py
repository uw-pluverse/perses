#!/usr/bin/env python3

import unittest
import os

SRC_FOLDER = '../src'

"""Get copyright info"""
with open("copyright.txt") as file:
    BUF_CPRT = file.read()
BUF_CPRT = ''.join(BUF_CPRT.split())


class TestCopyright(unittest.TestCase):
    """
    Test if copyright info exist in files with specified extensions
    """

    def test_copyright_java(self):
        """ Test Java files """
        javafiles = get_files(SRC_FOLDER, "java")
        self.assertTrue(len(javafiles) > 0)
        for javaf in javafiles:
            self.assertTrue(check_copyright(javaf), msg=javaf)

    def test_copyright_kt(self):
        """ Test Kotlin files """
        ktfiles = get_files(SRC_FOLDER, "kt")
        for ktf in ktfiles:
            self.assertTrue(check_copyright(ktf), msg=ktf)


def get_files(directory: str, extension: str) -> list:
    """
    This function takes a directory path and desired extension
    then returns a list of path+files with specified extension
    """
    file_list = list()

    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith('.' + extension):
                file_list.append(os.path.join(root, file))
    return file_list


def check_copyright(sourcefile: str) -> bool:
    """
    This function takes a source file name and
    outputs true if the file has copyright infomation
    """
    with open(sourcefile) as file:
        buf_srcfile = file.readline().rstrip('\n')
        if buf_srcfile.find("/*") == -1:
            return False
        cmtblk = list()
        buf_srcfile = file.readline()
        while buf_srcfile.find("*/") == -1:
            cmtblk.append(buf_srcfile.strip(" *"))

            buf_srcfile = file.readline()

    buf_srcfile = ''.join(cmtblk)
    buf_srcfile = ''.join(buf_srcfile.split())
    if buf_srcfile.find(BUF_CPRT) == -1:
        return False
    return True

if __name__ == '__main__':
    unittest.main()