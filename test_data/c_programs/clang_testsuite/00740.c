extern union Us { short s; } us;
union Us callee_us() { return us; }
void caller_us() {
  us = callee_us();
}
extern struct Ss { short s; } ss;
struct Ss callee_ss() { return ss; }
void caller_ss() {
  ss = callee_ss();
}
