




extern __thread int h_errno;
int *
__h_errno_location (void)
{
  return &h_errno;
}
