




import java.io.File;


public class T6865530 {

    public static void main(String... args) throws Exception {
        File badFile = new File("bad.exe");
        File testJar = new File("test.jar");
        File fooJava = new File("Foo.java");
        File barJava = new File("Bar.java");

        
        
        Utils.createJavaFile(fooJava);
        Utils.compile("-doe", "-verbose", fooJava.getName());
        String[] jarArgs = {
            "cvf", testJar.getAbsolutePath(), "Foo.class"
        };
        Utils.jarTool.run(jarArgs);
        Utils.cat(badFile, fooJava, testJar);

        
        Utils.createJavaFile(barJava);
        try {
            if (!Utils.compile("-doe", "-verbose", "-cp", badFile.getAbsolutePath(), "Bar.java")) {
                throw new RuntimeException("test fails javac did not compile");
            }
        } finally {
            Utils.deleteFile(badFile);
            Utils.deleteFile(testJar);
        }
    }
}

