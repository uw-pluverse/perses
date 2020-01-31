



public class T4494762 {

    static class Homer {
        float doh(float f) {
            System.out.println("doh(float)");
            return 1.0f;
        }

        char doh(char c) {
            System.out.println("doh(string)");
            return 'd';
        }
    }

    static class Bart extends Homer {
        float doh(float f) {
            System.out.println("doh(float)");
            return 1.0f;
        }
    }

    public static void main(String[] args) {
        Bart b = new Bart();
        b.doh('x');
        b.doh(1);
        b.doh(1.0f);
    }
}
