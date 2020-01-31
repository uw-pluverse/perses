extern void abort (void);

struct operation {
    short op;
    char rprio;
    char flags;
    char unsignedp;
    long value;
};

extern struct operation cpp_lex (void);

void
cpp_parse_expr (void)
{
  int rprio;
  struct operation op;

  for (;;)
    {
      op = cpp_lex ();

      switch (op.op)
 {
 case 0:
   break;
 case 1:
   return;
 case 2:
   rprio = 1;
   break;
 default:
   return;
 }

      if (op.op == 0)
 return;

      if (rprio != 1)
 abort();
    }
}
