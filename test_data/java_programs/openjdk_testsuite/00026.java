



import java.util.*;

interface A { List<Number> getList(); }
interface B { List getList(); }

interface AB extends A, B {} 

interface C<T> { List<T> getList(); }

interface BC<T> extends B, C<T> {} 

interface D { Number m(); }
interface E { Double m(); }

interface DE extends D, E {} 

interface F { ArrayList getList(); }
interface G { Collection getList(); }

interface AG extends A, G{}; 

interface CF<T> extends C<T>, F {} 

interface CG<T> extends C<T>, G {} 

interface H<T> { Iterable<T> getList(); }

interface CH<T> extends C<T>, H<T> {} 

interface CFGH<T> extends C<T>, F, G, H<T> {} 


class Test1 {

    
    void test(AB ab) {
        Number n = ab.getList().get(1);
    }

    void test(BC<String> bc) {
        String s = bc.getList().get(1);
    }

    void testRaw(BC bc) {
        List list = bc.getList();
    }

    void testWildCard(BC<?> bc) {
        List<?> list = bc.getList();
    }

    <T> void testGeneric(BC<T> bc) {
        T t = bc.getList().get(1);
    }

    
    void test(DE de) {
        Double d = de.m();
    }

    
    void test(AG ag) {
        Number n = ag.getList().get(0);
    }

    void test(CF<Integer> cf) {
        ArrayList list = cf.getList();
    }

    void test(CG<String> cg) {
        String s = cg.getList().get(0);
    }

    void test(CH<String> ch) {
        String s = ch.getList().get(0);
    }

    void test(CFGH<Double> cfgh) {
        ArrayList list = cfgh.getList();
    }

    void testWildCard(CFGH<?> cfgh) {
        ArrayList list = cfgh.getList();
    }
}
