#pragma clang section bss = ".bss.1"
int x;
#pragma clang section bss = ""
int x;
int y;
int z;
#pragma clang section bss = ".bss.2"
int x;
int y;
#pragma clang section rodata = ".rodata.1"
const int cx;
#pragma clang section rodata = ""
const int cx;
const int cy;
const int cz;
#pragma clang section rodata = ".rodata.2"
const int cx;
const int cy;
