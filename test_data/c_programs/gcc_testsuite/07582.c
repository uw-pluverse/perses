

struct foo {
 int bar;
};

typedef struct foo* bar;
void f () __attribute__ ((__malloc__));
int g () __attribute__ ((__malloc__));
int* h () __attribute__ ((__malloc__));
void* i () __attribute__ ((__malloc__));

struct foo j () __attribute__ ((__malloc__));
struct foo* k () __attribute__ ((__malloc__));
bar l () __attribute__((malloc));
