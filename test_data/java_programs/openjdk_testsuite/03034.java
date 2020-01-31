



class TargetType07 {

    public interface SAM1 { String m(); }
    public interface SAM2 { Comparable<?> m(); }

    public static void call(SAM1 s) { }
    public static void call(SAM2 s) { }

    public static void main(String[] args) {
        call((SAM1)()-> "Hello!" );
    }
}
