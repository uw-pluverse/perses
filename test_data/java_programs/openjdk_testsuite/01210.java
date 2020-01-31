




import p1.B;

class InaccessibleVarargsType {
    { new B().foo(new B(), new B()); }
}
