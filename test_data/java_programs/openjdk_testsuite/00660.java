

public class MisleadingErrorMsgDiamondPlusPrivateCtorTest {
    public void foo() {
        MyClass<Object> foo = new MyClass<>();
    }
}

class MyClass<E> {
    private MyClass() {}
}
