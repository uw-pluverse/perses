




struct S { int n, u[2]; };
const signed char z[] = {
  [0] = 0x100,
  [2] = 0x101,
};
int A[] = {
            0, 0x80000000,
            0xA, 0x80000000,
            0xA, 0xA, 0x80000000
          };
int *p = (int []) { 0x80000000 };
union { int k; } u = { .k = 0x80000000 };
typedef int H[];
void
foo (void)
{
  signed char a[][3] = { { 0x100,
                    1, 0x100 },
                  { '\0', 0x100, '\0' }
                };
  (const signed char []) { 0x100 };
  (const float []) { 1e0, 1e1, 1e100 };
  struct S s1 = { 0x80000000 };
  struct S s2 = { .n = 0x80000000 };
  struct S s3 = { .u[1] = 0x80000000 };
  H h = { 1, 2, 0x80000000 };
}
