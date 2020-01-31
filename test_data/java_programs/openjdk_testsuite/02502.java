

import static com.sun.tools.classfile.TypeAnnotation.TargetType.*;


public class ClassExtends {

    @TADescriptions({
        @TADescription(annotation = "TA", type = CLASS_EXTENDS, typeIndex = -1),
        @TADescription(annotation = "TB", type = CLASS_EXTENDS, typeIndex = 1)
    })
    public String regularClass() {
        return "class Test extends @TA Object implements Cloneable, @TB Runnable {"
               + "  public void run() { } }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = CLASS_EXTENDS, typeIndex = -1,
                genericLocation = { 3, 0 }),
        @TADescription(annotation = "TB", type = CLASS_EXTENDS, typeIndex = 1,
                genericLocation  = { 3, 1 })
    })
    public String regularClassExtendsParametrized() {
        return "class Test extends HashMap<@TA String, String> implements Cloneable, Map<String, @TB String>{ } ";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = CLASS_EXTENDS, typeIndex = -1),
        @TADescription(annotation = "TB", type = CLASS_EXTENDS, typeIndex = 1)
    })
    public String abstractClass() {
        return "abstract class Test extends @TA Date implements Cloneable, @TB Runnable {"
               + "  public void run() { } }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = CLASS_EXTENDS, typeIndex = -1,
                genericLocation = { 3, 0 }),
        @TADescription(annotation = "TB", type = CLASS_EXTENDS, typeIndex = 1,
                genericLocation  = { 3, 1 })
    })
    public String abstractClassExtendsParametrized() {
        return "abstract class Test extends HashMap<@TA String, String> implements Cloneable, Map<String, @TB String>{ } ";
    }

    @TADescription(annotation = "TB", type = CLASS_EXTENDS, typeIndex = 1)
    public String regularInterface() {
        return "interface Test extends Cloneable, @TB Runnable { }";
    }

    @TADescription(annotation = "TB", type = CLASS_EXTENDS, typeIndex = 1,
            genericLocation  = { 3, 1 })
    public String regularInterfaceExtendsParametrized() {
        return "interface Test extends Cloneable, Map<String, @TB String>{ } ";
    }

    @TADescription(annotation = "TB", type = CLASS_EXTENDS, typeIndex = 1)
    public String regularEnum() {
        return "enum Test implements Cloneable, @TB Runnable { TEST; public void run() { } }";
    }

    @TADescription(annotation = "TB", type = CLASS_EXTENDS, typeIndex = 1,
            genericLocation  = { 3, 0 })
    public String regularEnumExtendsParametrized() {
        return
            "enum Test implements Cloneable, Comparator<@TB String> { TEST;  "
            + "public int compare(String a, String b) { return 0; }}";
    }

}
