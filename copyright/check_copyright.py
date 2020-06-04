#!/usr/bin/env python3

import os
import argparse


SRC_FOLDER = '../src'


def get_update_flag()->bool:
    """
    Return true if copyright update option is required
    """
    parser = argparse.ArgumentParser(prog='check_copyright', usage='%(prog)s [option]',
                                     description='check/update copyright information'
                                     )
    parser.add_argument('-u', '--update-copyright',
                        action='store_true',
                        default=False,
                        help='update copyright (default: check copyright only)')
    flag = parser.parse_args()
    return flag.update_copyright


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
    with open("copyright.txt") as file:
        buf_cprt = file.read()
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


def check_files(folder: str, extension: str)->list:
    """
    Return a list of files missing copyright
    """
    missing_list = list()
    javafiles = get_files(folder, extension)

    for javaf in javafiles:
        if not check_copyright(javaf):
            missing_list.append(javaf)
    return missing_list


def comment_block_factory()->str:
    """ Return a formatted comment block for appending """
    with open("copyright.txt") as file:
        buf_cprt = file.readlines()
    for i, val in enumerate(buf_cprt):
        buf_cprt[i] = " * " + val
    buf_cprt.insert(0, "/*\n")
    buf_cprt.append(" */\n")


    return ''.join(buf_cprt)


def update_files(files: list):
    """ Updates give files with copyright info """
    cmtblk = comment_block_factory()
    for file in files:
        with open(file, 'r+') as f:
            content = f.read()
            f.seek(0, 0)
            f.write(cmtblk+content)


if __name__ == '__main__':

    UPDATE_FLAG = get_update_flag()

    java_missing_list = check_files(SRC_FOLDER, 'java')
    kt_missing_list = check_files(SRC_FOLDER, 'kt')
    print('Checking complete\n', '\n'.join(java_missing_list))

    if UPDATE_FLAG:
        print('Updating files above')
        update_files(java_missing_list)
        update_files(kt_missing_list)
        print('All files now have copyright info')

