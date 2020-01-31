


extern void abort (void);
struct rtx_def;
typedef struct rtx_def *rtx;
struct rtx_def
{
  int code;
};
void
foo (reg)
     rtx reg;
{
  reg->code = 42;
  if (reg->code != 42)
    abort ();
}
