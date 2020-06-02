import unittest
import os

src_folder = "//src"

class test_copyright (unittest.TestCase):

    def testcopyright_java(self):
        javafiles = getFiles(src_folder, "java")
        for javaf in javafiles:
            self.assertTrue(check_copyright(javaf))

    def testcopyright_kt(self):
        ktfiles = getFiles(src_folder, "kt")

        for ktf in ktfiles:
            if check_copyright(ktf) != True:
                print(ktf)
            self.assertTrue(check_copyright(ktf))


def getFiles (directory: str, extension: str)->list:
    """
    This function takes a directory path and desired extension
    then returns a list of path+files with a specified extension 
    """
    Filelist = list()
    for root, dirs, files in os.walk(directory):
        for f in files:
            if f.endswith('.'+extension):
                Filelist.append(os.path.join(root,f))
    return Filelist


def check_copyright (sourcefile: str) -> bool:
    """
    This function takes a source file name and
    outputs true if the file has copyright infomation
    """
    
    
    """Get copyright info"""
    with open("copyright.txt") as file:
        buf_cprt = file.read()
        
    """Extract comment block contents"""
    with open(sourcefile) as file:
        buf_srcfile = file.readline().rstrip('\n')
        if buf_srcfile.find("/*") == -1:
            return False
        cmtblk=[]
        buf_srcfile = file.readline()
        while buf_srcfile.find("*/") == -1:
            cmtblk.append(buf_srcfile.strip(" *"))
            buf_srcfile = file.readline()

    """"Check - Compare"""
    buf_srcfile = ''.join(cmtblk)
    if buf_srcfile.find(buf_cprt) == -1:
        return False
    return True
