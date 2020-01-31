




extern void abort ();
struct _struct_0
{
  char member_0;
} __attribute__((__ms_struct__));
typedef struct _struct_0 struct_0;

struct _struct_1
{
  char member_0;
  short member_1:13;
} __attribute__((__ms_struct__));
typedef struct _struct_1 struct_1;

struct _struct_2
{
  double member_0;
  unsigned char member_1:8;
  long member_2:32;
  unsigned char member_3:5;
  short member_4:14;
  short member_5:13;
  unsigned char:0;
} __attribute__((__ms_struct__));
typedef struct _struct_2 struct_2;

struct _struct_3
{
  unsigned long member_0:26;
  unsigned char member_1:2;

} __attribute__((__ms_struct__));
typedef struct _struct_3 struct_3;

struct _struct_4
{
  unsigned char member_0:7;
  double member_1;
  double member_2;
  short member_3:5;
  char member_4:2;

} __attribute__((__ms_struct__));
typedef struct _struct_4 struct_4;

struct _struct_5
{
  unsigned short member_0:12;
  long member_1:1;
  unsigned short member_2:6;

} __attribute__((__ms_struct__));
typedef struct _struct_5 struct_5;

struct _struct_6
{
  unsigned char member_0:7;
  unsigned long member_1:25;
  char member_2:1;
  double member_3;
  short member_4:9;
  double member_5;

} __attribute__((__ms_struct__));
typedef struct _struct_6 struct_6;

struct _struct_7
{
  double member_0;

} __attribute__((__ms_struct__));
typedef struct _struct_7 struct_7;

struct _struct_8
{
  unsigned char member_0:7;
  long member_1:11;
  long member_2:5;
  long:0;
  char member_4:8;
  unsigned short member_5:4;
  unsigned char member_6:3;
  long member_7:23;

} __attribute__((__ms_struct__));
typedef struct _struct_8 struct_8;

struct _struct_9
{
  double member_0;
  unsigned long member_1:6;
  long member_2:17;
  double member_3;
  unsigned long member_4:22;

} __attribute__((__ms_struct__));
typedef struct _struct_9 struct_9;

struct_0 test_struct_0 = { 123 };
struct_1 test_struct_1 = { 82, 1081 };
struct_2 test_struct_2 = { 20.0, 31, 407760, 1, 14916, 6712 };
struct_3 test_struct_3 = { 64616999, 1 };
struct_4 test_struct_4 = { 61, 20.0, 20.0, 12, 0 };
struct_5 test_struct_5 = { 909, 1, 57 };
struct_6 test_struct_6 = { 12, 21355796, 0, 20.0, 467, 20.0 };
struct_7 test_struct_7 = { 20.0 };
struct_8 test_struct_8 = { 126, 1821, 22, 125, 6, 0, 2432638 };
struct_9 test_struct_9 = { 20.0, 3, 23957, 20.0, 1001631 };


int
main (void)
{

  if (1 != sizeof (struct_0))
    abort ();

  if (4 != sizeof (struct_1))
    abort ();

  if (24 != sizeof (struct_2))
    abort ();

  if (8 != sizeof (struct_3))
    abort ();

  if (32 != sizeof (struct_4))
    abort ();

  if (12 != sizeof (struct_5))
    abort ();

  if (40 != sizeof (struct_6))
    abort ();

  if (8 != sizeof (struct_7))
    abort ();

  if (20 != sizeof (struct_8))
    abort ();

  if (32 != sizeof (struct_9))
    abort ();

  return 0;
}
