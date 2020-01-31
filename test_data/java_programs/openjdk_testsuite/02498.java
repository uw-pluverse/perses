

import static com.sun.tools.classfile.TypeAnnotation.TargetType.*;


public class MethodTypeParam {

    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_TYPE_PARAMETER, paramIndex = 0),
        @TADescription(annotation = "TB", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 0, boundIndex = 0),
        @TADescription(annotation = "TC", type = METHOD_TYPE_PARAMETER, paramIndex = 1),
        @TADescription(annotation = "TD", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 1, boundIndex = 0),
        @TADescription(annotation = "TE", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 1, boundIndex = 1)
    })
    public String regularClass() {
        return "<@TA K extends @TB Date, @TC V extends @TD Object & @TE Cloneable> void test() { }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_TYPE_PARAMETER, paramIndex = 0),
        @TADescription(annotation = "TB", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 0, boundIndex = 0),
        @TADescription(annotation = "TC", type = METHOD_TYPE_PARAMETER, paramIndex = 1),
        @TADescription(annotation = "TE", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 1, boundIndex = 1)
    })
    public String regularClass2() {
        return "<@TA K extends @TB Date, @TC V extends @TE Cloneable> void test() { }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 0, boundIndex = 1),
        @TADescription(annotation = "TB", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 0, boundIndex = 1, genericLocation = {3, 1}),
        @TADescription(annotation = "TC", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 1, boundIndex = 1),
        @TADescription(annotation = "TD", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 1, boundIndex = 1, genericLocation = {3, 0}),
        @TADescription(annotation = "TE", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 1, boundIndex = 1, genericLocation = {3, 0, 3, 0}),
        @TADescription(annotation = "TF", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 1, boundIndex = 0)
    })
    public String regularClassParameterized() {
        return "<K extends @TA Map<String, @TB String>, V extends @TF Object & @TC List<@TD List<@TE Object>>> void test() { }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_TYPE_PARAMETER, paramIndex = 0),
        @TADescription(annotation = "TB", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 0, boundIndex = 0),
        @TADescription(annotation = "TC", type = METHOD_TYPE_PARAMETER, paramIndex = 1),
        @TADescription(annotation = "TD", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 1, boundIndex = 0),
        @TADescription(annotation = "TE", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 1, boundIndex = 1)
    })
    public String abstractClass() {
        return "abstract class Test { abstract <@TA K extends @TB Date, @TC V extends @TD Object & @TE Cloneable> void test(); }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 0, boundIndex = 1),
        @TADescription(annotation = "TB", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 0, boundIndex = 1, genericLocation = {3, 1}),
        @TADescription(annotation = "TC", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 1, boundIndex = 1),
        @TADescription(annotation = "TD", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 1, boundIndex = 1, genericLocation = {3, 0}),
        @TADescription(annotation = "TE", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 1, boundIndex = 1, genericLocation = {3, 0, 3, 0}),
        @TADescription(annotation = "TF", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 1, boundIndex = 0),
        @TADescription(annotation = "TG", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 0, boundIndex = 0)
    })
    public String abstractClassParameterized() {
        return "abstract class Test { abstract <K extends @TG Object & @TA Map<String, @TB String>, V extends @TF Object & @TC List<@TD List<@TE Object>>> void test(); }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 0, boundIndex = 1),
        @TADescription(annotation = "TB", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 0, boundIndex = 1, genericLocation = {3, 1}),
        @TADescription(annotation = "TC", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 1, boundIndex = 1),
        @TADescription(annotation = "TD", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 1, boundIndex = 1, genericLocation = {3, 0}),
        @TADescription(annotation = "TE", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 1, boundIndex = 1, genericLocation = {3, 0, 3, 0})
    })
    public String abstractClassParameterized2() {
        return "abstract class Test { abstract <K extends @TA Map<String, @TB String>, V extends @TC List<@TD List<@TE Object>>> void test(); }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 0, boundIndex = 1),
        @TADescription(annotation = "TB", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 1, boundIndex = 1)
    })
    public String abstractClassParameterized3() {
        return "abstract class Test { abstract <K extends @TA List<String>, V extends @TB List<Object>> void test(); }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_TYPE_PARAMETER, paramIndex = 0),
        @TADescription(annotation = "TB", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 0, boundIndex = 0),
        @TADescription(annotation = "TC", type = METHOD_TYPE_PARAMETER, paramIndex = 1),
        @TADescription(annotation = "TD", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 1, boundIndex = 0),
        @TADescription(annotation = "TE", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 1, boundIndex = 1)
    })
    public String regularInterface() {
        return "interface Test { <@TA K extends @TB Date, @TC V extends @TD Object & @TE Cloneable> void test(); }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 0, boundIndex = 1),
        @TADescription(annotation = "TB", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 0, boundIndex = 1, genericLocation = {3, 1}),
        @TADescription(annotation = "TC", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 1, boundIndex = 1),
        @TADescription(annotation = "TD", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 1, boundIndex = 1, genericLocation = {3, 0}),
        @TADescription(annotation = "TE", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 1, boundIndex = 1, genericLocation = {3, 0, 3, 0}),
        @TADescription(annotation = "TF", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 1, boundIndex = 0),
        @TADescription(annotation = "TG", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 0, boundIndex = 0),
        @TADescription(annotation = "TH", type = METHOD_TYPE_PARAMETER, paramIndex = 0),
        @TADescription(annotation = "TI", type = METHOD_TYPE_PARAMETER, paramIndex = 1)
    })
    public String regularInterfaceParameterized() {
        return "interface Test { <@TH K extends @TG Object & @TA Map<String, @TB String>, @TI V extends @TF Object & @TC List<@TD List<@TE Object>>> void test(); }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 0, boundIndex = 1),
        @TADescription(annotation = "TB", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 0, boundIndex = 1, genericLocation = {3, 1}),
        @TADescription(annotation = "TC", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 1, boundIndex = 1),
        @TADescription(annotation = "TD", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 1, boundIndex = 1, genericLocation = {3, 0}),
        @TADescription(annotation = "TE", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 1, boundIndex = 1, genericLocation = {3, 0, 3, 0}),
        @TADescription(annotation = "TF", type = METHOD_TYPE_PARAMETER, paramIndex = 0),
        @TADescription(annotation = "TG", type = METHOD_TYPE_PARAMETER, paramIndex = 1)
    })
    public String regularInterfaceParameterized2() {
        return "interface Test { <@TF K extends @TA Map<String, @TB String>, @TG V extends @TC List<@TD List<@TE Object>>> void test(); }";
    }

    @TADescription(annotation = "TA", type = METHOD_RETURN)
    public String useInReturn1() {
        return "class Test { <T> @TA T m() { throw new RuntimeException(); } }";
    }

    @TADescription(annotation = "TA", type = METHOD_RETURN, genericLocation = {3, 0})
    public String useInReturn2() {
        return "class Test { <T> Class<@TA T> m() { throw new RuntimeException(); } }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 0, boundIndex = 0),
        @TADescription(annotation = "TB", type = METHOD_RETURN)
    })
    public String useInReturn3() {
        return "class Test { <T extends @TA Object> @TB T m() { throw new RuntimeException(); } }";
    }

    @TADescription(annotation = "TA", type = METHOD_FORMAL_PARAMETER,
            paramIndex = 0, genericLocation = {3, 0})
    public String useInParam1() {
        return "class Test { <T> void m(Class<@TA T> p) { throw new RuntimeException(); } }";
    }

    @TADescription(annotation = "TA", type = METHOD_FORMAL_PARAMETER,
            paramIndex = 0, genericLocation = {3, 0})
    public String useInParam2() {
        return "class Test { void m(Class<@TA Object> p) { throw new RuntimeException(); } }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 0, boundIndex = 1),
        @TADescription(annotation = "TB", type = METHOD_TYPE_PARAMETER_BOUND, paramIndex = 0, boundIndex = 2),
        @TADescription(annotation = "TC", type = METHOD_FORMAL_PARAMETER, paramIndex = 0)
    })
    public String useInParam3() {
        return "interface IA {} " +
               "interface IB<XB> {} " +
               "interface IC<XC> {} " +
               "class Test { <T extends @TA IB<IA> & @TB IC<IA>> void m(@TC T p) { throw new RuntimeException(); } }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_TYPE_PARAMETER_BOUND,
                paramIndex = 0, boundIndex = 1,
                genericLocation = {}),
        @TADescription(annotation = "TB", type = METHOD_TYPE_PARAMETER_BOUND,
                paramIndex = 0, boundIndex = 2,
                genericLocation = {}),
        @TADescription(annotation = "TC", type = METHOD_FORMAL_PARAMETER,
                paramIndex = 0)
    })
    public String useInParam4() {
        return "class Test {" +
               "  interface IA {} " +
               "  interface IB<XB> {} " +
               "  interface IC<XC> {} " +
               "  <T extends @TA IB<IA> & @TB IC<IA>> void m(@TC T p) { throw new RuntimeException(); } }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_TYPE_PARAMETER_BOUND,
                paramIndex = 0, boundIndex = 0,
                genericLocation = {}),
        @TADescription(annotation = "TB", type = METHOD_TYPE_PARAMETER_BOUND,
                paramIndex = 0, boundIndex = 0,
                genericLocation = {1, 0}),
        @TADescription(annotation = "TC", type = METHOD_TYPE_PARAMETER_BOUND,
                paramIndex = 0, boundIndex = 0,
                genericLocation = {1, 0, 3, 0}),
    })
    public String useInParam5() {
        return "class Test {" +
               "  interface IA {} " +
               "  class CB<XC> {} " +
               "  <T extends @TA Test. @TB CB<@TC IA>> void m(T p) { throw new RuntimeException(); } }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = METHOD_TYPE_PARAMETER,
                paramIndex = 0),
        @TADescription(annotation = "TB", type = METHOD_TYPE_PARAMETER_BOUND,
                paramIndex = 0, boundIndex = 0,
                genericLocation = {}),
        @TADescription(annotation = "TC", type = METHOD_TYPE_PARAMETER_BOUND,
                paramIndex = 0, boundIndex = 0,
                genericLocation = {1, 0, 3, 0}),
        @TADescription(annotation = "TD", type = METHOD_TYPE_PARAMETER_BOUND,
                paramIndex = 0, boundIndex = 1,
                genericLocation = {}),
        @TADescription(annotation = "TE", type = METHOD_TYPE_PARAMETER_BOUND,
                paramIndex = 0, boundIndex = 1,
                genericLocation = {3, 0})
    })
    public String useInParam6() {
        return "class Test {" +
               "  interface IA {} " +
               "  interface IB<XB> {} " +
               "  class CC<XC> {} " +
               "  interface ID<XD> {} " +
               "  <@TA T extends @TB Test.CC<@TC IA> & Test. @TD ID<@TE IA>> void m(T p) { throw new RuntimeException(); } }";
    }
}
