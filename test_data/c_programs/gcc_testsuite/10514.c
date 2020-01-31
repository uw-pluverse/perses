


__attribute__((__error__("error"))) void error ();

void f (int i) {
    if (__builtin_constant_p (i)) {
 error ();
    }
}
