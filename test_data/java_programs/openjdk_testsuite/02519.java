

import static com.sun.tools.classfile.TypeAnnotation.TargetType.*;


public class MethodReturns {

    
    @TADescription(annotation = "TA", type = METHOD_RETURN)
    public String methodReturnAsPrimitive() {
        return "@TA int test() { return 0; }";
    }

    @TADescription(annotation = "TA", type = METHOD_RETURN)
    public String methodReturnAsObject() {
        return "@TA Object test() { return null; }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_RETURN),
        @TADescription(annotation = "TB", type = METHOD_RETURN,
                genericLocation = { 3, 0 }),
        @TADescription(annotation = "TC", type = METHOD_RETURN,
                genericLocation = { 3, 1 }),
        @TADescription(annotation = "TD", type = METHOD_RETURN,
                genericLocation = { 3, 1, 3, 0 })
    })
    public String methodReturnAsParametrized() {
        return "@TA Map<@TB String, @TC List<@TD String>> test() { return null; }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_RETURN),
        @TADescription(annotation = "TB", type = METHOD_RETURN,
                genericLocation = { 0, 0 }),
        @TADescription(annotation = "TC", type = METHOD_RETURN,
                genericLocation = { 0, 0, 0, 0 })
    })
    public String methodReturnAsArray() {
        return "@TC String @TA [] @TB [] test() { return null; }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_RETURN),
        @TADescription(annotation = "TB", type = METHOD_RETURN,
                genericLocation = { 0, 0 }),
        @TADescription(annotation = "TC", type = METHOD_RETURN,
                genericLocation = { 0, 0, 0, 0 })
    })
    public String methodReturnAsArrayOld() {
        return "@TC String test() @TA [] @TB [] { return null; }";
    }

    @TADescriptions({})
    public String methodWithDeclarationAnnotation() {
        return "@Decl String test() { return null; }";
    }

    @TADescriptions({})
    public String methodWithNoTargetAnno() {
        return "@A String test() { return null; }";
    }

    
    @TADescription(annotation = "TA", type = METHOD_RETURN)
    public String interfaceMethodReturnAsObject() {
        return "interface Test { @TA Object test(); }";
    }

    @TADescription(annotation = "TA", type = METHOD_RETURN)
    public String abstractMethodReturnAsObject() {
        return "abstract class Test { abstract @TA Object test(); }";
    }


    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_RETURN),
        @TADescription(annotation = "TB", type = METHOD_RETURN,
                genericLocation = { 3, 0 }),
        @TADescription(annotation = "TC", type = METHOD_RETURN,
                genericLocation = { 3, 1 }),
        @TADescription(annotation = "TD", type = METHOD_RETURN,
                genericLocation = { 3, 1, 3, 0 })
    })
    public String interfaceMethodReturnAsParametrized() {
        return "interface Test { @TA Map<@TB String, @TC List<@TD String>> test(); }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_RETURN,
                genericLocation = { 3, 0 }),
        @TADescription(annotation = "TB", type = METHOD_RETURN,
                genericLocation = { 3, 0, 2, 0 }),
        @TADescription(annotation = "TC", type = METHOD_RETURN,
                genericLocation = { 3, 0, 2, 0, 1, 0 }),
        @TADescription(annotation = "TD", type = METHOD_RETURN,
                genericLocation = { 3, 0, 2, 0, 1, 0, 3, 0 }),
        @TADescription(annotation = "TE", type = METHOD_RETURN,
                genericLocation = { 3, 0, 2, 0, 1, 0, 3, 1 }),
        @TADescription(annotation = "TF", type = METHOD_RETURN,
                genericLocation = { 3, 0, 2, 0, 1, 0, 3, 1, 2, 0 })
    })
    public String methodReturnAsNestedWildcard() {
        return "Set<@TA ? extends @TB GOuter<String, String>. @TC GInner<@TD String, @TE ? super @TF Object>> entrySet() { return null; }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_RETURN,
                genericLocation = { 3, 0, 1, 0, 3, 0 }),
        @TADescription(annotation = "TB", type = METHOD_RETURN,
                genericLocation = { 3, 0, 1, 0, 3, 1 }),
        @TADescription(annotation = "TC", type = METHOD_RETURN,
                genericLocation = { 3, 0, 1, 0, 3, 1, 2, 0 })
    })
    public String methodReturnAsNestedWildcard2() {
        return "class GOuter<X, Y> { class GInner<X, Y> {} } " +
                "class Test<K> { Set<GOuter<String, String>.GInner<@TA K, @TB ? extends @TC Object>> entrySet() { return null; } }";
    }

    @TADescriptions({
        @TADescription(annotation = "TB", type = METHOD_RETURN,
                genericLocation = { 3, 0, 2, 0 }),
        @TADescription(annotation = "TC", type = METHOD_RETURN,
                genericLocation = { 3, 0, 2, 0, 1, 0 }),
    })
    public String methodReturnAsNestedWildcard3() {
        return "Set<? extends @TB GOuter<String, String>. @TC GInner<String, Object>> entrySet() { return null; }";
    }

    @TADescriptions({
        @TADescription(annotation = "TC", type = METHOD_RETURN,
                genericLocation = { 3, 0, 2, 0, 1, 0 }),
    })
    public String methodReturnAsNestedWildcard4() {
        return "Set<? extends GOuter<String, String>. @TC GInner<String, Object>> entrySet() { return null; }";
    }

    @TADescriptions({
        @TADescription(annotation = "TB", type = METHOD_RETURN,
                genericLocation = { 3, 0, 2, 0 }),
        @TADescription(annotation = "TC", type = METHOD_RETURN,
                genericLocation = { 3, 0, 2, 0, 1, 0 }),
    })
    public String methodReturnAsNestedWildcard5() {
        return "Set<? extends @TB Outer. @TC Inner> entrySet() { return null; }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_RETURN,
                genericLocation = { 3, 0, 2, 0, 1, 0, 3, 0 }),
        @TADescription(annotation = "TB", type = METHOD_RETURN,
                genericLocation = { 3, 0, 2, 0, 1, 0, 3, 1 }),
        @TADescription(annotation = "TC", type = METHOD_RETURN,
                genericLocation = { 3, 0, 2, 0, 1, 0 }),
    })
    public String methodReturnAsNestedWildcard6() {
        return "Set<? extends GOuter<String, String>. @TC GInner<@TA String, @TB Object>> entrySet() { return null; }";
    }

}
