




typedef struct { int x[20]; void *y; } S;
S nrv_candidate (void);
void use_result (S);
void make_escape (S *);
S global_S;
void foo (void)
{
  S *result;
  S local_S;



  result = &global_S;
  *result = nrv_candidate ();
  use_result (*result);




  make_escape (&local_S);
  result = &local_S;
  *result = nrv_candidate ();
  use_result (*result);
}
