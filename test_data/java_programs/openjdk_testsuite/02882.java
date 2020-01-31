



import pkg.PublicDerived8143647;

public class MethodReference75 {
    public static void main(String[] args) {
        if (java.util.Arrays
                .asList(new PublicDerived8143647())
                .stream()
                .map(PublicDerived8143647::getX)
                .findFirst()
                .get()
                .equals("PackagePrivateBase"))
            System.out.println("OK");
        else
            throw new AssertionError("Unexpected output");
    }
}
