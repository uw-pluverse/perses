




void
f (void)
{
  const int m = 1;
  ((void)(sizeof(struct { int i:!!m; })));
}
