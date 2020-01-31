


extern void callee (void);
extern void caller (void (*func) (void));

typedef void (*func_t) (void);
func_t func;

int
main ()
{


  func = callee;
  caller (callee);
  func ();

  return 0;
}
