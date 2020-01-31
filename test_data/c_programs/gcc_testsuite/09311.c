



void foo (void);

int test1 (int a)




{
  if ((a >> 3) & 134217728)
    foo ();
}


int test2 (unsigned int b)



{
  if ((b >> 3) & 134217728)
    foo ();
}
