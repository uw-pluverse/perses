struct reload
{
  int first_member;
  int out;
  int final_member;
};

int n_reloads;
struct reload rld[10];

static int
combine_reloads ()
{
  int i;
  int output_reload = -1;
  int secondary_out = -1;

  for (i = 0; i < n_reloads; i++)
    if (rld[i].out != 0)
      {
 if (output_reload >= 0)
   return output_reload;
 output_reload = i;
      }
  return output_reload;
}

int
main ()
{
  n_reloads = 4;
  rld[2].out = 2;
  if (combine_reloads () != 2)
    abort ();
  exit (0);
}
