



extern unsigned short mode_size[];

int
oof (int mode)
{
  return (64 < mode_size[mode] ? 64 : mode_size[mode]);
}
