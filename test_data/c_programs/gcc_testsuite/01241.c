



extern char *__ctype_ptr__;

unsigned char * foo(unsigned char *ReadPtr)
{

 unsigned char c;

 while (!(((__ctype_ptr__+sizeof(""[*ReadPtr]))[(int)(*ReadPtr)])&04) == (!(0)))
  ReadPtr++;

 return ReadPtr;
}
