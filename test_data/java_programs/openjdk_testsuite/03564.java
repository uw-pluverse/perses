






import java.io.*;

public class CompileClose {
    static void writeFile(String f, String contents) throws IOException {
        PrintStream s = new PrintStream(new FileOutputStream(f));
        s.println(contents);
        s.close();
    }

    static void rm(String filename) throws Exception {
        File f = new File(filename);
        f.delete();
        if (f.exists())
            throw new Exception(filename + ": couldn't remove");
    }

    static void clean() throws Exception {
        rm("tmpCompileClose.java");
        rm("tmpCompileClose.class");
        rm("tmpCompileClose.jar");
    }

    public static void main(String args[]) throws Exception {
        try {
            clean();
            main1();
        } finally {
            clean();
        }
    }

    static void main1() throws Exception {
        writeFile("tmpCompileClose.java",
                  "public class tmpCompileClose {}");
        
        SameJVM.jar("cf", "tmpCompileClose.jar", "tmpCompileClose.java");
        System.gc(); 
        SameJVM.javac("-cp", "tmpCompileClose.jar", "tmpCompileClose.java");
        
        rm("tmpCompileClose.jar");
    }
}
