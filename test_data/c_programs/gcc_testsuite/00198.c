


void f1 (void);
void __attribute__((mips16)) f1 (void) {}

void __attribute__((mips16)) f2 (void);
void f2 (void) {}

void f3 (void);
void __attribute__((nomips16)) f3 (void) {}

void __attribute__((nomips16)) f4 (void);
void f4 (void) {}

void __attribute__((mips16, nomips16)) f5 (void) {}
