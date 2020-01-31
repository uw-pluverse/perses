


extern __attribute__((transaction_safe)) void TMreleaseNode ();

int global;

__attribute__((transaction_safe))
void
TMrbtree_insert ()
{
  if (global)
    TMreleaseNode();
}
