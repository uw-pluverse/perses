



import javax.lang.model.element.ElementKind;

@Check
class Test {

    interface A {
        @Member(ElementKind.METHOD)
        public void m1();
    }

    interface B {
        @Member(ElementKind.METHOD)
        public void m2();
    }

    void test(){
        @IntersectionTypeInfo({"Test.A", "Test.B"})
        Object o = (A & B)null;
    }
}
