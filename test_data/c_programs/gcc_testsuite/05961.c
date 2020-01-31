





void foo (int i_width, char* dst, char* src1, char* src2)
{
      int x;
       for( x = 0; x < i_width; x++ )
       {
           *((char*)dst) = ( *((char*)src1) + *((char*)src2) + 1 ) >> 1;
    dst+=sizeof(char*);
    src1+=sizeof(char*);
    src2+=sizeof(char*);
       }
}
