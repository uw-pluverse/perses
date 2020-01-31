

class TargetType21 {
    interface SAM1 {
        String m1(Integer n) throws Exception;
    }

    interface SAM2 {
        void m2(Integer n);
    }

    interface SAM3<R,A> {
        R m3(A n);
    }

    void call(SAM1 sam) { }
    void call(SAM2 sam) { }
    <R,A> void call(SAM3<R,A> sam) { }

    void test() {
        call(x -> { throw new Exception(); }); 
        call((Integer x) -> { System.out.println(""); }); 
        call((Integer x) -> { return (Object) null; }); 
        call(x -> { System.out.println(""); }); 
        call(x -> { return (Object) null; }); 
        call(x -> { return null; }); 
    }
}
