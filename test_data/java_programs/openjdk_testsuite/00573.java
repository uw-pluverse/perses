



public class WrongStackframeGenerationTest1 {
    public static void main(String[] args) {}

    static void foo(){
        while (true) {
            int i = 0;
            break;
        }
        switch (1) {
            case 1:
                int j = 0;
            case 2:
                bar();
        }
    }

    static void bar() {}
}
