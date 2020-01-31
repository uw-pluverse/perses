


__attribute__ ((vector_size (64))) unsigned char v1, v2, v3;
void
vadd (void)
{
  v1 = v2 + v3;
}
void
test_add (void)
{
  vadd ();
}
void
vsub (void)
{
  v1 = v2 - v3;
}
