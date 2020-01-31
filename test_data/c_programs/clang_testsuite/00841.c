struct s1 {
  int f32;
  long long f64;
} s1;
struct s2 {
  int f32;
  long long f64[4];
} s2;
struct s3 {
  int f32;
  struct s1 s;
} s3;
