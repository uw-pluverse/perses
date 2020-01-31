extern struct { unsigned char a, b; } g0[];
void *g1[] = {g0 + -1, g0 + -23 };
void *g2[] = {g0 - 1, g0 - 23 };
