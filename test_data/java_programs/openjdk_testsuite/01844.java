



import java.io.*;
import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.*;
import javax.lang.model.element.*;
import javax.tools.Diagnostic;
import javax.tools.StandardLocation;

@SupportedOptions("mode")
public class TestValidRelativeNames extends JavacTestingAbstractProcessor {
    enum Kind { READER_WRITER, INPUT_OUTPUT_STREAM };

    static final String[] validRelativeNames = {
            "foo", "foo.bar", ".foo", ".foo.bar", "foodir/bar", "foodir/.bar"
    };

    public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment roundEnv) {
        if (roundEnv.processingOver()) {
            String mode = options.get("mode");
            for (String relativeBase: validRelativeNames) {
                for (Kind kind: Kind.values()) {
                    if (mode.equals("create"))
                        testCreate(relativeBase, kind);
                    else
                        testGet(relativeBase, kind);
                }
            }
        }

        return true;
    }

    void testCreate(String relativeBase, Kind kind) {
        String relative = getRelative(relativeBase, kind);
        System.out.println("test create relative path: " + relative + ", kind: " + kind);
        try {
            switch (kind) {
                case READER_WRITER:
                    try (Writer writer = filer.createResource(
                            StandardLocation.CLASS_OUTPUT, "", relative).openWriter()) {
                        writer.write(relative);
                    }
                    break;

                case INPUT_OUTPUT_STREAM:
                    try (OutputStream out = filer.createResource(
                            StandardLocation.CLASS_OUTPUT, "", relative).openOutputStream()) {
                        out.write(relative.getBytes());
                    }
                    break;
            }
        } catch (Exception e) {
            messager.printMessage(Diagnostic.Kind.ERROR,
                    "relative path: " + relative + ", kind: " + kind + ", unexpected exception: " + e);
        }
    }

    void testGet(String relativeBase, Kind kind) {
        String relative = getRelative(relativeBase, kind);
        System.out.println("test get relative path: " + relative + ", kind: " + kind);
        try {
            switch (kind) {
                case READER_WRITER:
                    try (Reader reader = new BufferedReader(filer.getResource(
                            StandardLocation.CLASS_OUTPUT, "", relative).openReader(true))) {
                        StringBuilder sb = new StringBuilder();
                        char[] buf = new char[1024];
                        int n;
                        while ((n = reader.read(buf, 0, buf.length)) > 0)
                            sb.append(new String(buf, 0, n));
                        if (!sb.toString().equals(relative)) {
                            messager.printMessage(Diagnostic.Kind.ERROR, "unexpected content: " + sb);
                        }
                    }
                    break;

                case INPUT_OUTPUT_STREAM:
                    try (InputStream in = new DataInputStream(filer.getResource(
                            StandardLocation.CLASS_OUTPUT, "", relative).openInputStream())) {
                        StringBuilder sb = new StringBuilder();
                        byte[] buf = new byte[1024];
                        int n;
                        while ((n = in.read(buf, 0, buf.length)) > 0)
                            sb.append(new String(buf, 0, n));
                        if (!sb.toString().equals(relative)) {
                            messager.printMessage(Diagnostic.Kind.ERROR, "unexpected content: " + sb);
                        }
                    }
                    break;
            }
        } catch (Exception e) {
            messager.printMessage(Diagnostic.Kind.ERROR,
                    "relative path: " + relative + ", kind: " + kind + ", unexpected exception: " + e);
        }
    }

    String getRelative(String relativeBase, Kind kind) {
        String suffix = (kind == Kind.READER_WRITER ? "RW" : "IOS");
        return relativeBase.replace("foo", "foo" + suffix);
    }
}

