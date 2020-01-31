SQLITE_PRIVATE int sqlite3PutVarint(unsigned char *p, u64 v){
  int i, j, n;
  u8 buf[10];
  if( v & (((u64)0xff000000)<<32) ){
    p[8] = v;
    v >>= 8;
    for(i=7; i>=0; i--){
      p[i] = (v & 0x7f) | 0x80;
      v >>= 7;
    }
    return 9;
  }
  n = 0;
  do{
    buf[n++] = (v & 0x7f) | 0x80;
    v >>= 7;
  }while( v!=0 );
  buf[0] &= 0x7f;
  assert( n<=9 );
  for(i=0, j=n-1; j>=0; j--, i++){
    p[i] = buf[j];
  }
  return n;
}
