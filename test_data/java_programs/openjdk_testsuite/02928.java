

class TargetType23 {

    interface Sam0 {
        void m();
    }

    interface Sam1 {
        int m();
    }

    interface Sam2 {
        String m();
    }

    interface Sam3<A> {
        A m();
    }


    void call(Sam0 s) { }
    void call(Sam1 s) { }
    void call(Sam2 s) { }
    <Z> void call(Sam3<Z> s) { }

    void call2(Sam0 s) { }
    void call2(Sam2 s) { }
    <Z> void call2(Sam3<Z> s) { }

    void test() {
        call(()-> { throw new RuntimeException(); }); 
        call2(()-> { throw new RuntimeException(); }); 
    }
}
