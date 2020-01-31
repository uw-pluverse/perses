

import static com.sun.tools.classfile.TypeAnnotation.TargetType.*;


public class FromSpecification {

    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_FORMAL_PARAMETER, paramIndex = 0),
        @TADescription(annotation = "TB", type = METHOD_FORMAL_PARAMETER,
                genericLocation = {3, 0}, paramIndex = 0),
        @TADescription(annotation = "TC", type = METHOD_FORMAL_PARAMETER,
                genericLocation = {3, 0, 2, 0}, paramIndex = 0),
        @TADescription(annotation = "TD", type = METHOD_FORMAL_PARAMETER,
                genericLocation = {3, 1}, paramIndex = 0),
        @TADescription(annotation = "TE", type = METHOD_FORMAL_PARAMETER,
                genericLocation = {3, 1, 3, 0}, paramIndex = 0)
    })
    public String testSpec1() {
        return "void test(@TA Map<@TB ? extends @TC String, @TD List<@TE Object>> a) { }";
    }

    @TADescriptions({
        @TADescription(annotation = "TF", type = METHOD_FORMAL_PARAMETER, paramIndex = 0),
        @TADescription(annotation = "TG", type = METHOD_FORMAL_PARAMETER,
                genericLocation = {0, 0}, paramIndex = 0),
        @TADescription(annotation = "TH", type = METHOD_FORMAL_PARAMETER,
                genericLocation = {0, 0, 0, 0}, paramIndex = 0),
        @TADescription(annotation = "TI", type = METHOD_FORMAL_PARAMETER,
                genericLocation = {0, 0, 0, 0, 0, 0}, paramIndex = 0)
    })
    public String testSpec2() {
        return "void test(@TI String @TF [] @TG [] @TH [] a) { }";
    }

    
    @TADescriptions({
        @TADescription(annotation = "TJ", type = METHOD_FORMAL_PARAMETER,
                genericLocation = {1, 0, 1, 0, 1, 0, 1, 0}, paramIndex = 0),
        @TADescription(annotation = "TK", type = METHOD_FORMAL_PARAMETER,
                genericLocation = {1, 0, 1, 0, 1, 0}, paramIndex = 0),
        @TADescription(annotation = "TL", type = METHOD_FORMAL_PARAMETER,
                genericLocation = {1, 0, 1, 0}, paramIndex = 0),
        @TADescription(annotation = "TM", type = METHOD_FORMAL_PARAMETER,
                genericLocation = {1, 0}, paramIndex = 0)
    })
    public String testSpec3() {
        return "class Test { class O1 { class O2 { class O3 { class NestedStatic {} } } }" +
                "void test(@TM O1.@TL O2.@TK O3.@TJ NestedStatic a) { } }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_FORMAL_PARAMETER, paramIndex = 0),
        @TADescription(annotation = "TB", type = METHOD_FORMAL_PARAMETER,
                genericLocation = {3, 0}, paramIndex = 0),
        @TADescription(annotation = "TC", type = METHOD_FORMAL_PARAMETER,
                genericLocation = {3, 0, 3, 0}, paramIndex = 0),
        @TADescription(annotation = "TD", type = METHOD_FORMAL_PARAMETER,
                genericLocation = {3, 0, 3, 0, 0, 0}, paramIndex = 0),
        @TADescription(annotation = "TE", type = METHOD_FORMAL_PARAMETER,
                genericLocation = {3, 0, 3, 0, 0, 0, 0, 0}, paramIndex = 0),
        @TADescription(annotation = "TF", type = METHOD_FORMAL_PARAMETER,
                genericLocation = {3, 0, 3, 0, 0, 0, 0, 0, 0, 0}, paramIndex = 0),
        @TADescription(annotation = "TG", type = METHOD_FORMAL_PARAMETER,
                genericLocation = {3, 1}, paramIndex = 0),
        @TADescription(annotation = "TH", type = METHOD_FORMAL_PARAMETER,
                genericLocation = {3, 1, 3, 0}, paramIndex = 0)
    })
    public String testSpec4() {
        return "void test(@TA Map<@TB Comparable<@TF Object @TC [] @TD [] @TE []>, @TG List<@TH String>> a) { }";
    }

    
    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_FORMAL_PARAMETER,
                genericLocation = {1, 0, 1, 0, 1, 0, 1, 0}, paramIndex = 0),
        @TADescription(annotation = "TB", type = METHOD_FORMAL_PARAMETER,
                genericLocation = {1, 0, 1, 0, 1, 0, 1, 0, 3, 0}, paramIndex = 0),
        @TADescription(annotation = "TC", type = METHOD_FORMAL_PARAMETER,
                genericLocation = {1, 0, 1, 0, 1, 0, 1, 0, 3, 1}, paramIndex = 0),
        @TADescription(annotation = "TD", type = METHOD_FORMAL_PARAMETER,
                genericLocation = {1, 0, 1, 0, 1, 0}, paramIndex = 0),
        @TADescription(annotation = "TE", type = METHOD_FORMAL_PARAMETER,
                genericLocation = {1, 0, 1, 0}, paramIndex = 0),
        @TADescription(annotation = "TF", type = METHOD_FORMAL_PARAMETER,
                genericLocation = {1, 0, 1, 0, 3, 0}, paramIndex = 0),
        @TADescription(annotation = "TG", type = METHOD_FORMAL_PARAMETER,
                genericLocation = {1, 0, 1, 0, 3, 1}, paramIndex = 0),
        @TADescription(annotation = "TH", type = METHOD_FORMAL_PARAMETER,
                genericLocation = {1, 0}, paramIndex = 0)
    })
    public String testSpec5() {
        return "class Test { class O1 { class O2<A, B> { class O3 { class Nested<X, Y> {} } } }" +
                "void test(@TH O1.@TE O2<@TF String, @TG String>.@TD O3.@TA Nested<@TB String, @TC String> a) { } }";
    }
}
