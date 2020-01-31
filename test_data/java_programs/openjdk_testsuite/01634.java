

import javax.lang.model.element.ElementKind;

@Check
class Test {

    class A extends Exception {
        @Member(ElementKind.METHOD)
        public void m() {};
        @Member(ElementKind.FIELD)
        public Object f;
    }

    class B1 extends A {}
    class B2 extends A {}

    void test(){
        try {
            if (true)
                throw new B1();
            else
                throw new B2();
        }
        catch(@UnionTypeInfo({"Test.B1", "Test.B2"}) B1 | B2 ex) { }
    }
}
