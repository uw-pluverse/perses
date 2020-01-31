


int sys_msgctl (void)
{
  struct { int mode; } setbuf;
  return setbuf.mode;
}
