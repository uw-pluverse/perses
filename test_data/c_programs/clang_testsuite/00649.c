struct foo {
    int v __attribute__((annotate("v_ann_0"))) __attribute__((annotate("v_ann_1")));
};
static struct foo gf;
int main(int argc, char **argv) {
    struct foo f;
    f.v = argc;
    gf.v = argc;
    return 0;
}
