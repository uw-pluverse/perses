extern void oof (void);
typedef struct simple_bitmap_def *sbitmap;
struct simple_bitmap_def
{
  unsigned char *popcount;
  unsigned int n_bits;
  unsigned long elms[1];
};
__inline__ void
SET_BIT (sbitmap map, unsigned int bitno)
{
  if (map->popcount)
    {
      unsigned char oldbit;
      oldbit =
 ((map)->elms[bitno / 64]);
      if (!oldbit)
 oof ();
    }
  map->elms[bitno / 64] |= 1;
}

void
fix_bb_placements (int indx1, int indx2, sbitmap in_queue)
{
  SET_BIT (in_queue, indx1);
  SET_BIT (in_queue, indx2);
}
