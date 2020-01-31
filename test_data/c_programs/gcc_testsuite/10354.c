




extern int foo(void);



const int x = ((__builtin_constant_p(1) ? __builtin_constant_p (0 && foo()) : 0) ? (0 && foo()) : -1);
