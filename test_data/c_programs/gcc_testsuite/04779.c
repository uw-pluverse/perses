

extern



void *memcpy (void *, const void *, long unsigned int);

struct S{
  long d0, d1, d2, d3, d4, d5, d6;
};

struct S s[6];

int f(struct S *p)
{
  memcpy(p, &s[2], sizeof(*p));
  memcpy(p, &s[1], sizeof(*p));
}
