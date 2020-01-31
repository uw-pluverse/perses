



import java.util.EnumMap;

public class T6846972 {

    enum Suit {
        CLUBS, DIAMONDS;
    }

    static Object [] array = {
        Suit.CLUBS, "value1",
        Suit.DIAMONDS, "value2"
    };

    static void test() {
        EnumMap map = new EnumMap(Suit.class);
        map.put(array[0], array[1]);
    }
}
