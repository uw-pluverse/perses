



import java.io.File;
import java.io.PrintWriter;
import javax.tools.Tool;
import javax.tools.ToolProvider;

public class T6350124 {
    public static void main(String[] args) {
        String classpath = System.getProperty("java.class.path");
        File srcDir = new File(System.getProperty("test.src"));

        
        mkCleanDir(new File("aClasses"));
        mkCleanDir(new File("newClasses"));
        mkCleanDir(new File("newSrc"));

        
        compile("-cp", classpath,
                "-d", "aClasses", path(srcDir, "HelloWorldAP.java"));

        
        compile("-cp", classpath,
                "-sourcepath", srcDir.getPath(),
                "-d", "newClasses",
                "-s", "newSrc",
                "-processorpath", "aClasses",
                "-processor", "HelloWorldAP", 
                "-proc:only",
                path(srcDir, "Marked.java"));

        File hw = new File("newSrc", "HelloWorld.java");
        if (!hw.exists())
            throw new AssertionError("generated source file not found");

        File dc = new File("newClasses", "HelloWorldAP.class");
        if (!dc.exists())
            throw new AssertionError("generated class file not found");
    }

    

    
    static void clean(File file) {
        if (!file.exists())
            return;
        if (file.isDirectory()) {
            for (File f: file.listFiles())
                clean(f);
        }
        file.delete();
    }

    static void mkCleanDir(File dir) {
        clean(dir);
        dir.mkdirs();
    }

    
    static void compile(String... args) {
        StringBuffer sb = new StringBuffer("compile:");
        for (String a: args)
            sb.append(' ').append(a);
        System.err.println(sb);

        Tool t = ToolProvider.getSystemJavaCompiler();
        int rc = t.run(System.in, System.out, System.err, args);
        System.out.flush();
        System.err.flush();
        if (rc != 0)
            throw new Error("compilation failed");
    }

    static String path(File dir, String name) {
        return new File(dir, name).getPath();
    }
}
