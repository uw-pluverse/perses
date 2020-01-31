





typedef struct {
  int x;
  int y;
} Point;

void
foo(Point *p1, Point *p2, Point *p3, int *data)
{
  int m, m1, m2;
  int i;

  for (i = 0; i < 16; i++) {
    m = *data++;

    m1 = p1->x - m;
    m2 = p2->x + m;

    p3->y = (m1 >= m2) ? p1->y : p2->y;

    p1++;
    p2++;
    p3++;
  }
}
