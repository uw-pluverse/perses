struct s1 {
  int f32;
  long long f64;
} __attribute__((__ms_struct__)) s1;
struct s2 {
  int f32;
  long long f64[4];
} __attribute__((__ms_struct__)) s2;
struct s3 {
  int f32;
  struct s1 s;
} __attribute__((__ms_struct__)) s3;
