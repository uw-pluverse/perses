



import static com.sun.tools.classfile.TypeAnnotation.TargetType.*;

public class Lambda {

    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_REFERENCE,
                offset = ReferenceInfoUtil.IGNORE_VALUE),
        @TADescription(annotation = "TB", type = METHOD_REFERENCE,
                offset = ReferenceInfoUtil.IGNORE_VALUE)
    })
    public String returnMethodRef1() {
        return
                "class Lambda {" +
                "  public String getName() { return \"Lambda!\"; }" +
                "}" +

                "class Test {" +
                "  java.util.function.Function<Lambda, String> lambda() {" +
                "    return @TA @TB Lambda::getName;" +
                "  }" +
                "}";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_REFERENCE,
                offset = ReferenceInfoUtil.IGNORE_VALUE),
        @TADescription(annotation = "TB", type = METHOD_REFERENCE,
                offset = ReferenceInfoUtil.IGNORE_VALUE,
                genericLocation = { 3, 0 }),
        @TADescription(annotation = "TC", type = METHOD_REFERENCE,
                offset = ReferenceInfoUtil.IGNORE_VALUE,
                genericLocation = { 3, 0 }),
        @TADescription(annotation = "TD", type = METHOD_REFERENCE,
                offset = ReferenceInfoUtil.IGNORE_VALUE,
                genericLocation = { 3, 1 }),
        @TADescription(annotation = "TE", type = METHOD_REFERENCE,
                offset = ReferenceInfoUtil.IGNORE_VALUE,
                genericLocation = { 3, 1 })
    })
    public String returnMethodRef2() {
        return
                "class Lambda<S, T> {" +
                "  public String getName() { return \"Lambda!\"; }" +
                "}" +

                "class Test {" +
                "  java.util.function.Function<Lambda<Integer, Float>, String> lambda() {" +
                "    return @TA Lambda<@TB @TC Integer, @TD @TE Float>::getName;" +
                "  }" +
                "}";
    }

    @TADescriptions({
        @TADescription(annotation = "CTA", type = METHOD_REFERENCE,
                offset = ReferenceInfoUtil.IGNORE_VALUE),
        @TADescription(annotation = "CTB", type = METHOD_REFERENCE,
                offset = ReferenceInfoUtil.IGNORE_VALUE,
                genericLocation = { 3, 0 }),
        @TADescription(annotation = "CTC", type = METHOD_REFERENCE,
                offset = ReferenceInfoUtil.IGNORE_VALUE,
                genericLocation = { 3, 1 })
    })
    public String returnMethodRef3() {
        return
                "class Lambda<S, T> {" +
                "  public String getName() { return \"Lambda!\"; }" +
                "}" +

                "@Target(ElementType.TYPE_USE)" +
                "@interface CTA {" +
                "  String value();" +
                "}" +

                "@Target(ElementType.TYPE_USE)" +
                "@interface CTB {" +
                "  int age();" +
                "}" +

                "@Target(ElementType.TYPE_USE)" +
                "@interface CTC {" +
                "  String name();" +
                "}" +

                "class Test {" +
                "  java.util.function.Function<Lambda<Integer, Float>, String> lambda() {" +
                "    return @CTA(\"x\") Lambda<@CTB(age = 5) Integer, @CTC(name = \"y\") Float>::getName;" +
                "  }" +
                "}";
    }


    @TADescriptions({
        @TADescription(annotation = "TA", type = CONSTRUCTOR_REFERENCE,
                offset = ReferenceInfoUtil.IGNORE_VALUE),
        @TADescription(annotation = "TB", type = CONSTRUCTOR_REFERENCE,
                offset = ReferenceInfoUtil.IGNORE_VALUE)
    })
    public String returnConstructorRef1() {
        return
                "class Lambda {" +
                "  Lambda() { }" +
                "}" +

                "class Test {" +
                "  Runnable lambda() {" +
                "    return @TA @TB Lambda::new;" +
                "  }" +
                "}";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = CONSTRUCTOR_REFERENCE,
                offset = ReferenceInfoUtil.IGNORE_VALUE),
        @TADescription(annotation = "TB", type = CONSTRUCTOR_REFERENCE,
                offset = ReferenceInfoUtil.IGNORE_VALUE,
                genericLocation = { 3, 0 }),
        @TADescription(annotation = "TC", type = CONSTRUCTOR_REFERENCE,
                offset = ReferenceInfoUtil.IGNORE_VALUE,
                genericLocation = { 3, 0 }),
        @TADescription(annotation = "TD", type = CONSTRUCTOR_REFERENCE,
                offset = ReferenceInfoUtil.IGNORE_VALUE,
                genericLocation = { 3, 1 }),
        @TADescription(annotation = "TE", type = CONSTRUCTOR_REFERENCE,
                offset = ReferenceInfoUtil.IGNORE_VALUE,
                genericLocation = { 3, 1 })
    })
    public String returnConstructorRef2() {
        return
                "class Lambda<S, T> {" +
                "  Lambda() { }" +
                "}" +

                "class Test {" +
                "  Runnable lambda() {" +
                "    return @TA Lambda<@TB @TC Integer, @TD @TE Float>::new;" +
                "  }" +
                "}";
    }

    @TADescriptions({
        @TADescription(annotation = "CTA", type = CONSTRUCTOR_REFERENCE,
                offset = ReferenceInfoUtil.IGNORE_VALUE),
        @TADescription(annotation = "CTB", type = CONSTRUCTOR_REFERENCE,
                offset = ReferenceInfoUtil.IGNORE_VALUE,
                genericLocation = { 3, 0 }),
        @TADescription(annotation = "CTC", type = CONSTRUCTOR_REFERENCE,
                offset = ReferenceInfoUtil.IGNORE_VALUE,
                genericLocation = { 3, 1 })
    })
    public String returnConstructorRef3() {
        return
                "class Lambda<S, T> {" +
                "  Lambda() { }" +
                "}" +

                "@Target(ElementType.TYPE_USE)" +
                "@interface CTA {" +
                "  String value();" +
                "}" +

                "@Target(ElementType.TYPE_USE)" +
                "@interface CTB {" +
                "  int age();" +
                "}" +

                "@Target(ElementType.TYPE_USE)" +
                "@interface CTC {" +
                "  String name();" +
                "}" +

                "class Test {" +
                "  Runnable lambda() {" +
                "    return @CTA(\"x\") Lambda<@CTB(age = 5) Integer, @CTC(name = \"y\") Float>::new;" +
                "  }" +
                "}";
    }


    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_REFERENCE_TYPE_ARGUMENT,
                 offset = ReferenceInfoUtil.IGNORE_VALUE,
                 typeIndex = 0),
        @TADescription(annotation = "TB", type = METHOD_REFERENCE_TYPE_ARGUMENT,
                 offset = ReferenceInfoUtil.IGNORE_VALUE,
                 typeIndex = 1)
    })
    public String returnMethodRefTA1() {
        return
                "interface Lambda {" +
                "  <S, T> void generic(S p1, T p2);" +
                "}" +

                "class LambdaImpl implements Lambda {" +
                "  public <S, T> void generic(S p1, T p2) {}" +
                "}" +

                "class Test {" +
                "  Lambda lambda(LambdaImpl r) {" +
                "    return r::<@TA Object, @TB Object>generic;" +
                "  }" +
                "}";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = CONSTRUCTOR_REFERENCE_TYPE_ARGUMENT,
                 offset = ReferenceInfoUtil.IGNORE_VALUE,
                 typeIndex = 0),
        @TADescription(annotation = "TB", type = CONSTRUCTOR_REFERENCE_TYPE_ARGUMENT,
                 offset = ReferenceInfoUtil.IGNORE_VALUE,
                 typeIndex = 1)
    })
    public String returnConstructorRefTA2() {
        return
                "interface Lambda {" +
                "  <S, T> void generic(S p1, T p2);" +
                "}" +

                "class LambdaImpl implements Lambda {" +
                "  <S, T> LambdaImpl(S p1, T p2) {}" +
                "  public <S, T> void generic(S p1, T p2) {}" +
                "}" +

                "class Test {" +
                "  Lambda lambda() {" +
                "    return LambdaImpl::<@TA Object, @TB Object>new;" +
                "  }" +
                "}";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_FORMAL_PARAMETER,
                paramIndex = 0),
        @TADescription(annotation = "TB", type = METHOD_FORMAL_PARAMETER,
                paramIndex = 1),
        @TADescription(annotation = "TC", type = METHOD_FORMAL_PARAMETER,
                paramIndex = 1, genericLocation = { 3, 0 }),
        @TADescription(annotation = "TD", type = LOCAL_VARIABLE,
                lvarOffset = ReferenceInfoUtil.IGNORE_VALUE,
                lvarLength = ReferenceInfoUtil.IGNORE_VALUE,
                lvarIndex = ReferenceInfoUtil.IGNORE_VALUE),
        @TADescription(annotation = "TE", type = CAST,
                offset = ReferenceInfoUtil.IGNORE_VALUE,
                typeIndex = 0)
    })
    public String returnLambdaExpr1() {
        return
                "interface LambdaInt {" +
                "  void lambda(Object p1, List<Object> p2);" +
                "}" +
                "class Test {" +
                "  LambdaInt getLambda() {" +
                "    return (@TA Object x, @TB List<@TC Object> y) -> { @TD Object l = null; System.out.println((@TE Object) l); };" +
                "  }" +
                "}";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_FORMAL_PARAMETER,
            paramIndex = 0)})
    public String lambdaField1() {
        return
            "class Test {" +
                " java.util.function.IntUnaryOperator field = (@TA int y) -> 1;" +
            "}";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_FORMAL_PARAMETER,
            paramIndex = 0)})
    public String lambdaField2() {
        return
            "class Test {" +
                " static java.util.function.IntUnaryOperator field = (@TA int y) -> 1;" +
            "}";
    }
}
