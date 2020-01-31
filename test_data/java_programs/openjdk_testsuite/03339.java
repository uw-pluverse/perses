

public class T8020689 {

    public static void main(String... args) {
        if (args.length > 0) {
            a();
        } else {
            b();
        }
    }

    static void a() {
    }

    static void b() {
        assertLine(15);
    }

    public static void assertLine(int expectedline) {
        Exception e = new Exception("expected line#: " + expectedline);
        int myline = e.getStackTrace()[2].getLineNumber();
        if( myline != expectedline) {
            throw new RuntimeException("Incorrect line number " +
                    "expected: " + expectedline +
                    ", got: " + myline, e);
        }
        System.out.format("Got expected line number %d correct %n", myline);
    }
}
