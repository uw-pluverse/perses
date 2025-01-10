typedef struct { struct { struct { struct { struct { struct { struct { struct { struct {
long x [ 6 ] ;
} x [ 6 ] ;
} x [ 6 ] ;
} x [ 6 ] ;
} x [ 6 ] ;
} x [ 6 ] ;
} x [ 6 ] ;
} x [ 6 ] ;
} x [ 6 ] ;
} myjmp_buf ;
typedef struct {
myjmp_buf regs ;
} my_stack ;
void switch_to_stack ( my_stack * stack ) {
asm (
"\n"
: "+r" ( stack -> regs )
) ;
}
