



class TargetType07 {

    public interface SAM1<X> { X m(); }
    public interface SAM2<X> { X m(); }

    public static <X> void call(SAM1<X> s) { }
    public static <X> void call(SAM2<X> s) { }

    public static void main(String[] args) {
        call((SAM1<Integer>)()-> 1 );
    }
}
