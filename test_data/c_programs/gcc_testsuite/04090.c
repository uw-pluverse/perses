int x;
struct gdt
{
unsigned a,b,c,d,e,f;
};
void f()
{
struct gdt gdt_table[2]=
{
    {
  0,
  ( (((unsigned)(&x))<<(24))&(-1<<(8)) ),
    },
};
}
