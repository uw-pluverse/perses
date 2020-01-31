



public class NullQualifiedNew2 {
    class Inner {
        Inner(int i) {}
    }
    public static void main(String[] args) {
        int i = 1;
        a: try {
            NullQualifiedNew2 c = null;
            c.new Inner(i++) {};
        } catch (NullPointerException e) {
            break a;
        }
        if (i != 1) throw new Error("i = " + i);
    }
}
