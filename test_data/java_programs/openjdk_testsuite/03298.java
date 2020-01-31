


public class InaccessibleMref02 {
    interface SAM {
        void m();
    }

    public static void main(String[] args) {
        p1.C c = new p1.C();
        SAM s = c::m;
        s.m();
    }
}
