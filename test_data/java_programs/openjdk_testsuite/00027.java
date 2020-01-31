



import java.util.*;

interface A { void m(Map map); }
interface B { void m(Map<Number, String> map); }

interface AB extends A, B {} 

interface C<K, V> { List<V> getList(Map<K, V> map); }
interface D { ArrayList getList(Map map); }

interface CD<K, V> extends C<K, V>, D {} 

interface E<T> { T get(List<?> list); }
interface F<T> { T get(List list); }

interface EF<T1, T2 extends T1> extends E<T1>, F<T2> {} 

class Test2 {

    
    void test(AB ab) {
        ab.m(new HashMap<Number, String>());
    }

    
    void testRaw(CD cd) { 
        ArrayList al = cd.getList(new HashMap());
    }

    <K, V> void testGeneric(CD<K, V> cd) { 
        V v = cd.getList(new HashMap<K, V>()).get(0);
    }

    void test(CD<Number, String> cd) { 
        String s = cd.getList(new HashMap<Number, String>()).get(0);
    }

    void test(EF<Number, Integer> ef) { 
        Number n = ef.get(new ArrayList<Integer>());
    }

    <T, U extends T> void testGeneric(EF<T, U> ef) { 
        T t = ef.get(new ArrayList<U>());
    }
}
