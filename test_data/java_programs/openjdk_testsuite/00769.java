



import java.util.*;
import javax.tools.*;
import static javax.tools.StandardLocation.*;
import static javax.tools.JavaFileObject.Kind.*;

public class T6400207 {
    static void testList(JavaFileManager fm,
                    JavaFileManager.Location location,
                    String packageName,
                    Set<JavaFileObject.Kind> kinds) throws Exception {
        boolean expectNpe =
            location == null ||
            packageName == null ||
            kinds == null;
        try {
            fm.list(location, packageName, kinds, false);
            if (expectNpe) {
                String message = "NullPointerException not thrown";
                if (location == null)
                    throw new AssertionError(message + " (location is null)");
                if (packageName == null)
                    throw new AssertionError(message + " (packageName is null)");
                if (kinds == null)
                    throw new AssertionError(message + " (kinds is null)");
                throw new AssertionError(message);
            }
        } catch (NullPointerException e) {
            if (!expectNpe)
                throw e;
        }
    }

    public static void main(String... args) throws Exception {
        JavaFileManager fm =
            ToolProvider.getSystemJavaCompiler().getStandardFileManager(null, null, null);
        JavaFileManager.Location bogusLocation = locationFor("bogus");
        JavaFileManager.Location knownLocation = CLASS_PATH;
        String packageName = "java.lang";
        Set<JavaFileObject.Kind> kinds = EnumSet.of(CLASS);

        for (StandardLocation location : StandardLocation.values()) {
            if (location != locationFor(location.getName()))
                throw new AssertionError(location + " != locationFor(" +
                                         location.getName() + ")");
        }

        testList(fm, null, null, null);
        testList(fm, bogusLocation, packageName, kinds);
        testList(fm, knownLocation, packageName, kinds);
        testList(fm, null, packageName, kinds);
        testList(fm, knownLocation, null, kinds);
        testList(fm, knownLocation, packageName, null);
        testList(fm, bogusLocation, null, kinds);
        testList(fm, bogusLocation, packageName, null);

        System.err.println("Test PASSED.");
    }
}
