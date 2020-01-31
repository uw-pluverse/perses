static long long llfoo;
static int intfoo;
static short shortfoo;
static char charfoo;
static int foo(int a) {
    return a + 1;
}
int main(int argc, char **argv) {
    char barray[16];
    char *b = (char *) __builtin_annotation((int)barray, "annotation_a");
    int call = __builtin_annotation(foo(argc), "annotation_a");
    long long lla = __builtin_annotation(llfoo, "annotation_a");
    int inta = __builtin_annotation(intfoo, "annotation_a");
    short shorta = __builtin_annotation(shortfoo, "annotation_a");
    char chara = __builtin_annotation(charfoo, "annotation_a");
    char **arg = (char**) __builtin_annotation((int) argv, "annotation_a");
    return 0;
}
