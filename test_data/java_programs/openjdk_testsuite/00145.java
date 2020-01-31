



import java.util.*;

public class T6273455<T extends Comparable<? super T>> {

    abstract class Group<E extends Comparable<? super E>>
        extends ArrayList<E>
        implements Comparable<Group<? extends E>> {}

    abstract class Sequence<E extends Comparable<? super E>>
        extends TreeSet<E>
        implements Comparable<Sequence<? extends E>> {}

    public void containsCombination(SortedSet<Group<T>> groups,
                                    SortedSet<Sequence<T>> sequences) {
        foo(groups, sequences);
    }

    <C extends Collection<T>> void foo(SortedSet<? extends C> setToCheck,
                                       SortedSet<? extends C> validSet) {}

}
