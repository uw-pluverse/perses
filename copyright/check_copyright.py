def check_copyright (sourcefile):
    """
    :type sourcefile: String
    :rtype: Boolean

    This function takes a source file name and
    outputs true if the file has copyright infomation
    """
    
    
    """Get copyright info"""
    with open("copyright.txt") as file:
        buf_cprt = file.read()
        

    """Extract comment block contents"""
    with open(sourcefile) as file:
        buf_srcfile = file.readline()
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
