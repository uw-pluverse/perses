

int v;

void
foo (void)
{
  int x = 0, y = 0;
 {
    int z;
 {
 x = 6;
    }
 z = x;
 y += z;
  }
 {
    int z;
 {
 v = 6;
    }
 z = v;
 y += z;
  }
 {
    int z;
 {
 x = 6;
    }
 z = x;
 y += z;
  }
  x = 0;
 {
 {
 x = 6;
    }
 y += x;
  }
 {
    x = 7;
  }
 {
 v = 6;
  }
}
