



class Dummy {
}

class AnonymousType {
    void method() {
        new Dummy() {
            void foo() {
            }
        }.foo();
    }
}
