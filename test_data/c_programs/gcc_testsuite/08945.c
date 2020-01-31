






extern void bar(int *);

void foo (__attribute__((__mode__(QI))) int abc)
{

 int b[sizeof(abc) == 1 ? 1 : -1];
 bar (b);
}
