



public class T6404756 {
    public void foo(Foo f) {
        @Deprecated String s1 = f.foo;
    }

}

class Foo {
    @Deprecated String foo;
}
