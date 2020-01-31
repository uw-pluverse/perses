





typedef unsigned char uint8;
typedef unsigned int uint32;

uint32 marker = 0;
uint8 *buff = 0;
uint32 bsize = 0;

extern int foo (void);

uint32
bar (void)
{
  int len, d;

  for (;;)
    {
      if (foo () == 0)
        return (0);

      switch (marker)
        {
        case 0xfe:
          {
            len |= (*buff++);
            bsize -= 2;

            while (len > 0)
              {
                d = *buff++;
                len--;
              }
          }
          break;
        default:
          break;
        }
    }
}
