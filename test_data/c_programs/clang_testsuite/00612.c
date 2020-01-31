typedef struct { unsigned int i: 1; } c;
const c d = { 1 };
struct Token {
  unsigned n : 31;
};
void sqlite3CodeSubselect(){
  struct Token one = { 1 };
}
typedef union T0 { char field0 : 2; } T0;
T0 T0_values = { 0 };
