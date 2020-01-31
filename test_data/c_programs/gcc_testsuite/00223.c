struct list
{
  struct list *next;
  int element;
};

struct list *gr;

int foo;

extern void t (int, int, int*);

void
f (struct list **ptr)
{
  if (gr)
    *ptr = gr->next;
  t (1, foo, &gr->element);
}
