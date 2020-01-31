






import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.zip.CRC32;
import java.util.zip.ZipEntry;
import java.util.zip.ZipOutputStream;

public class LoadClassFromJava6CreatedJarTest {

    static final String javaHome6 = System.getProperty("java6.home");
    static final String testClasses = System.getProperty("test.classes");

    public static void main(String... args)
            throws IOException, InterruptedException {
        if (javaHome6 != null) {
            new LoadClassFromJava6CreatedJarTest().run();
        } else {
            System.out.println(
                "The test LoadClassFromJava6CreatedJarTest cannot be executed. " +
                "In order to run it you should pass an option with " +
                "this form -javaoption:-Djava6.home=\"/path/to/jdk_or_jre6\" " +
                "to jtreg.");
        }
    }

    void run() throws IOException, InterruptedException {
        File classA = new File("A.java");
        Utils.createJavaFile(classA, null);
        if (!Utils.compile("-target", "6", "-source", "6",
            classA.getAbsolutePath())) {
            throw new AssertionError("Test failed while compiling class A");
        }

        executeCommand(Arrays.asList(javaHome6 + "/bin/java", "-classpath",
            testClasses, "LoadClassFromJava6CreatedJarTest$MakeJar"));

        File classB = new File("B.java");
        Utils.createJavaFile(classB, classA);
        if (!Utils.compile("-cp", "a.jar", classB.getAbsolutePath())) {
            throw new AssertionError("Test failed while compiling class Main");
        }
    }

    void executeCommand(List<String> command)
            throws IOException, InterruptedException {
        ProcessBuilder pb = new ProcessBuilder(command).
            redirectErrorStream(true);
        Process p = pb.start();
        BufferedReader r =
            new BufferedReader(new InputStreamReader(p.getInputStream()));
        String line;
        while ((line = r.readLine()) != null) {
            System.err.println(line);
        }
        int rc = p.waitFor();
        if (rc != 0) {
            throw new AssertionError("Unexpected exit code: " + rc);
        }
    }

    static class MakeJar {
        public static void main(String[] args) throws Throwable {
            File classFile = new File("A.class");
            ZipOutputStream zos = null;
            FileInputStream fis = null;
            final int MAX = Short.MAX_VALUE * 2 + 10;
            ZipEntry ze = null;
            try {
                zos = new ZipOutputStream(new FileOutputStream("a.jar"));
                zos.setLevel(ZipOutputStream.STORED);
                zos.setMethod(ZipOutputStream.STORED);
                for (int i = 0; i < MAX ; i++) {
                    ze = new ZipEntry("X" + i + ".txt");
                    ze.setSize(0);
                    ze.setCompressedSize(0);
                    ze.setCrc(0);
                    zos.putNextEntry(ze);
                }

                
                ze = new ZipEntry("A.class");
                ze.setCompressedSize(classFile.length());
                ze.setSize(classFile.length());
                ze.setCrc(computeCRC(classFile));
                zos.putNextEntry(ze);
                fis = new FileInputStream(classFile);
                for (int c; (c = fis.read()) >= 0;) {
                    zos.write(c);
                }
            } finally {
                zos.close();
                fis.close();
            }
        }

        private static final int BUFFER_LEN = Short.MAX_VALUE * 2;

        static long getCount(long minlength) {
            return (minlength / BUFFER_LEN) + 1;
        }

        static long computeCRC(long minlength) {
            CRC32 crc = new CRC32();
            byte[] buffer = new byte[BUFFER_LEN];
            long count = getCount(minlength);
            for (long i = 0; i < count; i++) {
                crc.update(buffer);
            }
            return crc.getValue();
        }

        static long computeCRC(File inFile) throws IOException {
            byte[] buffer = new byte[8192];
            CRC32 crc = new CRC32();
            FileInputStream fis = null;
            BufferedInputStream bis = null;
            try {
                fis = new FileInputStream(inFile);
                bis = new BufferedInputStream(fis);
                int n = bis.read(buffer);
                while (n > 0) {
                    crc.update(buffer, 0, n);
                    n = bis.read(buffer);
                }
            } finally {
                bis.close();
                fis.close();
            }
            return crc.getValue();
        }
    }
}
