

import static com.sun.tools.classfile.TypeAnnotation.TargetType.*;


public class TypeTests {

    @TADescription(annotation = "TA", type = INSTANCEOF, offset = ReferenceInfoUtil.IGNORE_VALUE)
    public String returnObject() {
        return "Object returnObject() { return null instanceof @TA String; }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = INSTANCEOF, offset = ReferenceInfoUtil.IGNORE_VALUE),
        @TADescription(annotation = "TB", type = INSTANCEOF,
                genericLocation = { 0, 0 }, offset = ReferenceInfoUtil.IGNORE_VALUE),
        @TADescription(annotation = "TC", type = INSTANCEOF,
                genericLocation = { 0, 0, 0, 0 }, offset = ReferenceInfoUtil.IGNORE_VALUE)
    })
    public String returnObjectArray() {
        return "Object returnObjectArray() { return null instanceof @TC String @TA [] @TB []; }";
    }

    

    @TADescriptions({
        @TADescription(annotation = "TA", type = INSTANCEOF, offset = ReferenceInfoUtil.IGNORE_VALUE),
        @TADescription(annotation = "TB", type = INSTANCEOF,
                genericLocation = { 0, 0 }, offset = ReferenceInfoUtil.IGNORE_VALUE),
        @TADescription(annotation = "TC", type = INSTANCEOF,
                genericLocation = { 0, 0, 0, 0 }, offset = ReferenceInfoUtil.IGNORE_VALUE)
    })
    public String returnPrimArray() {
        return "Object returnPrimArray() { return null instanceof @TC int @TA [] @TB []; }";
    }

    
    

    @TADescription(annotation = "TA", type = INSTANCEOF, offset = ReferenceInfoUtil.IGNORE_VALUE)
    public String initObject() {
        return "void initObject() { Object a =  null instanceof @TA String; }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = INSTANCEOF, offset = ReferenceInfoUtil.IGNORE_VALUE),
        @TADescription(annotation = "TB", type = INSTANCEOF,
                genericLocation = { 0, 0 }, offset = ReferenceInfoUtil.IGNORE_VALUE),
        @TADescription(annotation = "TC", type = INSTANCEOF,
                genericLocation = { 0, 0, 0, 0 }, offset = ReferenceInfoUtil.IGNORE_VALUE)
    })
    public String initObjectArray() {
        return "void initObjectArray() { Object a = null instanceof @TC String @TA [] @TB []; }";
    }

    

    @TADescriptions({
        @TADescription(annotation = "TA", type = INSTANCEOF, offset = ReferenceInfoUtil.IGNORE_VALUE),
        @TADescription(annotation = "TB", type = INSTANCEOF,
                genericLocation = { 0, 0 }, offset = ReferenceInfoUtil.IGNORE_VALUE),
        @TADescription(annotation = "TC", type = INSTANCEOF,
                genericLocation = { 0, 0, 0, 0 }, offset = ReferenceInfoUtil.IGNORE_VALUE)
    })
    public String initPrimArray() {
        return "void initPrimArray() { Object a = null instanceof @TC int @TA [] @TB []; }";
    }

    
    

    @TADescription(annotation = "TA", type = INSTANCEOF, offset = ReferenceInfoUtil.IGNORE_VALUE)
    public String eqtestObject() {
        return "void eqtestObject() { if (true == (null instanceof @TA String)); }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = INSTANCEOF, offset = ReferenceInfoUtil.IGNORE_VALUE),
        @TADescription(annotation = "TB", type = INSTANCEOF,
                genericLocation = { 0, 0 }, offset = ReferenceInfoUtil.IGNORE_VALUE),
        @TADescription(annotation = "TC", type = INSTANCEOF,
                genericLocation = { 0, 0, 0, 0 }, offset = ReferenceInfoUtil.IGNORE_VALUE)
    })
    public String eqtestObjectArray() {
        return "void eqtestObjectArray() { if (true == (null instanceof @TC String @TA [] @TB [])); }";
    }

    

    @TADescriptions({
        @TADescription(annotation = "TA", type = INSTANCEOF, offset = ReferenceInfoUtil.IGNORE_VALUE),
        @TADescription(annotation = "TB", type = INSTANCEOF,
                genericLocation = { 0, 0 }, offset = ReferenceInfoUtil.IGNORE_VALUE),
        @TADescription(annotation = "TC", type = INSTANCEOF,
                genericLocation = { 0, 0, 0, 0 }, offset = ReferenceInfoUtil.IGNORE_VALUE)
    })
    public String eqtestPrimArray() {
        return "void eqtestPrimArray() { if (true == (null instanceof @TC int @TA [] @TB [])); }";
    }

    
    

}
