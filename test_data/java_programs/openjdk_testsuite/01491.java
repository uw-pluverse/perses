



class QualifiedNewStaticClass {
    static class C { }
    QualifiedNewStaticClass x;
    C c = x.new C();
}
