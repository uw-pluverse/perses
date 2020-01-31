





struct optab { unsigned code; };
struct optab optab_table[1];

void
init_optab (struct optab *op)
{
  op->code = 0xdead;
}

void
set_conv_libfunc (void)
{
  init_optab (&optab_table[0]);
}

int main() { return 0; }
