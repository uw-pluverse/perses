




void bar (int, int);

void
foo (void)
{
 for (int i = 0; i < 16; ++i)
    for (int j = 0; j < 16; ++j)
      bar (i, j);
}
