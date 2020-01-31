

import static com.sun.tools.classfile.TypeAnnotation.TargetType.*;


public class MultiCatch {

    @TADescriptions({
        @TADescription(annotation = "TA", type = EXCEPTION_PARAMETER, exceptionIndex = 0),
        @TADescription(annotation = "TB", type = EXCEPTION_PARAMETER, exceptionIndex = 1)
    })
    public String multiCatch1() {
        return "void multiCatch1() { " +
            "try { new Object(); } catch (@TA NullPointerException | @TB IndexOutOfBoundsException e) { e.toString(); } }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = EXCEPTION_PARAMETER, exceptionIndex = 0),
        @TADescription(annotation = "TB", type = EXCEPTION_PARAMETER, exceptionIndex = 1),
        @TADescription(annotation = "TC", type = EXCEPTION_PARAMETER, exceptionIndex = 2),
    })
    public String multiCatch2() {
        return "void multiCatch2() { " +
            "try { new Object(); } catch (@TA NullPointerException | @TB IndexOutOfBoundsException | @TC IllegalArgumentException e) { e.toString(); } }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = EXCEPTION_PARAMETER, exceptionIndex = 1),
        @TADescription(annotation = "TB", type = EXCEPTION_PARAMETER, exceptionIndex = 1),
        @TADescription(annotation = "TC", type = EXCEPTION_PARAMETER, exceptionIndex = 2),
        @TADescription(annotation = "TD", type = EXCEPTION_PARAMETER, exceptionIndex = 2),
        @TADescription(annotation = "TE", type = EXCEPTION_PARAMETER, exceptionIndex = 3),
    })
    public String multiCatch3() {
        return "void multiCatch3() { " +
            "try { new Object(); } catch (NullPointerException e1) {}" +
            "try { new Object(); } catch (@TA @TB NullPointerException | @TC @TD IndexOutOfBoundsException | @TE IllegalArgumentException e2) { e2.toString(); } }";
    }
}
