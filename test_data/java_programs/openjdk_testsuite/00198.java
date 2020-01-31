



public class InterfaceCast1 {
    public static void main(String[] args) throws Exception {
    }
}

interface Collection<E> {
    <T> T[] toArray(T[] a);
}

interface Set<E> extends Collection<E> {
    <T> T[] toArray(T[] a);
}

interface SortedSet<E> extends Set<E> {
}

class TreeSet<E> {
    public void addAll(Collection<E> c) {
        if (c instanceof SortedSet) {
            SortedSet<E> ss = (SortedSet<E>) c;
        }
    }
}
