



import java.io.File;
import java.io.IOException;
import java.util.EnumSet;
import javax.tools.*;
import javax.tools.JavaFileObject.Kind;
import javax.tools.StandardLocation;

public class T6351767 {
    public static void main(String... args) throws Exception {

        JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();
        JavaFileManager jfm = compiler.getStandardFileManager(null, null, null);

        
        try {
            jfm.list(StandardLocation.SOURCE_PATH, null, EnumSet.of(Kind.SOURCE), false);
            error("NPE not thrown");
        }
        catch (NullPointerException e) {
            
        }

        
        try {
            jfm.list(StandardLocation.SOURCE_PATH, "", null, false);
            error("NPE not thrown");
        }
        catch (NullPointerException e) {
            
        }

        
        boolean found = false;
        for (JavaFileObject jfo : jfm.list(StandardLocation.PLATFORM_CLASS_PATH,
                                           "java.lang",
                                           EnumSet.of(Kind.CLASS),
                                           false)) {
            System.err.println("found " + jfo.toUri());
            if (jfo.isNameCompatible("Object", Kind.CLASS))
                found = true;
        }
        if (!found)
            error("expected file, java/lang/Object.class, not found");

        found = false;
        
        for (JavaFileObject jfo : jfm.list(StandardLocation.PLATFORM_CLASS_PATH,
                                           "java/lang",
                                           EnumSet.of(Kind.CLASS),
                                           false)) {
            System.err.println("found " + jfo.toUri());
            if (jfo.isNameCompatible("Object", Kind.CLASS))
                found = true;
        }
        if (!found)
            error("expected file, java/lang/Object.class, not found");

    }

    static void error(String msg) {
        throw new AssertionError(msg);
    }
}
