

public class VarargsAmbiguityCrashTest {
    void m1() {
        m2(null, new Exception());
    }

    void m2(Long l) {}

    void m2(Exception... exception) {}

    void m2(Long l, Exception... exception) {}
}
