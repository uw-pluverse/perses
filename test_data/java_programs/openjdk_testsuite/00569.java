

public class ForbidAccessToFieldUsingSuperTest {
    class C {
        int m() { return 0; }
    }

    interface T {
        int f = 0;
        C c = null;
        default int mm() {
            return 0;
        }
    }

    interface T1 extends T {}

    class X implements T1 {
        int i = T1.super.f;        
        int j = T1.super.c.m();    

        void foo(Runnable r) {
            foo(T1.super::mm);     
        }
    }
}
