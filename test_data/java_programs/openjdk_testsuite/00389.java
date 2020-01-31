



class Outer<E> {

   public void method(Outer<?>.Inner inner) {
       E entry = inner.getE();
   }

   class Inner {
       E getE() {return null;}
   }
}
