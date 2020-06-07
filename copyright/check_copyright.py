#!/usr/bin/env python3

import os
import argparse
from typing import List

SRC_FOLDER = '../src'

with open("copyright.txt") as file:
    BUF_CPRT = file.readlines()

def get_files(directory: str, extension: str) -> List[str]:
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


def check_copyright(sourcefile: str, rawtext: list) -> bool:
    """
    This function takes a source file name and
    outputs true if the file has copyright infomation
    """
    buf_cprt = ''.join(rawtext)
    buf_cprt = ''.join(buf_cprt.split())

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

    if buf_srcfile.find(buf_cprt) == -1:
        return False
    return True


def check_folder(folder: str, extension: str, rawtext: list)->list:
    """
    Return a list of files missing copyright
    """
    missing_list = list()
    files = get_files(folder, extension)

    for file in files:
        if not check_copyright(file, rawtext):
            missing_list.append(file)
    return missing_list


def comment_block_factory(rawtext: list)->str:
    """ Return a formatted comment block for appending """
    buf_cprt = rawtext[:]

    for i, val in enumerate(buf_cprt):
        buf_cprt[i] = " * " + val
    buf_cprt.insert(0, "/*\n")
    buf_cprt.append(" */\n")

    return ''.join(buf_cprt)


def update_files(files: list, rawtext: list):
    """ Updates give files with copyright info """
    cmtblk = comment_block_factory(rawtext)
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

    extensions = ['java', 'kt']
    missing_list = list()
    for ext in extensions:
        missing_list += check_folder(SRC_FOLDER, ext, BUF_CPRT)

    if not UPDATE_FLAG and missing_list != []:
        raise Exception('\n'.join(missing_list))

    elif UPDATE_FLAG:
        print('Updating files ...')
        update_files(missing_list, BUF_CPRT)
        print('All files now have copyright info')

    else:
        print('Check complete.\nAll files OK')
