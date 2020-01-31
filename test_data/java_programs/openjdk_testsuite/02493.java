import java.lang.annotation.ElementType;





import java.lang.annotation.*;

class InnerClass {

    InnerClass() {}
    InnerClass(Object o) {}

    private void a() {
        new Object() {
            public <R> void method() { }
        };
    }

    Object f1 = new InnerClass() {
            <R> void method() { }
        };

    Object f2 = new InnerClass() {
            <@A R> void method() { }
        };

    Object f3 = new InnerClass(null) {
            <R> void method() { }
        };

    Object f4 = new InnerClass(null) {
            <@A R> void method() { }
        };

    @Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
    @interface A { }
}
