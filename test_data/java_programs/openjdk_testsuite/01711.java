



import java.lang.invoke.*;

class XlintWarn {
    void test(MethodHandle mh) throws Throwable {
        int i1 = (int)mh.invokeExact();
        int i2 = (int)mh.invoke();
        int i3 = (int)mh.invokeWithArguments();
    }

    void test2(MethodHandle mh) throws Throwable {
        int i1 = (int)(mh.invokeExact());
        int i2 = (int)(mh.invoke());
        int i3 = (int)(mh.invokeWithArguments());
    }

    void test3(MethodHandle mh) throws Throwable {
        int i1 = (int)((mh.invokeExact()));
        int i2 = (int)((mh.invoke()));
        int i3 = (int)((mh.invokeWithArguments()));
    }
}
