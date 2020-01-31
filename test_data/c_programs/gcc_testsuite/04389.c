







struct _obstack_chunk
{
  char *limit;
  struct _obstack_chunk *prev;
  char contents[4];
};

struct obstack
{
  long chunk_size;
  struct _obstack_chunk *chunk;
  char *object_base;
  char *next_free;
  char *chunk_limit;
  long int temp;
  int alignment_mask;
  struct _obstack_chunk *(*chunkfun) (void *, long);
  void (*freefun) (void *, struct _obstack_chunk *);
  void *extra_arg;
  unsigned use_extra_arg:1;
  unsigned maybe_empty_object:1;
  unsigned alloc_failed:1;
};

extern void _obstack_newchunk (struct obstack *, int);

struct fooalign {char x; double d;};


union fooround {long x; double d;};
void
_obstack_newchunk (h, length)
     struct obstack *h;
     int length;
{
  register struct _obstack_chunk *old_chunk = h->chunk;
  register struct _obstack_chunk *new_chunk;
  register long new_size;
  register long obj_size = h->next_free - h->object_base;
  register long i;
  long already;

  new_size = (obj_size + length) + (obj_size >> 3) + 100;
  if (new_size < h->chunk_size)
    new_size = h->chunk_size;

  new_chunk = (((h) -> use_extra_arg) ? (*(h)->chunkfun) ((h)->extra_arg, (new_size)) : (*(struct _obstack_chunk *(*) (long)) (h)->chunkfun) ((new_size)));
  h->chunk = new_chunk;
  new_chunk->prev = old_chunk;
  new_chunk->limit = h->chunk_limit = (char *) new_chunk + new_size;

  if (h->alignment_mask + 1 >= ((long int) ((char *) &((struct fooalign *) 0)->d - (char *) 0)))
    {
      for (i = obj_size / sizeof (int) - 1;
    i >= 0; i--)
 ((int *)new_chunk->contents)[i]
   = ((int *)h->object_base)[i];
      already = obj_size / sizeof (int) * sizeof (int);
    }
  else
    already = 0;
  for (i = already; i < obj_size; i++)
    new_chunk->contents[i] = h->object_base[i];

  if (h->object_base == old_chunk->contents && ! h->maybe_empty_object)
    {
      new_chunk->prev = old_chunk->prev;
      do { if ((h) -> use_extra_arg) (*(h)->freefun) ((h)->extra_arg, (old_chunk)); else (*(void (*) (void *)) (h)->freefun) ((old_chunk)); } while (0);
    }

  h->object_base = new_chunk->contents;
  h->next_free = h->object_base + obj_size;
  h->maybe_empty_object = 0;
}
