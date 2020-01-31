





void foo (int i_width, char* dst, char* src1, char* src2)
{
      int x;
       for( x = 0; x < i_width; x++ )
       {
           *dst++ = ( *src1++ + *src2++ + 1 ) >> 1;
       }
}
