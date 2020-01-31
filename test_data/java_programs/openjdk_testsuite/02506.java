

import static com.sun.tools.classfile.TypeAnnotation.TargetType.*;


public class Fields {

    
    @TADescription(annotation = "TA", type = FIELD)
    public String fieldAsPrimitive() {
        return "@TA int test;";
    }

    @TADescription(annotation = "TA", type = FIELD)
    public String fieldAsObject() {
        return "@TA Object test;";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = FIELD),
        @TADescription(annotation = "TB", type = FIELD,
                genericLocation = { 3, 0 }),
        @TADescription(annotation = "TC", type = FIELD,
                genericLocation = { 3, 1 }),
        @TADescription(annotation = "TD", type = FIELD,
                genericLocation = { 3, 1, 3, 0 })
    })
    public String fieldAsParametrized() {
        return "@TA Map<@TB String, @TC List<@TD String>> test;";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = FIELD),
        @TADescription(annotation = "TB", type = FIELD,
                genericLocation = { 0, 0 }),
        @TADescription(annotation = "TC", type = FIELD,
                genericLocation = { 0, 0, 0, 0 })
    })
    public String fieldAsArray() {
        return "@TC String @TA [] @TB [] test;";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = FIELD),
        @TADescription(annotation = "TB", type = FIELD,
                genericLocation = { 0, 0 }),
        @TADescription(annotation = "TC", type = FIELD,
                genericLocation = { 0, 0, 0, 0 })
    })
    public String fieldAsArrayOld() {
        return "@TC String test @TA [] @TB [];";
    }

    @TADescriptions({})
    public String fieldWithDeclarationAnnotatin() {
        return "@Decl String test;";
    }

    @TADescriptions({})
    public String fieldWithNoTargetAnno() {
        return "@A String test;";
    }

    
    @TADescription(annotation = "TA", type = FIELD)
    public String interfacefieldAsObject() {
        return "interface Test { @TA String test = null; }";
    }

    @TADescription(annotation = "TA", type = FIELD)
    public String abstractfieldAsObject() {
        return "abstract class Test { @TA String test; }";
    }

    @TADescriptions({
        @TADescription(annotation = "TA", type = FIELD),
        @TADescription(annotation = "TB", type = FIELD,
                genericLocation = { 3, 0 }),
        @TADescription(annotation = "TC", type = FIELD,
                genericLocation = { 3, 1 }),
        @TADescription(annotation = "TD", type = FIELD,
                genericLocation = { 3, 1, 3, 0 })
    })
    public String interfacefieldAsParametrized() {
        return "interface Test { @TA Map<@TB String, @TC List<@TD String>> test = null; }";
    }


    @TADescriptions({
        @TADescription(annotation = "TA", type = FIELD),
        @TADescription(annotation = "TB", type = FIELD,
                genericLocation = { 3, 0 }),
        @TADescription(annotation = "TC", type = FIELD,
                genericLocation = { 3, 1 }),
        @TADescription(annotation = "TD", type = FIELD,
                genericLocation = { 3, 1, 3, 0 })
    })
    public String staticFieldAsParametrized() {
        return "static @TA Map<@TB String, @TC List<@TD String>> test;";
    }

}
