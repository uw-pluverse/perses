



import java.util.EnumSet;
import java.util.Set;
import javax.lang.model.SourceVersion;
import javax.tools.Tool;
import javax.tools.ToolProvider;
import static javax.lang.model.SourceVersion.*;

public class T6395981 {
    public static void main(String... args) {
        Tool compiler = ToolProvider.getSystemJavaCompiler();
        Set<SourceVersion> expected = EnumSet.noneOf(SourceVersion.class);
        for (String arg : args)
            expected.add(SourceVersion.valueOf(arg));
        Set<SourceVersion> found = compiler.getSourceVersions();
        Set<SourceVersion> notExpected = EnumSet.copyOf(found);
        for (SourceVersion version : expected) {
            if (!found.contains(version))
                throw new AssertionError("Expected source version not found: " + version);
            else
                notExpected.remove(version);
        }
        if (!notExpected.isEmpty())
            throw new AssertionError("Unexpected source versions: " + notExpected);
    }
}
