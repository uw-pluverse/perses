



import java.lang.invoke.MethodHandle;

public class MethodHandleInvokeTest {

    private static interface Obj2Obj {
        Object run(Object obj) throws Throwable;
    }

    private static void m(Obj2Obj param) {
    }

    public static void main(String[] args) {
        m((obj) -> {
            MethodHandle mhandle = null;
            mhandle.invoke(obj);
            return null;
        });
    }
}
