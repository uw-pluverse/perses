



import java.io.*;
import com.sun.tools.javac.api.*;

public class T6400383 {
    public static void main(String... args) {
        File foo = new File("foo.java");
        foo.delete();

        
        JavacTool tool = JavacTool.create();
        StringStream out = new StringStream();
        tool.run(null, out, out, foo.getPath());
        check(out.toString());


        
        out.clear();
        try {
            foo.mkdir();
            tool.run(null, out, out, foo.getPath());
            check(out.toString());
        } finally {
            foo.delete();
        }
    }

    private static void check(String s) {
        System.err.println(s);
        
        
        
        
        if (s.indexOf("Exception") != -1 || s.indexOf("Error") != -1)
            throw new AssertionError("found exception");
    }

    private static class StringStream extends OutputStream {
        public void write(int i) {
            sb.append((char) i);
        }

        void clear() {
            sb.setLength(0);
        }

        public String toString() {
            return sb.toString();
        }

        private StringBuilder sb = new StringBuilder();
    }
}
