


struct s { int a, b, c; };
struct s s1 = { 1, 2, 3 };
struct s s2 = { 1, 2 };
struct s s3[] = { { 1, 2 }, { 4, 5 } };
struct s s4[] = { 1, 2, 3, 4, 5 };
struct s s5[] = { 1, 2, 3, 4, 5, 6 };

struct s s6 = { .a = 1 };

struct s s7 = { 0 };
struct s s8 = { 1 };
