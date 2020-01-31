



package p;

public abstract class Tree {

    
    public abstract <E extends Throwable> void accept(Visitor<E> v) throws E;


    
    public static abstract class Visitor<E extends Throwable> {
        public void visitTree(Tree that)                   throws E { assert false; }
    }
}
