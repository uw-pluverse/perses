




int test(void)
{
  int __seg_fs *f = (int __seg_fs *)16;
  int __seg_gs *g = (int __seg_gs *)16;
  return *f + *g;
}
