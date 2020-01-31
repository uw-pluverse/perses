void builtinType(_Bool B, char C, unsigned char UC, signed char SC, short S,
                 unsigned short US, signed short SS, int I, unsigned int UI,
                 signed int SI, long L, unsigned long UL, signed long SL,
                 long long LL, unsigned long long ULL, signed long long SLL,
                 float F, double D, long double LD) {}
double _Complex Complex;
extern void eI();
void gI() {eI();};
extern void eV(void);
void gV(void) {eV();}
extern void eVA(int, ...);
void gVA(int i, ...) {eVA(i);}
extern const volatile int* volatile restrict const
    eQ(const volatile int * volatile restrict const);
const volatile int* volatile restrict const
    gQ(const volatile int * volatile restrict const i) {return eQ(i);}
extern int* EP;
int* GP;
int* pointerType(int *I, int * (*FP)(int *)) {
  return I? EP : GP;
}
extern int GA2[3][2];
extern const volatile int EA1[];
extern int EA2[2];
extern int EA3[][2];
extern int EA4[3][2];
const volatile int GA1[2];
extern void arrayTypeVariable1(int[*][2]);
extern void arrayTypeVariable2( void(*fp)(int[*][2]) );
extern void arrayTypeVariable3(int[3][*]);
extern void arrayTypeVariable4( void(*fp)(int[3][*]) );
typedef int RetType[2];
RetType* arrayType(int A1[], int const volatile A2[2], int A3[][2],
                   int A4[3][2], int A5[const volatile restrict static 2]) {
  if (A1) EA2[0] = EA1[0];
  if (A2) return &EA2;
  if (A3) return EA3;
  if (A4) return EA4;
  if (A5) EA2[0] = GA1[0];
  arrayTypeVariable1(EA4);
  arrayTypeVariable2(arrayTypeVariable1);
  arrayTypeVariable3(EA4);
  arrayTypeVariable4(arrayTypeVariable3);
  return GA2;
}
struct S2;
struct S1{struct S2 *ps2;};
struct S3;
struct S2{struct S3 *ps3;};
struct S3{struct S1 s1;};
struct S4{struct S1 s1;};
void structureType1(struct S1 s1){}
void structureType2(struct S2 s2){}
void structureType3(struct S3 s3){}
void structureType4(struct S4 s4){}
struct {int A;} StructAnon = {1};
struct SB{int:4; int:2; int N4:4; int N2:2; unsigned int:4; signed int:4;
          const int:4; int const :4; volatile const int:4;};
int structureTypeB(struct SB sb){return StructAnon.A;}
union U2;
union U1{union U2 *pu2;};
union U3;
union U2{union U3 *pu3;};
union U3{union U1 u1;};
union U4{union U1 u1;};
void unionType1(union U1 u1) {}
void unionType2(union U2 u2) {}
void unionType3(union U3 u3) {}
void unionType4(union U4 u4) {}
union UB{int:4; int:2; int N4:4; int N2:2; unsigned int:4; signed int:4;
         const int:4; int const :4; volatile const int:4;};
union {int A;} UnionAnon = {1};
int unionTypeB(union UB ub) {return UnionAnon.A;}
enum E {D, C=5, B, A};
enum {EA=3} EnumAnon = EA;
int enumType(enum E e) {return EnumAnon;}
extern int After[];
extern int Before[10];
int testReDecl() {return After[0] + Before[0];}
int After[10];
int Before[];
