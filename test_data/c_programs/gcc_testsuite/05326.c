

int a;
int
elantech_detect (void)
{
  return -38;
}
inline int
fsp_detect (void)
{
  return -38;
}
void
psmouse_extensions (void)
{
  int (*b)() = fsp_detect;
  a = b ();
}
