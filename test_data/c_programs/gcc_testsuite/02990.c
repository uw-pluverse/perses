struct rtx_def
{
  int code;
};

main()
{
  int tmp[2];
  struct rtx_def *r, s;
  int *p, *q;





  r = &s;
  r->code = 39;



  p = tmp;
  q = p + 1;
  *q = 0;
  tmp[1] = 39;
  if (*q != 39)
    abort ();
  exit (0);
}
