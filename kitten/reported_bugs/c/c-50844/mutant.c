static unsigned _t = 0 ;
void __attribute__ ( ( interrupt ) )
foo ( struct ucontext * oucp )
{
_t ++ ;
}
