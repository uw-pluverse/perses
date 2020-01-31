






int a[400];


void foo (int i_width, char* dst, char* src1, char* src2)
{
      char* dstn= dst + i_width;
      char* dst0 = dst;
      unsigned long long i = 0;
       for( ; dst <= dstn; )
       {
           dst0[i] = ( src1[i] + src2[i] + 1 +a[i]) >> 1;
           dst++;
    i += 16;
       }
}
