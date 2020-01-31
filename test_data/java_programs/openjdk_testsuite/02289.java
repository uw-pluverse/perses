



import java.nio.*;
import java.io.*;
import java.nio.channels.*;
import com.sun.tools.javac.api.JavacTaskImpl;
import com.sun.tools.javac.jvm.ClassReader.BadClassFile;
import com.sun.tools.javac.main.JavaCompiler;
import javax.tools.ToolProvider;

public class T6330997 {
    public static void main(String... args) {
        increaseMajor("T1.class", 1);
        increaseMajor("T2.class", 2);
        javax.tools.JavaCompiler tool = ToolProvider.getSystemJavaCompiler();
        JavacTaskImpl task = (JavacTaskImpl)tool.getTask(null, null, null, null, null, null);
        JavaCompiler compiler = JavaCompiler.instance(task.getContext());
        try {
            compiler.resolveIdent("T1").complete();
        } catch (Exception e) {
            e.printStackTrace();
            throw new RuntimeException("Failed: unexpected exception while reading class T1");
        }
        try {
            compiler.resolveIdent("T2").complete();
        } catch (BadClassFile e) {
            System.err.println("Passed: expected completion failure " + e.getClass().getName());
            return;
        } catch (Exception e) {
            e.printStackTrace();
            throw new RuntimeException("Failed: unexpected exception while reading class T2");
        }
        throw new RuntimeException("Failed: no error reported");
    }

    
    static void increaseMajor(String cfile, int delta) {
        try {
            RandomAccessFile cls = new RandomAccessFile(
                    new File(System.getProperty("test.classes", "."), cfile), "rw");
            FileChannel fc = cls.getChannel();
            ByteBuffer rbuf = ByteBuffer.allocate(2);
            fc.read(rbuf, 6);
            ByteBuffer wbuf = ByteBuffer.allocate(2);
            wbuf.putShort(0, (short)(rbuf.getShort(0) + delta));
            fc.write(wbuf, 6);
            fc.force(false);
            cls.close();
         } catch (Exception e){
            e.printStackTrace();
            throw new RuntimeException("Failed: unexpected exception");
         }
     }
}
