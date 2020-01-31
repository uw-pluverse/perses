



import java.util.*;

public class T6468384 {

    public class A {};

    public class B extends A {};

    public <T, V extends T> Set<T> newSet(V... objects) {
        Set<T> set = new LinkedHashSet<T>();
        for (T t : objects) {
            set.add(t);
        }
        return set;
    }

    public static void main(String... args) {
        T6468384 g = new T6468384();

        
        

        
        
        
        Set<A> set1 = g.newSet(g.new B());

        Set<A> set2 = g.<A,B>newSet(g.new B());
    }

}
