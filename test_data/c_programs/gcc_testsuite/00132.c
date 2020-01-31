




struct x {
  char x;
  char y;
};

struct x __attribute__ ((eightbit_data)) foo;

int bar ()
{
 if ((foo.y & 0x80) != 0)
   oof ();
}

int com ()
{
 if ((foo.x & 0x80) != 0)
   oof ();
}
