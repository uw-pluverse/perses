


int jj;

__attribute__((transaction_safe))
static void poof ()
{
  if (jj)
    return;
   poof();
}

__attribute__((transaction_safe))
void TMlist_free ()
{
    poof();
}
