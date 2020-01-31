


import java.util.List;

class T7041019 {
   <E> List<E>[] m(List<E> l) { return null; }

   void test(List<? extends String> ls) {
      int i = m(ls).length;
   }
}
