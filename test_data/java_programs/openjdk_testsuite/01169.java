




class ExplicitParamsDoNotConformToBounds {
    <X extends Number> void m() {}
    { this.<String>m(); }
}
