int foo() __attribute__((__hot__));
int bar() __attribute__((__cold__));
int var1 __attribute__((__cold__));
int var2 __attribute__((__hot__));
int qux() __attribute__((__hot__)) __attribute__((__cold__));
int baz() __attribute__((__cold__)) __attribute__((__hot__));
