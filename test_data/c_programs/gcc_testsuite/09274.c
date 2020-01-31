


typedef unsigned char __u8;
typedef unsigned short __u16;

static inline unsigned char *
foo(unsigned char * to, const unsigned char * from, int n)
{
  switch ( n )
    {
    case 3:
      *to = *from;
      break;
    case 5:
      to[4] = from [4];
      break;
    }
  return to;
}

struct {
  int size_of_select;
  unsigned char pcr_select[4];
} sel;

int bar(void)
{
  static unsigned char buf[64];

  sel.size_of_select = 3;
  foo(buf, sel.pcr_select, sel.size_of_select);

  return 1;
}


static inline unsigned char *
foo2(unsigned char * to, const unsigned char * from, int n)
{
  switch ( n )
    {
    case 3:
      *to = *from;
      break;
    case 5:
      to[4] = from [4];
      break;
    }
  return to;
}

int baz(void)
{
  static unsigned char buf[64];

  sel.size_of_select = 5;
  foo2(buf, sel.pcr_select, sel.size_of_select);

  return 1;
}
