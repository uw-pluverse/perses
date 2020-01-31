


package p;
import p.Tree.*;

public class TreeScanner<E extends Throwable> extends Visitor<E> {

    
    public void scan(Tree tree) throws E {
        if(tree!=null) tree.accept(this);
    }
}
