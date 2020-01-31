





extern void abort (void);
int Table[534];

void
pre_init_tokenizer ()
{
  int i;

  for (i = 0; i < 534; i++)
    {
      Table[i] = i;
      if (i < 64)
 Table[i] = 64;
      else
 {
   if (i < 77)
     Table[i] = 77;
   else
     {
       if (i < 89)
  Table[i] = 89;
     }
 }
    }
}

void
check ()
{
  int i;

  for (i = 0; i < 64; i++)
    if (Table[i] != 64)
      abort ();
  for (i = 64; i < 77; i++)
    if (Table[i] != 77)
      abort ();
  for (i = 77; i < 89; i++)
    if (Table[i] != 89)
      abort ();
  for (i = 89; i < 534; i++)
    if (Table[i] != i)
      abort ();
}

int
main ()
{
  int i;

  pre_init_tokenizer ();




  check ();
  return 0;
}
