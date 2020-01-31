






public class Closure2 {
    private int mValue;

    public Closure2() {
        new inner2();
    }

    private abstract class inner {
        public inner() {
            go();
        }
        public abstract void go();
    }

    private class inner2 extends inner {
        public void go() {
            mValue = 2;
        }
    }

    public static void main(String args[]) {
        new Closure2();
    }
}
