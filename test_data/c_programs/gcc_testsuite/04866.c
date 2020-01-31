


int v = 6;
void bar (int);
void bar2 (int, long *, long *);
int baz (void);

void
foo (int a, int b, long c, long d)
{



 bar (0);
 bar (1);
 bar (2);
 bar (3);
 bar (4);
 bar (5);
 bar (6);
 {
    {
      bar (7);
    }
  }
 bar (8);
 bar (9);
 bar (10);
 bar (11);
 bar (12);
 bar (13);
 {
 bar2 (14, &c, &d);



 bar (15);
  }


 bar (16);
 bar (17);


 bar (18);
}
