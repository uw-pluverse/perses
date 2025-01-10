



extern __seg_gs int *call_me (void);

int
read_seg_gs (void)
{
  return *call_me();
}
