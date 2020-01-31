



public class MethodRefNewInnerInLambdaNPE2 {

    interface Constructor {
        MyTest execute();
    }

    class MyTest {
        MyTest() { System.out.println("Constructor executed"); }
    }

    public Constructor getConstructor() {
        return getConstructor(() -> { return MyTest::new; });
    }

    public static void main(String argv[]) {
        MethodRefNewInnerInLambdaNPE2 t = new MethodRefNewInnerInLambdaNPE2();
        MyTest mytest = t.getConstructor().execute();
    }

    Constructor getConstructor(Wrapper arg) {
        return arg.unwrap();
    }

    interface Wrapper {
        Constructor unwrap();
    }
}
