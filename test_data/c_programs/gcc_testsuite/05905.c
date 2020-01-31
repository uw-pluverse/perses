


int bits;
unsigned int size;
int max_code;

void
test ()
{
 int code = 0;

 while (code < max_code)
   code |= ((unsigned int) (size >> (--bits)));

 while (bits < (unsigned int)25)
   bits += 8;
}
