



import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

import com.sun.tools.javac.sym.Profiles;

public class ProfileTest {
    public static void main(String... args) throws Exception {
        new ProfileTest().run();
    }

    public void run() throws Exception {
        test("A");
        test("B");

        if (errors > 0)
            throw new Exception(errors + " occurred");
    }

    void test(String base) throws IOException {
        System.err.println("test " + base);
        File profileDesc = createFiles(base);
        checkProfile(profileDesc, base);
    }

    void checkProfile(File profileDesc, String base) throws IOException {
        Profiles p = Profiles.read(profileDesc);
        for (int i = 0; i < p.getProfileCount(); i++) {
            System.err.println(p.getPackages(i));
            for (String pkg: p.getPackages(i)) {
                if (!pkg.endsWith(base))
                    error("unexpected package " + pkg + " for profile " + i);
            }
        }
    }

    File createFiles(String base) throws IOException {
        File baseDir = new File(base);
        baseDir.mkdirs();
        for (int p = 1; p <= 4; p++) {
            String pkg = "pkg" + p + base;
            File pkgDir = new File(baseDir, pkg);
            pkgDir.mkdirs();
            File clssFile = new File(pkgDir, pkg + "Class.java");
            try (PrintWriter out = new PrintWriter(new FileWriter(clssFile))) {
                out.println("package " + pkgDir.getName() + ";");
                out.println("class " + clssFile.getName().replace(".java", ""));
            }
        }

        File profileDesc = new File(baseDir, "profiles" + base + ".txt");
        try (PrintWriter out = new PrintWriter(new FileWriter(profileDesc))) {
            for (int p = 1; p <= 4; p++) {
                String pkg = "pkg" + p + base;
                createPackage(baseDir, pkg, "Pkg" + p + base + "Class");
                out.println("PROFILE_" + p + "_RTJAR_INCLUDE_PACKAGES := " + pkg);
                out.println("PROFILE_" + p + "_RTJAR_INCLUDE_TYPES :=");
                out.println("PROFILE_" + p + "_RTJAR_EXCLUDE_TYPES :=");
                out.println("PROFILE_" + p + "_INCLUDE_METAINF_SERVICES := ");
            }
        }

        return profileDesc;
    }

    void createPackage(File baseDir, String pkg, String... classNames) throws IOException {
        File pkgDir = new File(baseDir, pkg);
        pkgDir.mkdirs();
        for (String className: classNames) {
            File clssFile = new File(pkgDir, className + ".java");
            try (PrintWriter out = new PrintWriter(new FileWriter(clssFile))) {
                out.println("package " + pkg + ";");
                out.println("public class " + className + " { }");
            }
        }
    }

    void error(String msg) {
        System.err.println("Error: " + msg);
        errors++;
    }

    int errors;
}
