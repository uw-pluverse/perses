









class WhereIntersection {
    interface I1 {}
    interface I2 {}
    class A implements I1, I2 {}
    class B implements I1, I2 {}
    class Test {
        <Z> Z m(Z z1, Z z2) { return null; }
        void main(){
            A a = m(new A(), new B());
        }
    }
}
