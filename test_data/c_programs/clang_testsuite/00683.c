struct _struct_0
{
  int member_0 : 25 ;
  short member_1 : 6 ;
  char member_2 : 2 ;
  unsigned short member_3 : 1 ;
  unsigned char member_4 : 7 ;
  short member_5 : 16 ;
  int : 0 ;
  char member_7 ;
} __attribute__((__ms_struct__));
typedef struct _struct_0 struct_0;
struct_0 test_struct_0 = { 18557917, 17, 3, 0, 80, 6487, 93 };
static int a[(20 == sizeof (struct_0)) -1];
struct _struct_1 {
  int d;
  unsigned char a;
  unsigned short b:7;
  char c;
} __attribute__((__ms_struct__));
typedef struct _struct_1 struct_1;
struct_1 test_struct_1 = { 18557917, 'a', 3, 'b' };
static int a1[(12 == sizeof (struct_1)) -1];
struct ten {
  long long a:3;
  long long b:3;
  char c;
} __attribute__ ((ms_struct));
static int a2[(16 == sizeof (struct ten)) -1];
