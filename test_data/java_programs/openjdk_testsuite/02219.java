



class A<E> {
}
class B<E> {
}
class C<E> {
    public B<E> iter() {
        return new D(); 
    }
    class D<E> extends B<E> {
    }
}
