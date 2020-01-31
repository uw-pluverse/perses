




void abort (void);
int b,c,d,e,f;
int *a[5]={&b,&c,&c,&e};
void other_ltrans (void);
int
main()
{
  other_ltrans ();
  if (*(a[1])!=11)
    abort ();
  return 0;
}
