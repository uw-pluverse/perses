

import static com.sun.tools.classfile.TypeAnnotation.TargetType.*;


public class ExceptionParameters {

    @TADescription(annotation = "TA", type = EXCEPTION_PARAMETER, exceptionIndex = 0)
    public String exception() {
        return "void exception() { try { new Object(); } catch(@TA Exception e) { } }";
    }

    @TADescription(annotation = "TA", type = EXCEPTION_PARAMETER, exceptionIndex = 0)
    public String finalException() {
        return "void finalException() { try { new Object(); } catch(final @TA Exception e) { } }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = EXCEPTION_PARAMETER, exceptionIndex = 0),
        @TADescription(annotation = "TB", type = EXCEPTION_PARAMETER, exceptionIndex = 1),
        @TADescription(annotation = "TC", type = EXCEPTION_PARAMETER, exceptionIndex = 2)
    })
    public String multipleExceptions1() {
        return "void multipleExceptions() { " +
            "try { new Object(); } catch(@TA Exception e) { }" +
            "try { new Object(); } catch(@TB Exception e) { }" +
            "try { new Object(); } catch(@TC Exception e) { }" +
            " }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = EXCEPTION_PARAMETER, exceptionIndex = 0),
        @TADescription(annotation = "TB", type = EXCEPTION_PARAMETER, exceptionIndex = 1),
        @TADescription(annotation = "TC", type = EXCEPTION_PARAMETER, exceptionIndex = 2)
    })
    public String multipleExceptions2() {
        return "void multipleExceptions() { " +
            "  try { new Object(); " +
            "    try { new Object(); " +
            "      try { new Object(); } catch(@TA Exception e) { }" +
            "    } catch(@TB Exception e) { }" +
            "  } catch(@TC Exception e) { }" +
            "}";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = EXCEPTION_PARAMETER, exceptionIndex = 0),
        @TADescription(annotation = "TB", type = EXCEPTION_PARAMETER, exceptionIndex = 1),
        @TADescription(annotation = "TC", type = EXCEPTION_PARAMETER, exceptionIndex = 2)
    })
    public String multipleExceptions3() {
        return "void multipleExceptions() { " +
            "  try { new Object(); " +
            "  } catch(@TA Exception e1) { "+
            "    try { new Object(); " +
            "    } catch(@TB Exception e2) {" +
            "      try { new Object(); } catch(@TC Exception e3) { }" +
            "    }" +
            "  }" +
            "}";
    }
}
