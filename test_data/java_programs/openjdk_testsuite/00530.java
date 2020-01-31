

class T6946618b {
    static class C<T> {
      T makeT() {
        return new T<>(); 
      }
    }

    static class D<S> {
      C<S> makeC() {
        return new C<>(); 
      }
    }
}
