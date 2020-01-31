

import static com.sun.tools.classfile.TypeAnnotation.TargetType.*;


public class RepeatingTypeAnnotations {
    
    @TADescription(annotation = "RTAs", type = FIELD)
    public String fieldAsPrimitive() {
        return "@RTA @RTA int test;";
    }

    
    @TADescription(annotation = "RTAs", type = METHOD_RETURN)
    public String methodReturn1() {
        return "@RTA @RTA int test() { return 0; }";
    }

    @TADescription(annotation = "RTAs", type = METHOD_RETURN)
    public String methodReturn2() {
        return "@RTAs({@RTA, @RTA}) int test() { return 0; }";
    }

    
    @TADescriptions({
        @TADescription(annotation = "RTAs", type = METHOD_FORMAL_PARAMETER,
                paramIndex = 0),
        @TADescription(annotation = "RTBs", type = METHOD_FORMAL_PARAMETER,
                paramIndex = 0,
                genericLocation = { 3, 0 })
    })
    public String methodParam1() {
        return "void m(@RTA @RTA List<@RTB @RTB String> p) {}";
    }

    @TADescriptions({
        @TADescription(annotation = "RTAs", type = METHOD_FORMAL_PARAMETER,
                paramIndex = 0),
        @TADescription(annotation = "RTBs", type = METHOD_FORMAL_PARAMETER,
                paramIndex = 0,
                genericLocation = { 3, 0 })
    })
    public String methodParam2() {
        return "void m(@RTAs({@RTA, @RTA}) List<@RTBs({@RTB, @RTB}) String> p) {}";
    }

    
}
