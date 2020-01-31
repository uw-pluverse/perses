




class IllegalQualNotIcls {
    static class C { }
    IllegalQualNotIcls x;
    C c = x.new C() { };
}
