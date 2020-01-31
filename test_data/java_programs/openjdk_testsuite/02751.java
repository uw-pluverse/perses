





public class LateAddition {
    public int f() {
        class Local {
            private int i = 5;
        }
        return (new Local()).i;
    }
}
