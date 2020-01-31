

import static com.sun.tools.classfile.TypeAnnotation.TargetType.*;


public class TypeCasts {

    @TADescription(annotation = "TA", type = CAST, offset = ReferenceInfoUtil.IGNORE_VALUE,
            typeIndex = 0)
    public String returnObject() {
        return "Object returnObject() { return (@TA String)null; }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = CAST, offset = ReferenceInfoUtil.IGNORE_VALUE,
                typeIndex = 0),
        @TADescription(annotation = "TB", type = CAST,
                genericLocation = { 0, 0 }, offset = ReferenceInfoUtil.IGNORE_VALUE,
                typeIndex = 0),
        @TADescription(annotation = "TC", type = CAST,
                genericLocation = { 0, 0, 0, 0 }, offset = ReferenceInfoUtil.IGNORE_VALUE,
                typeIndex = 0)
    })
    public String returnObjectArray() {
        return "Object returnObjectArray() { return (@TC String @TA [] @TB [])null; }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = CAST, offset = ReferenceInfoUtil.IGNORE_VALUE,
                typeIndex = 0),
        @TADescription(annotation = "TB", type = CAST,
                genericLocation = { 3, 0 }, offset = ReferenceInfoUtil.IGNORE_VALUE,
                typeIndex = 0)
    })
    public String returnObjectGeneric() {
        return "Object returnObjectGeneric() { return (@TA List<@TB String>)null; }";
    }

    @TADescription(annotation = "TA", type = CAST, offset = ReferenceInfoUtil.IGNORE_VALUE,
            typeIndex = 0)
    public String returnPrim() {
        return "Object returnPrim() { return (@TA int)0; }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = CAST, offset = ReferenceInfoUtil.IGNORE_VALUE,
                typeIndex = 0),
        @TADescription(annotation = "TB", type = CAST,
                genericLocation = { 0, 0 }, offset = ReferenceInfoUtil.IGNORE_VALUE,
                typeIndex = 0)
    })
    public String returnPrimArray() {
        return "Object returnPrimArray() { return (@TB int @TA [])null; }";
    }

    @TADescription(annotation = "TA", type = CAST, offset = ReferenceInfoUtil.IGNORE_VALUE,
            typeIndex = 0)
    public String initObject() {
        return "void initObject() { Object a =  (@TA String)null; }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = CAST, offset = ReferenceInfoUtil.IGNORE_VALUE,
                typeIndex = 0),
        @TADescription(annotation = "TB", type = CAST,
                genericLocation = { 0, 0 }, offset = ReferenceInfoUtil.IGNORE_VALUE,
                typeIndex = 0)
    })
    public String initObjectArray() {
        return "void initObjectArray() { Object a = (@TB String @TA [])null; }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = CAST, offset = ReferenceInfoUtil.IGNORE_VALUE,
                typeIndex = 0),
        @TADescription(annotation = "TB", type = CAST,
                genericLocation = { 3, 0 }, offset = ReferenceInfoUtil.IGNORE_VALUE,
                typeIndex = 0)
    })
    public String initObjectGeneric() {
        return "void initObjectGeneric() { Object a = (@TA List<@TB String>)null; }";
    }

    @TADescription(annotation = "TA", type = CAST, offset = ReferenceInfoUtil.IGNORE_VALUE,
            typeIndex = 0)
    public String initPrim() {
        return "void initPrim() { Object a =  (@TA int)0; }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = CAST, offset = ReferenceInfoUtil.IGNORE_VALUE,
                typeIndex = 0),
        @TADescription(annotation = "TB", type = CAST,
                genericLocation = { 0, 0 }, offset = ReferenceInfoUtil.IGNORE_VALUE,
                typeIndex = 0)
    })
    public String initPrimArray() {
        return "void initPrimArray() { Object a = (@TB int @TA [])null; }";
    }

    @TADescription(annotation = "TA", type = CAST, offset = ReferenceInfoUtil.IGNORE_VALUE,
            typeIndex = 0)
    public String eqtestObject() {
        return "void eqtestObject() { if (null == (@TA String)null); }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = CAST, offset = ReferenceInfoUtil.IGNORE_VALUE,
                typeIndex = 0),
        @TADescription(annotation = "TB", type = CAST,
                genericLocation = { 0, 0 }, offset = ReferenceInfoUtil.IGNORE_VALUE,
                typeIndex = 0)
    })
    public String eqtestObjectArray() {
        return "void eqtestObjectArray() { if (null == (@TB String @TA [])null); }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = CAST, offset = ReferenceInfoUtil.IGNORE_VALUE,
                typeIndex = 0),
        @TADescription(annotation = "TB", type = CAST,
                genericLocation = { 3, 0 }, offset = ReferenceInfoUtil.IGNORE_VALUE,
                typeIndex = 0)
    })
    public String eqtestObjectGeneric() {
        return "void eqtestObjectGeneric() { if (null == (@TA List<@TB String >)null); }";
    }

    @TADescription(annotation = "TA", type = CAST, offset = ReferenceInfoUtil.IGNORE_VALUE,
            typeIndex = 0)
    
    public String eqtestPrim() {
        return "void eqtestPrim(int a) { if (0 == (@TA int)a); }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = CAST, offset = ReferenceInfoUtil.IGNORE_VALUE,
                typeIndex = 0),
        @TADescription(annotation = "TB", type = CAST,
                genericLocation = { 0, 0 }, offset = ReferenceInfoUtil.IGNORE_VALUE,
                typeIndex = 0)
    })
    public String eqtestPrimArray() {
        return "void eqtestPrimArray() { if (null == (@TB int @TA [])null); }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = CAST,
                offset = ReferenceInfoUtil.IGNORE_VALUE, typeIndex = 0),
        @TADescription(annotation = "TB", type = CAST,
                offset = ReferenceInfoUtil.IGNORE_VALUE, typeIndex = 1),
        @TADescription(annotation = "TC", type = CAST,
                offset = ReferenceInfoUtil.IGNORE_VALUE, typeIndex = 1,
                genericLocation = {3, 0})
    })
    public String intersection1() {
        return "void intersection() { Object o = (@TA String & @TB Comparable<@TC String>) null; }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = CAST,
                offset = ReferenceInfoUtil.IGNORE_VALUE, typeIndex = 0),
        @TADescription(annotation = "TB", type = CAST,
                offset = ReferenceInfoUtil.IGNORE_VALUE, typeIndex = 1),
        @TADescription(annotation = "TC", type = CAST,
                offset = ReferenceInfoUtil.IGNORE_VALUE, typeIndex = 1,
                genericLocation = {3, 0}),
        @TADescription(annotation = "TD", type = CAST,
                offset = ReferenceInfoUtil.IGNORE_VALUE, typeIndex = 2),
    })
    public String intersection2() {
        return "void intersection() { Object o = (@TA String & @TB Comparable<@TC String> & @TD CharSequence) null; }";
    }
}
