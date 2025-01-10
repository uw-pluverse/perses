




double sin (double);
void
fn (int *p)
{
  int **a[] = { &p,
               (void *) 0, &p };
  double d[] = { sin (1.0),
                 8.8, sin (1.0), 2.6 };
}
