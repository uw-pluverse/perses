



public class T6370653 {
    static boolean test() {
        int x = 10;
        int y = x--;
        
        return (x == 9) && (y == 10);
    }

    public static void main(String[] args) {
        if (!test()) {
            throw new Error("Test failed.");
        }
    }
}
