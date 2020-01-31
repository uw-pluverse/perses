



import javax.tools.*;
import java.util.*;
import java.io.*;

import static javax.tools.JavaFileObject.Kind;

public class T6340549 {
    public static void main(String... args) throws Exception {

        
        File dir = new File("temp" + args.hashCode());
        if (!dir.exists())
            dir.mkdir();
        if (!dir.isDirectory())
            throw new AssertionError("Not a directory " + dir);

        try {
            JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();
            StandardJavaFileManager jfm = compiler.getStandardFileManager(null, null, null);
            jfm.setLocation(StandardLocation.CLASS_PATH, Arrays.asList(new File(".")));

            for (JavaFileObject jfo : jfm.list(StandardLocation.CLASS_PATH,
                    "", EnumSet.of(Kind.OTHER), false)) {
                if (new File(jfo.getName()).isDirectory()) {
                    throw new AssertionError("Found directory: " + jfo);
                }
            }
        } finally {
            dir.delete(); 
        }
    }
}
