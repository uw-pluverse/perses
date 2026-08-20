# /usr/bin/env python3

import argparse
import os
# Make sure we import the check with the full path. 
# See #762 in the private issue tracker.
from copyright.pluverse_check_copyright import CopyrightChecker

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
    parser.add_argument('paths', nargs='*',
                        help='directories to scan recursively and/or individual '
                             'files to check')
    flags = parser.parse_args()

    with open(flags.copyright) as file:
        copyright_text = file.readlines()
    copyright_checker = CopyrightChecker(copyright_text)

    extensions = ['java', 'kt', "proto"]
    suffixes = tuple('.' + extension for extension in extensions)
    file_list = list()
    print('Checking copyright for %d path(s):\n%s\n'
          % (len(flags.paths), '\n'.join(flags.paths)))
    for path in flags.paths:
        assert os.path.exists(path), 'path=%s, cwd=%s' % (path, os.getcwd())
        if os.path.isdir(path):
            for extension in extensions:
                file_list += copyright_checker.locate_files(path, extension)
        elif path.endswith(suffixes):
            # An individual file: include it unless its directory opts out via a
            # 'copyright_checking_excluded' marker, mirroring locate_files().
            sibling_dir = os.path.dirname(path) or '.'
            if 'copyright_checking_excluded' not in os.listdir(sibling_dir):
                file_list.append(path)

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
