



public class CondExprInCaseLabel1 {
    public static void main(String [] args) {
        final boolean cond = true;
        switch (args[0]) {
            case cond ? (String)"hello" : "world":
                break;
        }
    }
}
