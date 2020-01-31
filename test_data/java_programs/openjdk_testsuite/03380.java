

class T66862608b<T extends String, S> {
   <S, T extends S> void foo(T t) {
      test(t);
   }

   void test(T t) {}
}
