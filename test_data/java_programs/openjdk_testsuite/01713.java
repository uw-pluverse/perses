

import java.lang.invoke.*;

class VarargsWarn {
    void test(MethodHandle mh) throws Throwable {
        mh.invokeExact((Integer[])null);
        mh.invoke((Integer[])null);
        mh.invokeWithArguments((Integer[])null); 
    }
}
