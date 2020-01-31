

import static com.sun.tools.classfile.TypeAnnotation.TargetType.*;


public class MethodThrows {

    @TADescriptions({
        @TADescription(annotation = "TA", type = THROWS, typeIndex = 0),
        @TADescription(annotation = "TB", type = THROWS, typeIndex = 2)
    })
    public String regularMethod() {
        return "class Test { void test() throws @TA RuntimeException, IllegalArgumentException, @TB Exception { } }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = THROWS, typeIndex = 0),
        @TADescription(annotation = "TB", type = THROWS, typeIndex = 2)
    })
    public String abstractMethod() {
        return "abstract class Test { abstract void test() throws @TA RuntimeException, IllegalArgumentException, @TB Exception; }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = THROWS, typeIndex = 0),
        @TADescription(annotation = "TB", type = THROWS, typeIndex = 2)
    })
    public String interfaceMethod() {
        return "interface Test { void test() throws @TA RuntimeException, IllegalArgumentException, @TB Exception; }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = THROWS, typeIndex = 0,
                       genericLocation = {}),
        @TADescription(annotation = "TB", type = THROWS, typeIndex = 0,
                       genericLocation = {1, 0}),
        @TADescription(annotation = "TC", type = THROWS, typeIndex = 0,
                       genericLocation = {1, 0, 1, 0}),
        @TADescription(annotation = "TD", type = THROWS, typeIndex = 1,
                       genericLocation = {}),
        @TADescription(annotation = "TE", type = THROWS, typeIndex = 1,
                       genericLocation = {1, 0}),
        @TADescription(annotation = "TF", type = THROWS, typeIndex = 1,
                       genericLocation = {1, 0, 1, 0})
    })
    public String NestedTypes() {
        return "class Outer { class Middle { class Inner1 extends Exception {}" +
                "  class Inner2 extends Exception{} } }" +
                "class Test { void test() throws @TA Outer.@TB Middle.@TC Inner1, @TD Outer.@TE Middle.@TF Inner2 { } }";
    }
}
