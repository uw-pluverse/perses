


typedef struct {
  int code;
} *rtx;

static inline void *zero ()
{
  return 0;
}
static inline int three ()
{
  return 3;
}

int
can_combine_p (rtx insn, rtx elt)
{
  rtx set;

  set = zero ();
  if (insn->code == three ())
    set = insn;
  else
    {
      set = elt;
      if (set == zero ())
 return 0;
    }

  if (set == zero ())
    return 1;

  return 0;
}
