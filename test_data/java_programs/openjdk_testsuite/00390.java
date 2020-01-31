


class Outer<E> {

   public void method(Outer<? extends E>.Inner inner) {
       E entry = inner.getE();
   }

   class Inner {
       E getE() {return null;}
   }
}
