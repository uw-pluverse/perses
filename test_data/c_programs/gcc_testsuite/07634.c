



struct S
{
  int i;
};

typedef struct S __attribute__((scalar_storage_order("big-endian"))) S1;

typedef struct S __attribute__((scalar_storage_order("little-endian"))) S2;

typedef struct S __attribute__((scalar_storage_order("other"))) S3;

void incompatible_assign (struct S *s, S1 *s1, S2 *s2)
{
  *s = *s1, *s = *s2;
  *s1 = *s2;
}
