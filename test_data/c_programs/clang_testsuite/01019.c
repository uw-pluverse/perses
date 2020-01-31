#pragma pack(4)
struct ref {
        struct ref *next;
} refs;
struct S
{
  char a[3];
#pragma pack(1)
  struct T
  {
    char b;
    int c;
  } d;
#pragma pack()
  struct T2
  {
    char b;
    int c;
  } d2;
} ss;
struct S3
{
  char a[3];
#pragma pack(push, 2)
  struct T3
  {
    char b;
    int c;
  } d;
#pragma pack(pop)
  struct T32
  {
    char b;
    int c;
  } e;
} s3;
struct S4
{
  char a[3];
#pragma align=packed
  struct T4
  {
    char b;
    int c;
  } d;
  int e;
} s4;
