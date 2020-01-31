

const int v1;
const char * const v2;
struct s { int f1; int f2; };
const struct s v3;
const int v4 = 1;
const char * const v5 = 0;
const struct s v6 = { 0, 0 };
const struct s v7 = { 0 };
void
f()
{
  const int v11;
  const char * const v12;
  const struct s v13;
  const int v14 = 1;
  const char * const v15 = 0;
  const struct s v16 = { 0, 0 };
  const struct s v17 = { 0 };
}
