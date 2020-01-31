


extern int v1;
extern int v2;
void g (void);

void
f ()
{
  if (v2 || v1)
    (!(v1)) ? (void) 0 : (void) g ();
}
