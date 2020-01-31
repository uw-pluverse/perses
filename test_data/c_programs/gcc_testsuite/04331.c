typedef long unsigned int size_t;
typedef unsigned long int reg_syntax_t;
struct re_pattern_buffer
{
  unsigned char *buffer;
};
typedef enum
{
  jump,
  jump_n,
} re_opcode_t;
static int
foo (bufp)
     struct re_pattern_buffer *bufp;
{
  int mcnt;
  unsigned char *p = bufp->buffer;
  switch (((re_opcode_t) * p++))
    {
    unconditional_jump:
      ;


    case jump:
      do
        {
          (mcnt) = *(p) & 0377;
        }
      while (0);
      (p) += 2;
      p += mcnt;
    case jump_n:
      (mcnt) = *(p + 2) & 0377;
      if (mcnt)
        goto unconditional_jump;
    }
}
