



public class T6218229 {
    static interface Ac<S extends St<S,A>,A extends Ac<S,A>> { };
    static interface St<S extends St<S,A>,A extends Ac<S,A>> { };
    static abstract class CSS<X, Y> implements St<CSS<X, Y>, CSN<X, Y>> {};
    static final class CSN<X, Y> extends CSS<X, Y> implements Ac<CSS<X, Y>, CSN<X, Y>> {};
}
