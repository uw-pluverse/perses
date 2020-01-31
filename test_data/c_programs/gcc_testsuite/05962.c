







void foo (int i_width, char* dst, char* src1, char* src2)
{
      char* dstn= dst + i_width;
       for( ; dst < dstn; )
       {
           *dst++ = ( *src1++ + *src2++ + 1 ) >> 1;
       }
}
