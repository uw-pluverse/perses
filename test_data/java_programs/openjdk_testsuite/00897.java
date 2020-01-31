



enum Color {
    red, green
}

public class EnumSwitch {
    static int f(Color c) {
        switch(c) {
        case red:
            return 1;
        case green: 
            return 2;
        default:
            return 0;
        }
    }

    public static void main(String[] args) {
        f(Color.red);
        System.out.println("test passed");
    }
}
