


public class MostSpecific04 {

    interface DoubleMapper<T> {
        double map(T t);
    }

    interface LongMapper<T> {
        long map(T t);
    }

    static class MyList<E> {
        void map(DoubleMapper<? super E> m) { }
        void map(LongMapper<? super E> m) { }
    }

    public static void main(String[] args) {
        MyList<String> ls = new MyList<String>();
        ls.map(e->e.length()); 
        ls.map((String e)->e.length()); 
    }
}
