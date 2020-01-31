int scanf(const char *restrict format, ...);
int system(const char *command);
void taintDiagnostic()
{
  char buf[128];
  scanf("%s", buf);
  system(buf);
}
