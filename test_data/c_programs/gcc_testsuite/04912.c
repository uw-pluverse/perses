



void
f1 (int ***x)
{
  int i, j, k;
 for (i = 0; i < 10; ++i)
    {
 for (j = 0; j < 10; ++j)
   {
 for (k = 0; k < 10; ++k)
  x[i][j][k] = k;
   }
    }
}

void
f2 (int ***x)
{
  int i, j, k;
 for (i = 0; i < 10; ++i)
    {
 for (j = 0; j < 10; ++j)
   {
 for (k = 0; k < 10; ++k)
  x[i][j][k] = k;
   }
    }
}

void
f3 (int ***x)
{
  int i, j, k;
 for (i = 0; i < 10; ++i)
    {
 for (j = 0; j < 10; ++j)
   {
 for (k = 0; k < 10; ++k)
  x[i][j][k] = k;
   }
    }
}
