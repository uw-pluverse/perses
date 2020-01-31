struct s1 { struct s2 *A; };
struct s2 { struct s1 *B; };
struct s1 a;
struct s2 b;
