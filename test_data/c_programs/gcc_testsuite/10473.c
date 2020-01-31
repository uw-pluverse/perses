




typedef struct { int x[20]; void *y; } S;
typedef struct { int a; S b; } T;
S nrv_candidate (void);
void use_result (S);
void make_escape (S *);
void foo (void)
{
  S result;
  T result_arr[10][5];

  make_escape (&result);
  make_escape (&(result_arr[3][4].b));


  result = nrv_candidate ();
  result_arr[3][4].b = nrv_candidate ();

  use_result (result);
  use_result (result_arr[3][4].b);
}
