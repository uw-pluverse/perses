



import java.io.*;
import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.*;
import javax.lang.model.element.*;
import javax.tools.Diagnostic;
import javax.tools.StandardLocation;

public class TestInvalidRelativeNames extends JavacTestingAbstractProcessor {
    enum Kind { CREATE_WRITER, GET_READER, CREATE_OUTPUT_STREAM, GET_INPUT_STREAM };

    static final String[] invalidRelativeNames = {
            "/boo", "goo/../hoo", "./ioo", ""
    };

    public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment roundEnv) {
        if (roundEnv.processingOver()) {
            for (String relative: invalidRelativeNames) {
                for (Kind kind: Kind.values()) {
                    test(relative, kind);
                }
            }
        }
        return true;
    }

    void test(String relative, Kind kind) {
        System.out.println("test relative path: " + relative + ", kind: " + kind);
        try {
            switch (kind) {
                case CREATE_WRITER:
                    Writer writer = filer.createResource(
                            StandardLocation.SOURCE_OUTPUT, "", relative).openWriter();
                    writer.close();
                    break;

                case GET_READER:
                    Reader reader = filer.getResource(
                            StandardLocation.SOURCE_OUTPUT, "", relative).openReader(true);
                    reader.close();
                    break;

                case CREATE_OUTPUT_STREAM:
                    OutputStream out = filer.createResource(
                            StandardLocation.SOURCE_OUTPUT, "", relative).openOutputStream();
                    out.close();
                    break;

                case GET_INPUT_STREAM:
                    InputStream in = filer.createResource(
                            StandardLocation.SOURCE_OUTPUT, "", relative).openInputStream();
                    in.close();
                    break;
            }
        } catch (IllegalArgumentException expected) {
            System.out.println("expected exception thrown: " + expected);
            return;
        } catch (Exception e) {
            messager.printMessage(Diagnostic.Kind.ERROR,
                    "relative path: " + relative + ", kind: " + kind + ", unexpected exception: " + e);
            return;
        }
        messager.printMessage(Diagnostic.Kind.ERROR,
                "relative path: " + relative + ", kind: " + kind + ", no exception thrown");
    }
}

