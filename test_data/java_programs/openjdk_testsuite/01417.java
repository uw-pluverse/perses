




class InferArgsLengthMismatch {
    <X extends Number> void m(X x1, X x2) {}
    { this.m(1); }
}
