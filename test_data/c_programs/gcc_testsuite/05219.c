


typedef unsigned int cppchar_t;
void foo (void);
cppchar_t oof (void);
cppchar_t
cpp_parse_escape (pstr, limit, wide)
     const unsigned char **pstr;
     const unsigned char *limit;
     int wide;
{
  cppchar_t i = 0;
  int overflow = 0;
  cppchar_t mask = ~0;

   while (*pstr < limit)
     {
       overflow |= i ^ (i << 4 >> 4);
       i = oof ();
     }
   if (overflow | (i != (i & mask)))
     foo();
}
