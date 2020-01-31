


struct s1 { int f; };
typedef int s2;
void
f1 ()
{
  typedef int s1;
  struct s2 { int f; };
}

struct s3 { int f; };
typedef struct s3 s3;

typedef struct s4 s4;
struct s4 { int f; };

struct s5 { int f; };
typedef int s5;

typedef int s6;
struct s6 { int f; };

void
f2 ()
{
  struct s7 { int f; };
  typedef int s7;

  typedef int s8;
  struct s8 { int f; };

  struct s9 { int f; };
  { typedef int s9; }

  typedef int s10;
  { struct s10 { int f; }; }
}

enum e1 { A };
typedef int e2;
void
f3 ()
{
  typedef int e1;
  enum e2 { B };
}

enum e3 { C };
typedef enum e3 e3;

enum e5 { E };
typedef int e5;

typedef int e6;
enum e6 { F };

void
f4 ()
{
  enum e7 { G };
  typedef int e7;

  typedef int e8;
  enum e8 { H };

  enum e9 { I };
  { typedef int e9; }

  typedef int e10;
  { enum e10 { J }; }
}
