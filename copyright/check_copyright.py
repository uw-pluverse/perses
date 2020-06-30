import os
from typing import List


class CopyrightChecker:
    """CopyrightChecker class serves two purposes:
    1. to check copyright for all files with specified extension.
    2. to update copyright for all files in specified folders

    Attributes:
       copyright_text: A list read from copyright.txt
    """

    def __init__(self, copyright_text):
        """Inits CopyrightChecker with a list version of copyright text"""
        self.copyright_text = copyright_text

    def locate_files(self, folder: str, extension: str) -> List[str]:
        """
        Return a list of files with a specific extension
        """
        file_list = list()
        for root, dirs, files in os.walk(folder):
            for file in files:
                if file.endswith('.' + extension):
                    file_list.append(os.path.join(root, file))
        return file_list

    def check_files(self, file_list: List[str]) -> List[str]:
        """
        Return a list of files missing copyright
        """
        missing_list = list()
        for file in file_list:
            if not self.check_copyright(file):
                missing_list.append(file)
        return missing_list

    def check_copyright(self, sourcefile: str) -> bool:
        """
        Return a True if the input file has copyright infomation
        """
        buf_copyright = ''.join(self.copyright_text)
        buf_copyright = ''.join(buf_copyright.split())

        with open(sourcefile) as file:
            buf_srcfile = file.readline().rstrip('\n')
            if buf_srcfile.find("/*") == -1:
                return False
            comment_block = list()
            buf_srcfile = file.readline()
            while buf_srcfile.find("*/") == -1:
                comment_block.append(buf_srcfile.strip(" *"))
                buf_srcfile = file.readline()

        buf_srcfile = ''.join(comment_block)
        buf_srcfile = ''.join(buf_srcfile.split())

        if buf_srcfile.find(buf_copyright) == -1:
            return False
        return True

    def update_files(self, file_list: List[str]):
        """ Updates given files with copyright info """
        buf_copyright = self.copyright_text[:]

        for i, val in enumerate(buf_copyright):
            if val == '\n':
                buf_copyright[i] = " *" + val
            else:
                buf_copyright[i] = " * " + val
        buf_copyright.insert(0, "/*\n")
        buf_copyright.append(" */\n")

        comment_block = ''.join(buf_copyright)

        for file in file_list:
            with open(file, 'r+') as target_file:
                content = target_file.read()
                if content.find('* Copyright') != -1:
                    start_index = content.find('*/\n') + 3
                    content = content[start_index:]
                target_file.seek(0, 0)
                target_file.write(comment_block + content)
