# /usr/bin/env python3

import argparse
import os
import check_copyright

# noinspection PyInterpreter
if __name__ == '__main__':

    parser = argparse.ArgumentParser(prog='check_copyright', usage='%(prog)s [option]',
                                     description='check/update copyright information'
                                     )
    parser.add_argument('-u', '--update-copyright',
                        action='store_true',
                        default=False,
                        help='update copyright (default: check copyright only)')
    parser.add_argument('copyright',
                        help='copyright filepath')
    parser.add_argument('dirs', nargs='*')
    flags = parser.parse_args()

    with open(flags.copyright) as file:
        copyright_text = file.readlines()
    copyright_checker = check_copyright.CopyrightChecker(copyright_text)

    extensions = ['java', 'kt', "proto"]
    file_list = list()
    print('Checking files in folders:\n%s\n' % '\n'.join(flags.dirs))
    for folder in flags.dirs:
        assert os.path.exists(folder), 'folder=%s, cwd=%s' % (folder, os.getcwd())
        for extension in extensions:
            file_list += copyright_checker.locate_files(folder, extension)

    if flags.update_copyright:
        copyright_checker.update_files(file_list)
        print("%d files have been updated!" % len(file_list))
    else:
        missing_list = copyright_checker.check_files(file_list)
        if missing_list:
            raise Exception(
                'Following %d files require copyright update:\n%s' %
                (len(missing_list), '\n'.join(missing_list)))
        else:
            print("All files are up to date")
