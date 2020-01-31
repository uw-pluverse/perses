



struct S {
    int a;
    union {
        int b;
        int c;
    };
} __attribute__((designated_init));

struct S s1 = { .a = 0, .b = 0 };
struct S s2 = { 0, 0 };
struct S s3 = { .a = 5, 0 };
