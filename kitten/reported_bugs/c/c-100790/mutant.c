int
__builtin_clz ( int x ) { return x ? __builtin_clz ( x ) : 32 ;
}
int
bar ( unsigned long long x )
{
return x ? __builtin_clzll ( x ) : 64 ;
}
