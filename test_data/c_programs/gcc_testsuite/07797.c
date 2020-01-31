



struct lineno_cache_entry
{
  unsigned long size;
};
int
_bfd_link_section_stabs (struct lineno_cache_entry * stabsec)
{
  unsigned long count;
  unsigned char *sym;
  unsigned char *symend;
  unsigned long skip;
  count = stabsec->size / 12;
  for (; sym < symend; sym += 1);
  stabsec->size = (count - skip) * 12;
}
