        
#pragma redefine_extname fake real
        
#pragma redefine_extname name alias
extern int fake(void);
int name;
int fish() { return fake() + 1 + name; }
        
#pragma redefine_extname foo bar
int f() {
  int foo = 0;
  return foo;
}
extern int foo() { return 1; }
        
#pragma redefine_extname foo_static bar_static
static int foo_static() { return 1; }
int baz() { return foo_static(); }
