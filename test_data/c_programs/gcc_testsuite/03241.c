


typedef long unsigned int size_t;

extern void *memset(void *, int, size_t);

struct Baz;

void quux(struct Baz *context)
{
  memset(context, 0, 4);
}
