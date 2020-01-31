struct S0 { int i; };

struct S1 { int i; struct S0 s; } __attribute__((scalar_storage_order("big-endian")));;

struct S2 { int a[4]; struct S0 s; } __attribute__((scalar_storage_order("big-endian")));;

struct S0 s0;
struct S1 s1;
struct S2 s2;
