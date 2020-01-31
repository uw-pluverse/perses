


class T8015101 {

     public static class Bug<X extends Child<?, ?> & Runnable> {
     }

     interface Parent<C> {
         public C get();
     }

     interface Child<C, S extends C> extends Parent<C> {
         @Override
         public S get();
     }

 }
