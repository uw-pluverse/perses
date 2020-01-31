



import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.io.RandomAccessFile;
import java.nio.ByteBuffer;
import java.nio.MappedByteBuffer;
import java.nio.channels.FileChannel;


public class T6567415 {
    final static String TEST_FILE_NAME = "Bar";
    final static String TEST_JAVA = TEST_FILE_NAME + ".java";
    final static String TEST_CLASS = TEST_FILE_NAME + ".class";

    final static String TEST2_FILE_NAME = "Foo";
    final static String TEST2_JAVA = TEST2_FILE_NAME + ".java";

    

    final static int BAD_FILE_LENGTH =
            com.sun.tools.javac.jvm.ClassReader.INITIAL_BUFFER_SIZE;

    static void createClassFile() throws IOException {
        FileOutputStream fos = null;
        try {
            fos = new FileOutputStream(TEST_JAVA);
            PrintStream ps = new PrintStream(fos);
            ps.println("public class " + TEST_FILE_NAME + " {}");
        } finally {
            fos.close();
        }
        String cmds[] = {TEST_JAVA};
        com.sun.tools.javac.Main.compile(cmds);
    }

    static void enlargeClassFile() throws IOException {
        File f = new File(TEST_CLASS);
        if (!f.exists()) {
            System.out.println("file not found: " + TEST_CLASS);
            System.exit(1);
        }
        File tfile = new File(f.getAbsolutePath() + ".tmp");
        f.renameTo(tfile);

        RandomAccessFile raf = null;
        FileChannel wfc = null;

        FileInputStream fis = null;
        FileChannel rfc = null;

        try {
            raf =  new RandomAccessFile(f, "rw");
            wfc = raf.getChannel();

            fis = new FileInputStream(tfile);
            rfc = fis.getChannel();

            ByteBuffer bb = MappedByteBuffer.allocate(BAD_FILE_LENGTH);
            rfc.read(bb);
            bb.rewind();
            wfc.write(bb);
            wfc.truncate(BAD_FILE_LENGTH);
        } finally {
            wfc.close();
            raf.close();
            rfc.close();
            fis.close();
        }
        System.out.println("file length = " + f.length());
    }

    static void createJavaFile() throws IOException {
        FileOutputStream fos = null;
        try {
            fos = new FileOutputStream(TEST2_JAVA);
            PrintStream ps = new PrintStream(fos);
            ps.println("public class " + TEST2_FILE_NAME +
                    " {" + TEST_FILE_NAME + " b = new " +
                    TEST_FILE_NAME  + " ();}");
        } finally {
            fos.close();
        }
    }

    public static void main(String... args) throws Exception {
        createClassFile();
        enlargeClassFile();
        createJavaFile();
        Thread t = new Thread () {
            @Override
            public void run() {
                String cmds[] = {"-verbose", "-cp", ".", TEST2_JAVA};
                int ret = com.sun.tools.javac.Main.compile(cmds);
                System.out.println("test compilation returns: " + ret);
            }
        };
        t.start();
        t.join(1000*60);
        System.out.println(t.getState());
        if (t.isAlive()) {
            throw new RuntimeException("Error: compilation is looping");
        }
    }
}
