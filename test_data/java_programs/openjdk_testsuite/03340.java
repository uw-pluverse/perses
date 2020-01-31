

public class T7024096 {
    private static final int START = 14; 
    public static void main(String[] args) {
        T7024096 m = new T7024096();
        m.nest(START);
        m.nest(START + 1, m.nest(START + 1), m.nest(START + 1),
            m.nest(START + 2),
            m.nest(START + 3, m.nest(START + 3)));
    }

    public T7024096 nest(int expectedline, T7024096... args) {
        Exception e = new Exception("expected line#: " + expectedline);
        int myline = e.getStackTrace()[1].getLineNumber();
        if( myline != expectedline) {
            throw new RuntimeException("Incorrect line number " +
                    "expected: " + expectedline +
                    ", got: " + myline, e);
        }
        System.out.format("Got expected line number %d correct %n", myline);
        return null;
    }
}
