


int t;
extern void link_error(void);
int main (void)
{
      struct { unsigned int a : 7; } s;
      s.a = t;
      if (s.a >> 8)
          link_error ();
      if (s.a >> 9)
          link_error ();
}
