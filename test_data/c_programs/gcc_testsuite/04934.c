


extern



__attribute__((__simd__("notinbranch")))
int simd_attr (void)
{
  return 0;
}
extern



__attribute__((simd("inbranch")))
int simd_attr2 (void)
{
  return 0;
}
