#!/usr/bin/env python3

import os
import argparse
from typing import List


SRC_FOLDER = '../src'


class Copyright:
    
    def __init__(self, copyright_text):
        self.buf_cprt = copyright_text


    def check_folder(self, folder: str, extension: str)->list:
        """
        Return a list of files missing copyright
        """
        file_list = list()
        for root, dirs, files in os.walk(folder):
            for file in files:
                if file.endswith('.' + extension):
                    file_list.append(os.path.join(root, file))

        missing_list = list()
        for file in file_list:
            if not self.check_copyright(file):
                missing_list.append(file)
        return missing_list


    def check_copyright(self, sourcefile: str) -> bool:
        """
        This function takes a source file name and
        outputs true if the file has copyright infomation
        """
        copyright_text = ''.join(self.buf_cprt)
        copyright_text = ''.join(copyright_text.split())

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

        if buf_srcfile.find(copyright_text) == -1:
            return False
        return True


    def update_files(self, files: list):
        """ Updates give files with copyright info """
##        print('Updating files ...')
        copyright_text = self.buf_cprt[:]

        for i, val in enumerate(copyright_text):
            copyright_text[i] = " * " + val
        copyright_text.insert(0, "/*\n")
        copyright_text.append(" */\n")

        cmtblk = ''.join(copyright_text)
        
        for file in files:
            with open(file, 'r+') as f:
                content = f.read()
                f.seek(0, 0)
                f.write(cmtblk+content)


if __name__ == '__main__':

    parser = argparse.ArgumentParser(prog='check_copyright', usage='%(prog)s [option]',
                                     description='check/update copyright information'
                                     )
    parser.add_argument('-u', '--update-copyright',
                        action='store_true',
                        default=False,
                        help='update copyright (default: check copyright only)')
    UPDATE_FLAG = parser.parse_args().update_copyright

    with open("copyright.txt") as file:
        copyright_text = file.readlines()
    copyright_checker = Copyright(copyright_text)

    extensions = ['java', 'kt']
    missing_list = list()
    
    for ext in extensions:
        missing_list += copyright_checker.check_folder(SRC_FOLDER, ext)

    if not UPDATE_FLAG and missing_list != []:
        raise Exception('\n'.join(missing_list))

    elif UPDATE_FLAG:
        copyright_checker.update_files(missing_list)
        print('All files now have copyright info')

    else:
        print('Check complete.\nAll files OK')
