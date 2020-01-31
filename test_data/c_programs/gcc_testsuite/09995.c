




long unsigned int cnfs_mapcntl(long pagesize)
{
     return ~(long unsigned int)(pagesize - 1);
}
