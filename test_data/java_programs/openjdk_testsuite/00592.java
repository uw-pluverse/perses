



public class WhichImplicitThis4 {
    boolean isCorrect() { return true; }
    void check() {
        class I2 {
            I2() {
                if (!isCorrect()) throw new Error();
            }
        }
        class I3 extends WhichImplicitThis4 {
            boolean isCorrect() { return false; }
            public void check() {
                new I2() {
                        
                };
            }
        }
        new I3().check();
    }
    public static void main(String[] args) {
        new WhichImplicitThis4().check();
    }
}
