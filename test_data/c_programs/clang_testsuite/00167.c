#pragma options
#pragma options align
#pragma options align =
#pragma options align = foo
#pragma options align = reset foo
#pragma options align=natural
#pragma options align=reset
#pragma options align=mac68k
#pragma options align=power
#pragma align
#pragma align =
#pragma align = foo
#pragma align = reset foo
#pragma align=natural
#pragma align=reset
#pragma align=mac68k
#pragma align=power
struct S
{
  char a[3];
#pragma align=packed
  struct T
  {
    char b;
    int c;
  } d;
};
