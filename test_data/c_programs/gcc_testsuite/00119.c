


volatile float a,b,c,d;

void foo()
{
     __asm__ __volatile__( "vcmpss $1,%1, %2,%3;" : "=x"(c) : "x"(a),"x"(b),"x"(d) );
}
