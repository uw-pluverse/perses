



import javax.tools.StandardLocation;

public class T6418694 extends ToolTester {
    void test(String... args) {
        for (StandardLocation loc : StandardLocation.values()) {
            switch (loc) {
            case CLASS_PATH:
            case SOURCE_PATH:
            case CLASS_OUTPUT:
            case PLATFORM_CLASS_PATH:
                if (!fm.hasLocation(loc))
                    throw new AssertionError("Missing location " + loc);
                break;
            default:
                if (fm.hasLocation(loc))
                    throw new AssertionError("Extra location " + loc);
                break;
            }
        }
    }
    public static void main(String... args) {
        new T6418694().test(args);
    }
}
