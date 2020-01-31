





public class BadBreak {
    public static void main(String [] args) {
    label:
        break label;
        System.out.println("I am correctly reached!");
    }
}
