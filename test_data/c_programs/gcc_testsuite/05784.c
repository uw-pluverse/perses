




void link_error (void);

typedef struct teststruct
{
  double d;
  char f1;
} teststruct;


void
copystruct11 (teststruct *param)
{
  static teststruct local;
  param->f1 = 0;
  local = *param;
  if (local.f1 != 0)
    link_error ();
}
