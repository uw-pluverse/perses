





package meth;

import java.lang.invoke.MethodHandle;

public class InvokeMH {
    void test(MethodHandle mh_SiO,
              MethodHandle mh_vS,
              MethodHandle mh_vi,
              MethodHandle mh_vv) throws Throwable {
        Object o; String s; int i;  

        
        mh_SiO.invokeExact("world", 123);
        mh_SiO.invokeExact("mundus", 456);
        Object k = "kosmos";
        mh_SiO.invokeExact((String)k, 789);
        o = mh_SiO.invokeExact((String)null, 000);
        o = (Object) mh_SiO.invokeExact("arda", -123);

        
        s = (String) mh_vS.invokeExact();

        
        i = (int) mh_vi.invokeExact();
        o = (int) mh_vi.invokeExact();

        
        mh_vv.invokeExact();
    }

    void testGen(MethodHandle mh_SiO,
                 MethodHandle mh_vS,
                 MethodHandle mh_vi,
                 MethodHandle mh_vv) throws Throwable {
        Object o; String s; int i;  

        
        o = mh_SiO.invoke((Object)"world", (Object)123);
        mh_SiO.invoke((Object)"mundus", (Object)456);
        Object k = "kosmos";
        o = mh_SiO.invoke(k, 789);
        o = mh_SiO.invoke(null, 000);
        o = mh_SiO.invoke("arda", -123);

        
        o = mh_vS.invoke();

        
        i = (int) mh_vi.invoke();
        o = (int) mh_vi.invoke();
        mh_vi.invoke();

        
        mh_vv.invoke();
        o = mh_vv.invoke();
    }
}
