


import pkg.B;
public class MethodReferencePackagePrivateQualifier {
    public static void main(String... args) {
        pkg.B.m();
        Runnable r = pkg.B::m;
        r.run();
        r = B::m;
        r.run();
        if (!pkg.B.result.equals("A.m()A.m()A.m()"))
            throw new AssertionError("Incorrect result");
    }
}
