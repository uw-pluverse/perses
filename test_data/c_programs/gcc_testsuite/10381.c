






int foo (int);

int a, b, c;
_Bool d;

int
bar (void)
{
  if (a = b)
    foo (0);
  if ((a = b))
    foo (1);
  if (a = a)
    foo (2);
  if ((a = a))
    foo (3);
  if (b = c)
    foo (4);
  else
    foo (5);
  if ((b = c))
    foo (6);
  else
    foo (7);
  if (b = b)
    foo (8);
  else
    foo (9);
  if ((b = b))
    foo (10);
  else
    foo (11);
  while (c = b)
    foo (12);
  while ((c = b))
    foo (13);
  while (c = c)
    foo (14);
  while ((c = c))
    foo (15);
  do foo (16); while (a = b);
  do foo (17); while ((a = b));
  do foo (18); while (a = a);
  do foo (19); while ((a = a));
  for (;c = b;)
    foo (20);
  for (;(c = b);)
    foo (21);
  for (;c = c;)
    foo (22);
  for (;(c = c);)
    foo (23);
  d = a = b;
  foo (24);
  d = (a = b);
  foo (25);
  d = a = a;
  foo (26);
  d = (a = a);
  foo (27);
}
