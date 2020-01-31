




int bar (int x) { return x; }
__attribute__((__target__("no-vsx"))) int foo (int x) { return x; }
