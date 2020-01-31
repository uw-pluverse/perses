#pragma clang system_header
typedef struct __sFILE {
  unsigned char *_p;
} FILE;
FILE *fopen(const char * restrict, const char * restrict) __asm("_" "fopen" );
int fputc(int, FILE *);
int fputs(const char * restrict, FILE * restrict) __asm("_" "fputs" );
int fclose(FILE *);
void exit(int);
typedef struct __FileStruct {
  FILE * p;
} FileStruct;
void fakeSystemHeaderCall(FileStruct *);
void checkDoubleFClose(int *Data) {
  FILE *F = fopen("myfile.txt", "w");
  if (F != 0) {
    fputs ("fopen example", F);
    if (!Data)
      fclose(F);
    else
      fputc(*Data, F);
    fclose(F);
  }
}
int checkLeak(int *Data) {
  FILE *F = fopen("myfile.txt", "w");
  if (F != 0) {
    fputs ("fopen example", F);
  }
  if (Data)
    return *Data;
  else
    return 0;
}
void checkLeakFollowedByAssert(int *Data) {
  FILE *F = fopen("myfile.txt", "w");
  if (F != 0) {
    fputs ("fopen example", F);
    if (!Data)
      exit(0);
    fclose(F);
  }
}
void CloseOnlyOnValidFileHandle() {
  FILE *F = fopen("myfile.txt", "w");
  if (F)
    fclose(F);
  int x = 0;
}
void leakOnEnfOfPath1(int *Data) {
  FILE *F = fopen("myfile.txt", "w");
}
void leakOnEnfOfPath2(int *Data) {
  FILE *F = fopen("myfile.txt", "w");
  return;
}
FILE *leakOnEnfOfPath3(int *Data) {
  FILE *F = fopen("myfile.txt", "w");
  return F;
}
void myfclose(FILE *F);
void SymbolEscapedThroughFunctionCall() {
  FILE *F = fopen("myfile.txt", "w");
  myfclose(F);
  return;
}
FILE *GlobalF;
void SymbolEscapedThroughAssignmentToGlobal() {
  FILE *F = fopen("myfile.txt", "w");
  GlobalF = F;
  return;
}
void SymbolDoesNotEscapeThoughStringAPIs(char *Data) {
  FILE *F = fopen("myfile.txt", "w");
  fputc(*Data, F);
  return;
}
void passConstPointer(const FILE * F);
void testPassConstPointer() {
  FILE *F = fopen("myfile.txt", "w");
  passConstPointer(F);
  return;
}
void testPassToSystemHeaderFunctionIndirectly() {
  FileStruct fs;
  fs.p = fopen("myfile.txt", "w");
  fakeSystemHeaderCall(&fs);
}
