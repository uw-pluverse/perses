# /usr/bin/env python3

import argparse

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
    parser.add_argument('dirs', nargs='*')
    flags = parser.parse_args()

    with open("copyright/copyright.txt") as file:
        copyright_text = file.readlines()
    copyright_checker = check_copyright.CopyrightChecker(copyright_text)

    extensions = ['java', 'kt']
    missing_list = list()
    print('Checking files in folders %s' % flags.dirs)
    for folder in flags.dirs:
        for ext in extensions:
            missing_list += copyright_checker.check_folder(folder, ext)

    if not flags.update_copyright and missing_list != []:
        raise Exception('The following files do not have up-to-date copyright.'
                        '\n'.join(missing_list))

    if flags.update_copyright and missing_list != []:
        copyright_checker.update_files(missing_list)
        print('All files now have copyright info')

    else:
        print('Check complete.\nAll files OK')
