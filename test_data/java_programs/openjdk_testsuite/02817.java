
public class T8062747 {

    public interface Throwing<Y extends Exception> {
        void canThrow() throws Y;
    }

    public static <Y extends Exception> void wrap(Throwing<Y> action) {
    }

    public static void invoke(String a) {
        Runnable r = new Runnable() {
            @Override
            public void run() {
                wrap(() -> System.out.println(a));
            }
        };
    }
}
