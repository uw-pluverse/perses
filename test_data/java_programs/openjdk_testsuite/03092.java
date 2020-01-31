
class EffectivelyFinalTest {

    void m1(int x) {
        int y = 1;
        new Object() { { System.out.println(x+y); } }; 
    }

    void m2(int x) {
        int y;
        y = 1;
        new Object() { { System.out.println(x+y); } }; 
    }

    void m3(int x, boolean cond) {
        int y;
        if (cond) y = 1;
        new Object() { { System.out.println(x+y); } }; 
    }

    void m4(int x, boolean cond) {
        int y;
        if (cond) y = 1;
        else y = 2;
        new Object() { { System.out.println(x+y); } }; 
    }

    void m5(int x, boolean cond) {
        int y;
        if (cond) y = 1;
        y = 2;
        new Object() { { System.out.println(x+y); } }; 
    }

    void m6(int x) {
        new Object() { { System.out.println(x+1); } }; 
        x++; 
    }

    void m7(int x) {
        new Object() { { System.out.println(x=1); } }; 
    }

    void m8() {
        int y;
        new Object() { { System.out.println(y=1); } }; 
    }
}
