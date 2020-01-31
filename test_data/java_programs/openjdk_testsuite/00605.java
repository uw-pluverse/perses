



public class WhichImplicitThis3 {
    boolean isCorrect() { return true; }
    void check() {
        class I2 {
            public void check() {
                if (!isCorrect()) throw new Error();
            }
        }
        class I3 extends WhichImplicitThis3 {
            boolean isCorrect() { return false; }
            public void check() {
                new I2().check(); 
            }
        }
        new I3().check();
    }
    public static void main(String[] args) {
        new WhichImplicitThis3().check();
    }
}
