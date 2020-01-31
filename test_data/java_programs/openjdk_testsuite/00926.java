



import java.util.AbstractCollection;
import java.util.Collection;
import java.util.Iterator;

interface Q<E> extends Collection<E> {}

abstract class AbstractQ<E> extends AbstractCollection<E> implements Q<E> {
    
    
}

class ConcreteQ<E> extends AbstractQ<E> {
    public int size() { return 0; }
    public Iterator<E> iterator() { return null; }
}

public class SuperfluousAbstract {
    public static void main(String[] args) {
        try {
            Q<Integer> q = new ConcreteQ<Integer>() ;
            for (Integer i : q) {}
        }
        catch (AbstractMethodError e) {
            e.printStackTrace(System.err);
        }
        catch (NullPointerException e) {
            
        }
    }
}
