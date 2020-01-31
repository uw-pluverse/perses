



public class Attach {
    public static void main(String[] args) {
        Attach.class.getClassLoader().
            setClassAssertionStatus("Attach", false);
        if (V.assertsEnabled())
            throw new Error("failed 4478095.1");
        if (!U.correct)
            throw new Error("failed 4478095.2");
    }
    static class U {
        static boolean correct = V.assertsEnabled();
    }
    static class V extends U {
        static boolean assertsEnabled() {
            boolean enabled = false;
            assert enabled=true;
            return enabled;
        }
    }
}
