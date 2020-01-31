



import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.zip.CRC32;
import java.util.zip.ZipEntry;
import java.util.zip.ZipOutputStream;

public class T6836682 {

    private static final long GIGA = 1024 * 1024 * 1024;
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
            Utils.close(bis);
            Utils.close(fis);
        }
        return crc.getValue();
    }

    static void createLargeFile(OutputStream os, long minlength) throws IOException {
        byte[] buffer = new byte[BUFFER_LEN];
        long count = getCount(minlength);
        for (long i = 0; i < count; i++) {
            os.write(buffer);
        }
        os.flush();
    }

    static void createJarWithLargeFile(File jarFile, File javaFile,
            long minlength) throws IOException {
        Utils.createClassFile(javaFile, null, true);
        File classFile = new File(Utils.getClassFileName(javaFile));
        ZipOutputStream zos = null;
        BufferedOutputStream bos = null;
        FileInputStream fis = null;
        try {
            zos = new ZipOutputStream(new FileOutputStream(jarFile));
            zos.setLevel(ZipOutputStream.STORED);
            zos.setMethod(0);
            bos = new BufferedOutputStream(zos);

            ZipEntry ze = new ZipEntry("large.data");
            ze.setCompressedSize(getCount(minlength) * BUFFER_LEN);
            ze.setSize(getCount(minlength) * BUFFER_LEN);
            ze.setCrc(computeCRC(minlength));
            ze.setMethod(ZipEntry.STORED);
            zos.putNextEntry(ze);
            createLargeFile(bos, minlength);

            ze = new ZipEntry(classFile.getName());
            ze.setCompressedSize(classFile.length());
            ze.setSize(classFile.length());
            ze.setCrc(computeCRC(classFile));
            ze.setMethod(ZipEntry.STORED);
            zos.putNextEntry(ze);
            fis = new FileInputStream(classFile);
            Utils.copyStream(fis, bos);
            bos.flush();
            zos.closeEntry();
        } finally {
            Utils.close(bos);
            Utils.close(zos);
            Utils.close(fis);
        }
        
        new File(Utils.getClassFileName(javaFile)).delete();
    }

    static void createLargeJar(File jarFile, File javaFile) throws IOException {
        File classFile = new File(Utils.getClassFileName(javaFile));
        Utils.createClassFile(javaFile, null, true);
        ZipOutputStream zos = null;
        FileInputStream fis = null;
        final int MAX = Short.MAX_VALUE * 2 + 10;
        ZipEntry ze = null;
        try {
            zos = new ZipOutputStream(new FileOutputStream(jarFile));
            zos.setLevel(ZipOutputStream.STORED);
            zos.setMethod(ZipOutputStream.STORED);
            for (int i = 0; i < MAX ; i++) {
                ze = new ZipEntry("X" + i + ".txt");
                ze.setSize(0);
                ze.setCompressedSize(0);
                ze.setCrc(0);
                zos.putNextEntry(ze);
            }

            
            ze = new ZipEntry(classFile.getName());
            ze.setCompressedSize(classFile.length());
            ze.setSize(classFile.length());
            ze.setCrc(computeCRC(classFile));
            zos.putNextEntry(ze);
            fis = new FileInputStream(classFile);
            Utils.copyStream(fis, zos);
        } finally {
            Utils.close(zos);
            Utils.close(fis);
        
        new File(Utils.getClassFileName(javaFile)).delete();
    }
    }

    
    public static void testScenarioA(String... args) throws IOException {
        File largeJar = new File("large.jar");
        File javaFile = new File("Foo.java");
        createLargeJar(largeJar, javaFile);

        File testFile = new File("Bar.java");
        try {
            Utils.createJavaFile(testFile, javaFile);
            if (!Utils.compile("-doe", "-verbose", "-cp",
                    largeJar.getAbsolutePath(), testFile.getAbsolutePath())) {
                throw new IOException("test failed");
            }
        } finally {
            Utils.deleteFile(largeJar);
        }
    }

    
    public static void testScenarioB(String... args) throws IOException {
        final File largeJar = new File("huge.jar");
        final File javaFile = new File("Foo.java");

        final Path path = largeJar.getAbsoluteFile().getParentFile().toPath();
        final long available = Files.getFileStore(path).getUsableSpace();
        final long MAX_VALUE = 0xFFFF_FFFFL;

        final long absolute  = MAX_VALUE + 1L;
        final long required  = (long)(absolute * 1.1); 
        System.out.println("\tavailable: " + available / GIGA + " GB");
        System.out.println("\trequired: " + required / GIGA + " GB");

        if (available > required) {
            createJarWithLargeFile(largeJar, javaFile, absolute);
            File testFile = new File("Bar.java");
            Utils.createJavaFile(testFile, javaFile);
            try {
                if (!Utils.compile("-doe", "-verbose", "-cp",
                        largeJar.getAbsolutePath(), testFile.getAbsolutePath())) {
                    throw new IOException("test failed");
                }
            } finally {
                Utils.deleteFile(largeJar);
            }
        } else {
            System.out.println("Warning: testScenarioB passes vacuously," +
                    " requirements exceeds available space");
        }
    }

    public static void main(String... args) throws IOException {
        testScenarioA();
        System.out.println("testScenarioA: PASS");
        if (Boolean.getBoolean("T6836682.testScenarioB")) {
            testScenarioB();
            System.out.println("testScenarioB: PASS");
        } else {
            System.out.println("Warning: testScenarioB, large file test skipped");
        }
    }
}
