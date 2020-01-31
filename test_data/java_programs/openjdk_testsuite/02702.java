



import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Random;

import com.sun.tools.javac.Main;

public class T6558476 {
    private static File copyFileTo(File file, File directory) throws IOException {
        File newFile = new File(directory, file.getName());
        FileInputStream fis = null;
        FileOutputStream fos = null;
        try {
            fis = new FileInputStream(file);
            fos = new FileOutputStream(newFile);
            byte buff[] = new byte[1024];
            int val;
            while ((val = fis.read(buff)) > 0)
                fos.write(buff, 0, val);
        } finally {
            if (fis != null)
                fis.close();
            if (fos != null)
                fos.close();
        }
        return newFile;
    }

    private static String generateJavaClass(String className) {
        StringBuffer sb = new StringBuffer();
        sb.append("import sun.net.spi.nameservice.dns.DNSNameService;\n");
        sb.append("public class ");
        sb.append(className);
        sb.append(" {\n");
        sb.append("  public void doStuff() {\n");
        sb.append("    DNSNameService dns = null;\n");
        sb.append("  }\n");
        sb.append("}\n");
        return sb.toString();
    }

    public static void main(String[] args) throws IOException {
        File javaHomeDir = new File(System.getProperty("java.home"));
        File outputDir = new File("outputDir" + new Random().nextInt(65536));
        outputDir.mkdir();
        outputDir.deleteOnExit();

        File dnsjarfile = new File(javaHomeDir, "lib" + File.separator + "ext" + File.separator + "dnsns.jar");
        File tmpJar = copyFileTo(dnsjarfile, outputDir);
        String className = "TheJavaFile";
        File javaFile = new File(outputDir, className + ".java");
        javaFile.deleteOnExit();
        FileOutputStream fos = new FileOutputStream(javaFile);
        fos.write(generateJavaClass(className).getBytes());
        fos.close();

        int rc = Main.compile(new String[]{"-d", outputDir.getPath(),
                    "-classpath",
                    tmpJar.getPath(),
                    javaFile.getAbsolutePath()});
        if (rc != 0) {
            throw new Error("Couldn't compile the file (exit code=" + rc + ")");
        }

        if (tmpJar.delete()) {
            System.out.println("jar file successfully deleted");
        } else {
            throw new Error("Error deleting file \"" + tmpJar.getPath() + "\"");
        }
    }
}
