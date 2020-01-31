

import static com.sun.tools.classfile.TypeAnnotation.TargetType.*;


public class MethodReceivers {

    @TADescription(annotation = "TA", type = METHOD_RECEIVER)
    public String regularMethod() {
        return "class Test { void test(@TA Test this) { } }";
    }

    @TADescription(annotation = "TA", type = METHOD_RECEIVER)
    public String abstractMethod() {
        return "abstract class Test { abstract void test(@TA Test this); }";
    }

    @TADescription(annotation = "TA", type = METHOD_RECEIVER)
    public String interfaceMethod() {
        return "interface Test { void test(@TA Test this); }";
    }

    @TADescription(annotation = "TA", type = METHOD_RECEIVER)
    public String regularWithThrows() {
        return "class Test { void test(@TA Test this) throws Exception { } }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_RECEIVER,
                genericLocation = {}),
        @TADescription(annotation = "TB", type = METHOD_RECEIVER,
                genericLocation = {1, 0})
    })
    @TestClass("TestOuter$TestInner")
    public String nestedtypes1() {
        return "class TestOuter { class TestInner { void test(@TA TestOuter. @TB TestInner this) { } } }";
    }

    @TADescription(annotation = "TA", type = METHOD_RECEIVER,
            genericLocation = {})
    @TestClass("TestOuter$TestInner")
    public String nestedtypes2() {
        return "class TestOuter { class TestInner { void test(@TA TestOuter.TestInner this) { } } }";
    }

    @TADescription(annotation = "TB", type = METHOD_RECEIVER,
            genericLocation = {1, 0})
    @TestClass("TestOuter$TestInner")
    public String nestedtypes3() {
        return "class TestOuter { class TestInner { void test(TestOuter. @TB TestInner this) { } } }";
    }

}
