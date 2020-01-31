




typedef int T[2][2];

int
fn1 (int a[])
{
  return sizeof a;
}

int
fn2 (int x, int b[3])
{
  return x + sizeof b;
}

int
fn3 (int *p)
{
  return sizeof p;
}

int fn4 (int *p);
int
fn4 (int p[])
{
  return sizeof p;
}

int fn5 (int x[]);
int
fn5 (int *x)
{
  return sizeof x;
}



int fn6 (int x[*]);
int
fn6 (int x[])
{
  return sizeof x;
}


int
fn7 (int x[][2])
{
  return sizeof x;
}

int
fn8 (char *x[])
{
  return sizeof x;
}

int
fn9 (char **x)
{
  return sizeof x;
}


int
fn10 (int a, char x[static sizeof a])
{
  return sizeof x;
}

int
fn11 (a)
  char a[];
{
  return sizeof a;
}

int
fn12 (a)
  char *a;
{
  return sizeof a;
}


int
fn13 (char (*x)[2])
{
  return sizeof x;
}

int
fn14 (T t)
{
  return sizeof t;
}
