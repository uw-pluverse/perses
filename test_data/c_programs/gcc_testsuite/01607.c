







extern void bar(float *, float *, float *, float *);
void foo()
{
 int i;
 float a[16], b[16], c[16], d[16];
 bar(a,b,c,d);
 for (i = 0; i < 16; i++) {
  a[i] = b[i] + c[i] * d[i];
 }
 bar(a,b,c,d);






 for (i = 0; i < 16; i++) {
  a[i] = b[i] * c[i] + d[i];
 }
 bar(a,b,c,d);
 for (i = 0; i < 16; i++) {
  a[i] = b[i] * c[i] - d[i];
 }
 bar(a,b,c,d);
}
