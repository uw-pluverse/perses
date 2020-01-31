



package Casting;

class Test {}

class List<T> {
    <T> T[] toArray(T[] a) { return null; }
}

public class Casting {
    public static void main(String[] args) {
        List<Test> l1 = null;
        List<Test> l2 = (List<Test>)l1;
    }
}

interface Map<K,V> {
    void put(K k, V v);
    V get(Object o);
}
interface Set<T> {
    <T> T[] toArray(T[] a);
}

class Casting2 {
     public static void main(String[] args){
         Map<Integer,Set<Integer>> map = null;
         if (map.get(new Integer(1)) == map.get(new Integer(2))) ;
     }
}
