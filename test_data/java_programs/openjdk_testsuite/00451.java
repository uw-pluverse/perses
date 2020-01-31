



class Test2 {
    interface Ord {}

    static <B extends Ord> List<B> nil() { return new List<B>(); }

    static <A> List<A> cons(A x, List<A> xs) { return xs.prepend(x); }
    static <A> Cell<A> makeCell(A x) { return new Cell<A>(x); }
    static <A> A id(A x) { return x; }

    public static void main(String[] args) {
        List<Ord> xs = nil();
        List<Ord> zs = nil().prependList(nil());

        System.out.println(nil());
        System.out.println(nil().length());

        List<Ord> a = args.length == 1 ? nil() : nil();
        a = (List<Ord>) nil();
    }

}
