


enum E { A };

enum E v;
unsigned int *p = &v;

void foo(unsigned int);
void (*pfn)(enum E) = &foo;
