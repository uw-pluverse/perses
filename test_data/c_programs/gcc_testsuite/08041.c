

void byte_insert_op1 (unsigned char *loc, unsigned char *end, unsigned *pto)
{
  while (end != loc)
    *pto = *--end;
}
