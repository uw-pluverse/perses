



int *a;
int b, c, d, e;
int sched_analyze(void) {
 for (; b; b++) {
   c = 0;
   for (; c < 32; c++)
     if (b & 1 << c)
       a[b + c] = d;
 }
 return 0;
}

void schedule_insns(void) { e = sched_analyze(); }
int main(void) { schedule_insns(); }
