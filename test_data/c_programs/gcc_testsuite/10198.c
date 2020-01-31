




int f (void);
void g (void);
int *p;

void
h (void)
{
  1 + f ();
  f () + f ();
  f () + f (), f ();
  (char) f ();
  g ();
  f ();
  (void) f ();
  *p++;
  ++*p;
  (*p ? f() : 0);
  ({ f(); });



  ({ f() + 1; });
  ({ f(); 0; });
  ({ f() + 1; 0; });
  1 + ({ f(); });
}
