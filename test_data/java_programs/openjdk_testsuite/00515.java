



public class ArrayClone {
    public static void main(String... args) {
        if (args.length==0)
            main("foo", "bar", "xyzzy");
        String[] args2 = args.clone();
        for (int i=0; i<args2.length; i++)
            if (!args[i].equals(args2[i]))
                throw new Error(args2[i]);
        f1(1, 2, 3, 4, 5);
    }
    static void f1(int... a) {
        int[] b = a.clone();
        for (int i=0; i<a.length; i++)
            if (a[i] != b[i])
                throw new Error(""+b[i]);
    }
}
