



import javax.lang.model.SourceVersion;
import static javax.lang.model.SourceVersion.*;


public class TestSourceVersion {
    public static void main(String... args) {
        if (SourceVersion.latest() != RELEASE_8 ||
            SourceVersion.latestSupported() != RELEASE_8)
            throw new RuntimeException("Unexpected release value(s) found:\n" +
                                       "latest:\t" + SourceVersion.latest() + "\n" +
                                       "latestSupported:\t" + SourceVersion.latestSupported());
    }
}
