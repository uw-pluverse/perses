



class T6738538a {

    class C<T> {
        public T m(){
            return null;
        }
    }
    interface I<T>{
        public T m();
    }
    class Crash<T extends C<?> & I> {}
}
