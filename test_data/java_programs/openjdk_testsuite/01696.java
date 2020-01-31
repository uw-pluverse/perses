


public class T6614974<T> {

    private T n;

    public void error() {
        T6614974<Integer> val = new T6614974<Integer>();
        val.n = 0;
        Integer.toString(val.n++);
    }

    public static void main(String[] args) {
        T6614974.class.getMethods();
    }
}
