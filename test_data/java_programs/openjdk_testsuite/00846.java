



public class T6675483 {
    enum E implements Comparable<E> {}

    interface C<T extends E & Comparable<E>> {
        <S extends E & Comparable<E>> void m();
    }
}
