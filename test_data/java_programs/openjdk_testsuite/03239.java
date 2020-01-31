



import java.lang.reflect.Method;
import java.util.HashSet;
import java.util.Set;

public class LambdaTest6<T> {

    interface H {Object m();}

    interface K<U> {void m(U element);}

    interface L extends K<String> {} 

    interface M {void m(String s);}

    interface KM extends K<String>, M{} 

    interface N extends H {String m();} 

    private static void assertTrue(boolean b) {
        if(!b)
            throw new AssertionError();
    }

    private Set<String> setOfStringObject() {
        Set<String> s = new HashSet<>();
        s.add("java.lang.String");
        s.add("java.lang.Object");
        return s;
    }

    private void test1()
    {
        L la = s -> { };
        la.m("hi");
        Class<? extends L> c1 = la.getClass();
        Method[] methods = c1.getDeclaredMethods();
        Set<String> types = setOfStringObject();
        for(Method m : methods) {
            assertTrue(m.getName().equals("m"));
            Class[] parameterTypes = m.getParameterTypes();
            assertTrue(parameterTypes.length == 1);
            assertTrue(types.remove(parameterTypes[0].getName()));
        }
        assertTrue(types.isEmpty() || (types.size() == 1 && types.contains("java.lang.String")));
    }

    private void test2()
    {
        KM km = s -> { };
        
        Class<? extends KM> c2 = km.getClass();
        Method[] methods = c2.getDeclaredMethods();
        Set<String> types = setOfStringObject();
        for(Method m : methods) {
            assertTrue(m.getName().equals("m"));
            Class[] parameterTypes = m.getParameterTypes();
            assertTrue(parameterTypes.length == 1);
            assertTrue(types.remove(parameterTypes[0].getName()));
        }
        assertTrue(types.isEmpty());
    }

    private void test3()
    {
        N na = ()-> "hi";
        assertTrue( na.m().equals("hi") );
        assertTrue( ((H)na).m().equals("hi") );
        Class<? extends N> c3 = na.getClass();
        Method[] methods = c3.getDeclaredMethods();
        Set<String> types = setOfStringObject();
        for(Method m : methods) {
            assertTrue(m.getName().equals("m"));
            Class returnType = m.getReturnType();
            assertTrue(types.remove(returnType.getName()));
        }
        assertTrue(types.size() == 1); 
    }


    public static void main(String[] args) {
        LambdaTest6 test = new LambdaTest6();
        test.test1();
        test.test2();
        test.test3();
    }
}
