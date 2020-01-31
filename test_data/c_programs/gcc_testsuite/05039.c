


volatile int count;
void bar(int);
void foo()
{
 bar(count++);
}
