long long f0(void) {
 struct { unsigned f0 : 32; } x = { 18 };
 return (long long) (x.f0 - (int) 22);
}
long long f1(void) {
 struct { unsigned f0 : 31; } x = { 18 };
 return (long long) (x.f0 - (int) 22);
}
long long f2(void) {
 struct { unsigned f0 ; } x = { 18 };
 return (long long) (x.f0 - (int) 22);
}
