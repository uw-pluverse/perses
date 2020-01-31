



import java.io.File;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.net.URI;
import java.util.Arrays;
import javax.tools.JavaCompiler.CompilationTask;

import javax.tools.*;


public class T6378728 {
    private static class ExceptionalFileManager extends ForwardingJavaFileManager {
        public ExceptionalFileManager(JavaFileManager wrapped) {
            super(wrapped);
        }

        @Override
        public FileObject getFileForOutput(Location location,
                                           String packageName,
                                           String relativeName,
                                           FileObject sibling)
        {
            throw new IllegalArgumentException("No files for you!");
        }

        @Override
        public JavaFileObject getJavaFileForOutput(Location location,
                                                   String className,
                                                   JavaFileObject.Kind kind,
                                                   FileObject sibling)
        {
            throw new IllegalArgumentException("No files for you!");
        }
    }

    public static void main(String[] args) {
        
        JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();
        String srcdir = System.getProperty("test.src");
        File source = new File(srcdir, "T6378728.java");
        StandardJavaFileManager fm = compiler.getStandardFileManager(null, null, null);

        CompilationTask task =
            compiler.getTask(null,
                             new ExceptionalFileManager(fm),
                             null,
                             Arrays.asList("-proc:only"),
                             null,
                             fm.getJavaFileObjectsFromFiles(Arrays.asList(source)));
        if (!task.call())
            throw new RuntimeException("Unexpected compilation failure");
    }
}
