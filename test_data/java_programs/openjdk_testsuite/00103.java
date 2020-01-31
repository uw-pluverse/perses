



class T6835428<T> {
    interface X<T> {}
   <T extends Comparable<? super T>> T6835428<X<T>> m() { return null; }
   <T extends Comparable<? super T>> void test() {
      T6835428<X<T>> t = m();
   }
}
