



public class CondExprInCaseLabel {
    public static void main(String [] args) {
        final boolean cond = true;
        switch (args[0]) {
            case cond ? "hello" : "world":
                break;
        }
    }
}
