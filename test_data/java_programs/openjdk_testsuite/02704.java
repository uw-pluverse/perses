



public class NestedFinallyReturn {
    public static void main(String[] argv) {
        try {
            Object o = new Object() {
                public String toString() {
                    try { return "Hi"; }
                    finally {
                        System.out.println("nestedFinally");
                    }
                }
            };
        }
        finally { System.out.println("outerFinally"); }
    }
}
