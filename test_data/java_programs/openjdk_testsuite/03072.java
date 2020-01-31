


public class MostSpecific05 {

    interface ObjectConverter<T extends Object> {
        T map(Object o);
    }

    interface NumberConverter<T extends Number> {
        T map(Object o);
    }

    static class MyMapper<A extends Object, B extends Number> {
        void map(ObjectConverter<? extends A> m) { }
        void map(NumberConverter<? extends B> m) { }
    }

    public static void main(String[] args) {
        MyMapper<Number, Double> mm = new MyMapper<Number, Double>();
        mm.map(e->1.0); 
        mm.map((Object e)->1.0); 
    }
}
