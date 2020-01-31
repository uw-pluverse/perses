




unsigned int bar (void);




void foo0x1 (void) { unsigned int a = bar (); if (a <= 0x1) bar (); }
void foo0x3 (void) { unsigned int a = bar (); if (a <= 0x3) bar (); }
void foo0x7 (void) { unsigned int a = bar (); if (a <= 0x7) bar (); }
void foo0xf (void) { unsigned int a = bar (); if (a <= 0xf) bar (); }
void foo0x1f (void) { unsigned int a = bar (); if (a <= 0x1f) bar (); }
void foo0x3f (void) { unsigned int a = bar (); if (a <= 0x3f) bar (); }
void foo0x7f (void) { unsigned int a = bar (); if (a <= 0x7f) bar (); }
void foo0xff (void) { unsigned int a = bar (); if (a <= 0xff) bar (); }
void foo20x1 (void) { unsigned int a = bar (); if (a > 0x1) bar (); }
void foo20x3 (void) { unsigned int a = bar (); if (a > 0x3) bar (); }
void foo20x7 (void) { unsigned int a = bar (); if (a > 0x7) bar (); }
void foo20xf (void) { unsigned int a = bar (); if (a > 0xf) bar (); }
void foo20x1f (void) { unsigned int a = bar (); if (a > 0x1f) bar (); }
void foo20x3f (void) { unsigned int a = bar (); if (a > 0x3f) bar (); }
void foo20x7f (void) { unsigned int a = bar (); if (a > 0x7f) bar (); }
void foo20xff (void) { unsigned int a = bar (); if (a > 0xff) bar (); }
