


public class ExerciseDependency {
    public static void main(String... args) {
        foo.WrittenAfterProcessing wap = new foo.WrittenAfterProcessing();
        java.lang.Package pkg = wap.getClass().getPackage();
        Deprecated d = pkg.getAnnotation(Deprecated.class);
        if (d == null)
            throw new RuntimeException();
    }
}
