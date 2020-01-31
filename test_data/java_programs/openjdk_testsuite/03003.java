

class SourceLevelTest {
    interface I {
        default void m() { SourceLevelTest.impl(this); }
    }

    interface SAM {
        void m();
    }

    SAM s1 = () -> { };
    SAM s2 = this::m;

    static void impl(I i) {}
    void m() {}
}
