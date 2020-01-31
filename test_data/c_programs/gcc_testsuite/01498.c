

void foo(int i)
{
    extern int j;

    if (i) {
         j = 10;
    }
    else {
          j = 20;
    }
}
