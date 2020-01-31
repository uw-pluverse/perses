



class T6270087 {

    static class Foo<X> {}

    <S extends Comparable<S>> void test1(Comparable<Integer> c) {
        Object o = (Comparable<S>)c;
    }

   <U extends Throwable, V extends Runnable> void test2(Foo<V> lv) {
        Object o = (Foo<U>) lv;
   }
}
