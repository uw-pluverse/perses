


void bar (int);

void
foo ()
{
 {
    bar (1);
 {
      bar (2);
    }
  }
 {
 bar (3);
 {
      bar (4);
      bar (5);
    }
  }
 {
    {
      bar (6);
      bar (7);
    }
 bar (8);
  }
 {
 {
      bar (9);
    }
 bar (10);
 bar (11);
  }
 {
  }
 {
    bar (12);
    bar (13);
 bar (14);
  }
 {
 }
 {
    bar (15);
 bar (16);
    bar (17);
  }
 {
    bar (18);
 }
}
