



import java.util.*;

class T6294779b {

    interface I1<E> {
        List<E> m();
    }

    interface I2<E> {
        Queue<E> m();
    }

    interface I3<E> {
        LinkedList<E> m();
    }

    interface I4<E> extends I1<E>, I2<E>, I3<E> {}
}
