





void foo (int i_width, char* dst, char* src1, char* src2)
{
      int x;
       for( x = 0; x < i_width; x++ )
       {
           dst[x] = ( src1[x] + src2[x] + 1 ) >> 1;
       }
}
