



import java.lang.annotation.*;
import java.util.Formatter;
import java.util.Set;
import java.util.regex.*;
import javax.annotation.processing.*;
import javax.lang.model.element.*;
import static javax.lang.model.util.ElementFilter.*;
import static javax.tools.Diagnostic.Kind.*;


@SupportedOptions("expectedMethodCount")
public class TestExecutableElement extends JavacTestingAbstractProcessor implements ProviderOfDefault {
    private int seenMethods = 0;
    @IsDefault(false)
    public boolean process(Set<? extends TypeElement> annotations,
                           RoundEnvironment roundEnv) {
        if (!roundEnv.processingOver()) {
            for (Element element : roundEnv.getRootElements()) {
                for (ExecutableElement method : methodsIn(element.getEnclosedElements())) {
                    checkIsDefault(method);
                    seenMethods++;
                }
            }
        } else {
            String expectedMethodCountStr = processingEnv.getOptions().get("expectedMethodCount");
            if (expectedMethodCountStr == null) {
                messager.printMessage(ERROR, "No expected method count specified.");
            } else {
                int expectedMethodCount = Integer.parseInt(expectedMethodCountStr);

                if (seenMethods != expectedMethodCount) {
                    messager.printMessage(ERROR, "Wrong number of seen methods: " + seenMethods);
                }
            }
        }
        return true;
    }

    @IsDefault(false)
    void checkIsDefault(ExecutableElement method) {
        System.out.println("Testing " + method);
        IsDefault expectedIsDefault = method.getAnnotation(IsDefault.class);

        boolean expectedDefault = (expectedIsDefault != null) ?
            expectedIsDefault.value() :
            false;

        boolean methodIsDefault = method.isDefault();

        if (expectedDefault) {
            if (!method.getModifiers().contains(Modifier.DEFAULT)) {
                messager.printMessage(ERROR,
                                      "Modifier \"default\" not present as expected.",
                                      method);
            }

            
            java.io.Writer stringWriter = new java.io.StringWriter();
            eltUtils.printElements(stringWriter, method);
            Pattern p = Pattern.compile(expectedIsDefault.expectedTextRegex(), Pattern.DOTALL);

            if (! p.matcher(stringWriter.toString()).matches()) {
                messager.printMessage(ERROR,
                                      new Formatter().format("Unexpected printing ouptput:%n\tgot %s,%n\texpected pattern %s.",
                                                             stringWriter.toString(),
                                                             expectedIsDefault.expectedTextRegex()).toString(),
                                      method);
            }

            System.out.println("\t" + stringWriter.toString());

        } else {
            if (method.getModifiers().contains(Modifier.DEFAULT)) {
                messager.printMessage(ERROR,
                                      "Modifier \"default\" present when not expected.",
                                      method);
            }
        }

        if (methodIsDefault != expectedDefault) {
            messager.printMessage(ERROR,
                                  new Formatter().format("Unexpected Executable.isDefault result: got ``%s'', expected ``%s''.",
                                                         expectedDefault,
                                                         methodIsDefault).toString(),
                                  method);
        }
    }
}


@Retention(RetentionPolicy.RUNTIME)
@Target(ElementType.METHOD)
@interface IsDefault {
    boolean value();
    String expectedTextRegex() default "";
}


interface ProviderOfDefault {
    @IsDefault(false)
    boolean process(Set<? extends TypeElement> annotations,
                    RoundEnvironment roundEnv);

    @IsDefault(value=true, expectedTextRegex="\\s*@IsDefault\\(.*\\)\\s*default strictfp void quux\\(\\);\\s*$")
    default strictfp void quux() {};
    @IsDefault(false)
    static void statik() {}
}
