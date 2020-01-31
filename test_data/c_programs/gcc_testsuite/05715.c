

extern void abort (void);
struct rtx_def;
typedef struct rtx_def *rtx;
enum rtx_code
{
  CALL_INSN,
  EXPR_LIST,
  NOTE,
  LAST = 256
};

struct rtx_def
{

  enum rtx_code code:16;
};

extern void blah (rtx *);

int
nonlocal_mentioned_p (x)
     rtx x;
{
  if (x->code == CALL_INSN)
    {
      rtx const _rtx = ((x));
      if (_rtx->code != CALL_INSN
   && _rtx->code != NOTE
   && _rtx->code != EXPR_LIST)
 abort ();
    }

  blah (&x);
}
