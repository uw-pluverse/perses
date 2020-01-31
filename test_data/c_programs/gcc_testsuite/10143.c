



typedef int vvv __attribute__((designated_init));

union U {
  int a;
  double b;
} __attribute__((designated_init));

enum E { ONE, TWO } __attribute__((designated_init));

struct Pok {
  int x;
  int y;
};

struct Des {
  int x;
  int y;
} __attribute__ ((designated_init));

struct Des d1 = { 5, 5 };
struct Des d2 = { .x = 5, .y = 5 };
struct Des d3 = { .x = 5, 5 };

struct Des fd1 (void)
{
  return (struct Des) { 5, 5 };
}

struct Des fd2 (void)
{
  return (struct Des) { .x = 5, .y = 5 };
}

struct Des fd3 (void)
{
  return (struct Des) { .x = 5, 5 };
}

struct Wrap {
  struct Pok p;
  struct Des d;
} __attribute__ ((designated_init));

struct Wrap w1 = { { 0, 1 }, { 2, 3} };
struct Wrap w2 = { .p = { 0, 1 }, { 2, 3} };
struct Wrap w3 = { .p = { 0, 1 }, .d = { 2, 3} };
struct Wrap w4 = { { 0, 1 }, .d = { 2, 3} };
struct Wrap w5 = { .p = { 0, 1 }, .d = { .x = 2, .y = 3} };

struct Wrap w6 = { { 0, 1 }, .d.x = 2, .d.y = 3 };
struct Wrap w7 = { .p = { 0, 1 }, .d.x = 2, .d.y = 3 };
struct Wrap w8 = { .p = { 0, 1 }, .d = { 2, 0 }, .d.y = 3 };
struct Wrap w9 = { .p = { 0, 1 }, .d = { .x = 2 }, .d.y = 3 };

struct Wrap fw1 (void)
{
  return (struct Wrap) { { 0, 1 }, { 2, 3} };
};

struct Wrap fw2 (void)
{
  return (struct Wrap) { .p = { 0, 1 }, { 2, 3} };
}

struct Wrap fw3 (void)
{
  return (struct Wrap) { .p = { 0, 1 }, .d = { 2, 3} };
}

struct Wrap fw4 (void)
{
  return (struct Wrap) { { 0, 1 }, .d = { 2, 3} };
}

struct Wrap fw5 (void)
{
  return (struct Wrap) { .p = { 0, 1 }, .d = { .x = 2, .y = 3} };
}

struct Wrap fw6 (void)
{
  return (struct Wrap) { { 0, 1 }, .d.x = 2, .d.y = 3 };
}

struct Wrap fw7 (void)
{
  return (struct Wrap) { .p = { 0, 1 }, .d.x = 2, .d.y = 3 };
}

struct Wrap fw8 (void)
{
  return (struct Wrap) { .p = { 0, 1 }, .d = { 2, 0 }, .d.y = 3 };
}

struct Wrap fw9 (void)
{
  return (struct Wrap) { .p = { 0, 1 }, .d = { .x = 2 }, .d.y = 3 };
}

struct Des da[] = {
  { .x = 1, .y = 2 },
  { 5, 5 }
};
