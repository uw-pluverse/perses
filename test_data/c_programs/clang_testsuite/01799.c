struct Point {
  float x, y;
};
struct Rectangle {
  struct Point top_left,
               bottom_right;
};
enum Color { Red, Green, Blue };
struct Window {
  struct Rectangle bounds;
  enum Color color;
};
struct Window window = {
  .bunds.
  topleft.x = 3.14,
  2.71818, 5.0, 6.0, Red
};
void test() {
  Rectangle r1;
  r1.top_left.x = 0;
  typedef struct Rectangle Rectangle;
  rectangle *r2 = &r1;
  r2->top_left.y = 0;
  unsinged *ptr = 0;
  *ptr = 17;
}
