





class InferVarargsArgumentMismatch {
    <X> void m(X x1, String... xs) {}
    { this.m("", 1); }
}
