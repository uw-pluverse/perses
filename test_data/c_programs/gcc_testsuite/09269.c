



struct
{
  int i;
} *s;

extern void bar (void);

void foo ()
{
  !s ? s->i++ : bar ();
}
