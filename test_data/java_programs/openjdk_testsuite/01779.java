



public class ClassLit {
    public static void main(String[] args) {
        ClassLit t = new ClassLit();
        if (t.getClass() != ClassLit.class) throw new Error();
        int[] a = new int[2];
        if (a.getClass() != int[].class) throw new Error();
        if (int.class != Integer.TYPE) throw new Error();
    }
}
