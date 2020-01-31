typedef union _gc_head {
  struct {
    union _gc_head *gc_next;
    union _gc_head *gc_prev;
    long gc_refs;
  } gc;
  int dummy __attribute__((aligned(16)));
} PyGC_Head;
struct gc_generation {
  PyGC_Head head;
  int threshold;
  int count;
};
struct gc_generation generations[3] = {
        {{{(&generations[0].head), (&generations[0].head), 0}}, 700, 0},
        {{{(&generations[1].head), (&generations[1].head), 0}}, 10, 0},
        {{{(&generations[2].head), (&generations[2].head), 0}}, 10, 0},
};
