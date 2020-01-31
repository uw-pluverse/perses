





char *f(char *x, int flag)
{
    char *ret = (char*)0;


    if( x > (char*)1 ) {
      if(x)
        return (char*)0;
    } else {
      if( flag & 1 )
        ret = (char*)1;
      flag |= 2;
    }
    return ret;
}
