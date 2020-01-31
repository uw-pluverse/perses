



class Test {

    static <B> List<B> nil() { return new List<B>(); }
    static <A> List<A> cons(A x, List<A> xs) { return xs.prepend(x); }
    static <A> Cell<A> makeCell(A x) { return new Cell<A>(x); }
    static <A> A id(A x) { return x; }

    public static void main(String[] args) {
        List<String> xs = nil();
        List<String> ys = cons("abc", Test.<String>nil());
        List<String> zs = Test.<String>nil().prepend("abc");

        System.out.println(nil());
        System.out.println(nil().length());

        System.out.println(cons("abc", nil()));
        System.out.println(nil().prepend("abc"));
        System.out.println(nil().prepend(makeCell(null)));
        System.out.println(cons(makeCell(null), nil()));

        System.out.println(id(nil()));
        System.out.println(id(nil()).length());

        System.out.println(cons("abc", id(nil())));
        System.out.println(id(nil()).prepend("abc"));
        System.out.println(id(nil()).prepend(makeCell(null)));
        System.out.println(cons(makeCell(null), id(nil())));

        List<String> a =
            args.length == 1 ? Test.<String>nil() : Test.<String>nil();
        a = (List<String>) Test.<String>nil();
    }

}
