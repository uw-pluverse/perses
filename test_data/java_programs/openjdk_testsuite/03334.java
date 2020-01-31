



public class CondExprInCaseLabel2 {
    public static void main(String [] args) {
        final boolean cond = true;
        switch (args[0]) {
            case cond ? "hello" : (String)"world":
                break;
        }
    }
}
