



public class TestCast6979683_GOOD {
    public static void main(String... av) {
        bugReportExample();
        for (int x = -1; x <= 2; x++) {
            zconvTests(x != 0);
            iconvTests(x);
            bconvTests((byte)x);
            cconvTests((char)x);
        }
        System.out.println("Successfully ran "+tests+" tests.");
    }

    static int tests;
    static void assertEquals(Object x, Object y) {
        if (!x.equals(y)) {
            throw new RuntimeException("assertEquals: "+x+" != "+y);
        }
        ++tests;
    }

    static void bugReportExample() {
  {} 
  Object x = (Object)1;
  int y = (int)x;
  {} 
    }

    static boolean zconv1(Boolean o) { return o; }
    static boolean zconv2(Object o) { return (boolean)o; }
    static boolean zconv3(Comparable<Boolean> o) { return (boolean)o; }

    static void zconvTests(boolean x) {
        assertEquals(x, zconv1(x));
        assertEquals(x, zconv2(x));
        assertEquals(x, zconv3(x));
    }

    static int iconv1(Integer o) { return o; }
    static int iconv2(Object o) { return (int)o; }
    static int iconv3(java.io.Serializable o) { return (int)o; }
    static int iconv4(Number o) { return (int)o; }
    static int iconv5(Comparable<Integer> o) { return (int)o; }

    static void iconvTests(int x) {
        assertEquals(x, iconv1(x));
        assertEquals(x, iconv2(x));
        assertEquals(x, iconv3(x));
        assertEquals(x, iconv4(x));
        assertEquals(x, iconv5(x));
    }

    static float bconv1(Byte o) { return o; }  
    static float bconv2(Object o) { return (byte)o; }
    static float bconv3(java.io.Serializable o) { return (byte)o; }
    static float bconv4(Number o) { return (byte)o; }

    static void bconvTests(byte x) {
        float xf = x;
        assertEquals(xf, bconv1(x));
        assertEquals(xf, bconv2(x));
        assertEquals(xf, bconv3(x));
        assertEquals(xf, bconv4(x));
    }

    static float cconv1(Character o) { return o; }  
    static float cconv2(Object o) { return (char)o; }
    static float cconv3(java.io.Serializable o) { return (char)o; }
    static float cconv4(Comparable<Character> o) { return (char)o; }

    static void cconvTests(char x) {
        float xf = x;
        assertEquals(xf, cconv1(x));
        assertEquals(xf, cconv2(x));
        assertEquals(xf, cconv3(x));
        assertEquals(xf, cconv4(x));
    }

}
