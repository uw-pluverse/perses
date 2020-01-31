



public class ThrowBeforeTryFinally {

    static class MyEx extends Exception {}

    public String test() {
        try {
            if (true) throw new MyEx();
            try {
            } finally {
                return null;
            }
        } catch (MyEx ex) {
            return null;
        }
    }
}
