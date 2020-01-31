


class T7148242 {
   static abstract class A<K, V, I extends Pair<K, V>, I2 extends Pair<V, K>> {
      abstract A<V, K, I2, I> test();
   }
   static class Pair<K, V> { }
}
