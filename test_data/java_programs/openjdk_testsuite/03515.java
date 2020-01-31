

abstract class CompatibleAbstracts2
    implements A, B 
{
    void f(A a, B b) {
        if (a == b) ;
        B b2 = (B) a;
        A a2 = (A) b;
    }
}
