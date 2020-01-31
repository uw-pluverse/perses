



public class WrongStackframeGenerationTest2 {
    public static void main(String[] args) {}

    static void foo() {
        int len;
        for (;;) {
            try {
                len = 1;
                break;
            } catch (Exception e) {
            }
        }

        try {
           if (len == -1) {
               len = 0;
           }
        } finally {
        }
    }
}
