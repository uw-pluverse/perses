



import java.util.*;

public abstract class Casting2<E extends Enum<E>> extends AbstractSet<E>
    implements Cloneable, java.io.Serializable
{
    public static <E extends Enum<E>> Casting2<E> copyOf(Collection<E> s) throws CloneNotSupportedException {
        return (Casting2<E>)((Casting2<E>)s).clone();
    }
}
