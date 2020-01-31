

int x; int y;
struct { int x; int y; } global;
int foo() {
 int i;
 for ( i=0; i<10; i++)
  y += x*x;
 for ( i=0; i<10; i++)
  global.y += global.x*global.x;
}
