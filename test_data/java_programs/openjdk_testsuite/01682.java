


public class T6816548 {

    public static void main(String[] args) {
        testInt();
        testShort();
        testByte();
        testChar();
    }

    public static void testInt() {
        final int fi = 0;
        Byte b = fi;
        Short s = fi;
        Character c = fi;
    }

    public static void testShort() {
        final short fs = 0;
        Byte b = fs;
        Short s = fs;
        Character c = fs;
    }

    public static void testByte() {
        final byte fb = 0;
        Byte b = fb;
        Short s = fb;
        Character c = fb;
    }

    public static void testChar() {
        final char fc = '0';
        Byte b = fc;
        Short s = fc;
        Character c = fc;
    }
}
