



void * restrict const a[2];
void * restrict const (*p2)[2];

void foo(void) {
   p2 = &a;
}

void * restrict volatile b[2];
void * restrict volatile (*q2)[2];

void bar(void) {
   q2 = &b;
}
