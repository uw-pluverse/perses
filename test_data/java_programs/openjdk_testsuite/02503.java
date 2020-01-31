

import static com.sun.tools.classfile.TypeAnnotation.TargetType.*;


public class Initializers {

    @TADescriptions({
        @TADescription(annotation = "TA", type = NEW, offset = ReferenceInfoUtil.IGNORE_VALUE),
        @TADescription(annotation = "TB", type = NEW,
                genericLocation = { 3, 0 }, offset = ReferenceInfoUtil.IGNORE_VALUE)
    })
    public String instanceInit1() {
        return "class Test { { Object o = new @TA ArrayList<@TB String>(); } }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = NEW, offset = ReferenceInfoUtil.IGNORE_VALUE),
        @TADescription(annotation = "TB", type = NEW,
                genericLocation = { 3, 0 }, offset = ReferenceInfoUtil.IGNORE_VALUE),
        @TADescription(annotation = "TC", type = NEW, offset = ReferenceInfoUtil.IGNORE_VALUE),
        @TADescription(annotation = "TD", type = NEW,
                genericLocation = { 3, 0 }, offset = ReferenceInfoUtil.IGNORE_VALUE)
    })
    public String instanceInit2() {
        return "class Test { Object f = new @TA ArrayList<@TB String>(); " +
                " { Object o = new @TC ArrayList<@TD String>(); } }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = NEW, offset = ReferenceInfoUtil.IGNORE_VALUE),
        @TADescription(annotation = "TB", type = NEW,
                genericLocation = { 3, 0 }, offset = ReferenceInfoUtil.IGNORE_VALUE)
    })
    public String staticInit1() {
        return "class Test { static { Object o = new @TA ArrayList<@TB String>(); } }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = NEW, offset = ReferenceInfoUtil.IGNORE_VALUE),
        @TADescription(annotation = "TB", type = NEW,
                genericLocation = { 3, 0 }, offset = ReferenceInfoUtil.IGNORE_VALUE),
        @TADescription(annotation = "TC", type = NEW, offset = ReferenceInfoUtil.IGNORE_VALUE),
        @TADescription(annotation = "TD", type = NEW,
                genericLocation = { 3, 0 }, offset = ReferenceInfoUtil.IGNORE_VALUE),
        @TADescription(annotation = "TE", type = NEW, offset = ReferenceInfoUtil.IGNORE_VALUE),
        @TADescription(annotation = "TF", type = NEW,
                genericLocation = { 3, 0 }, offset = ReferenceInfoUtil.IGNORE_VALUE)
    })
    public String staticInit2() {
        return "class Test { Object f = new @TA ArrayList<@TB String>(); " +
                " static Object g = new @TC ArrayList<@TD String>(); " +
                " static { Object o = new @TE ArrayList<@TF String>(); } }";
    }

    
    

    @TADescriptions({
        @TADescription(annotation = "TA", type = CAST,
                typeIndex = 0, offset = ReferenceInfoUtil.IGNORE_VALUE),
    })
    public String lazyConstantCast1() {
        return "class Test { public static final Object o = (@TA Object) null; }";
    }

}
