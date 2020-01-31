int foo(int v __attribute__((annotate("param_ann_2"))) __attribute__((annotate("param_ann_3"))));
int foo(int v __attribute__((annotate("param_ann_0"))) __attribute__((annotate("param_ann_1")))) {
    return v + 1;
}
void local(void) {
    int localvar __attribute__((annotate("localvar_ann_0"))) __attribute__((annotate("localvar_ann_1"))) = 3;
}
void undef(void) {
    int undefvar __attribute__((annotate("undefvar_ann_0")));
}
