
import java.lang.annotation.ElementType;
import java.lang.annotation.Target;

@Target({ElementType.METHOD, ElementType.CONSTRUCTOR})
@interface Candidate {
    
    Pos pos() default @Pos(userDefined=false);
    
    Phase[] applicable() default { };
    
    boolean mostSpecific() default false;
    
    String sig() default "";
}

enum Phase {
    BASIC("BASIC"),
    BOX("BOX"),
    VARARGS("VARARITY");

    final String javacString;

    private Phase(String javacString) {
        this.javacString = javacString;
    }

    static Phase fromString(String s) {
        for (Phase phase : Phase.values()) {
            if (phase.javacString.equals(s)) {
                return phase;
            }
        }
        throw new AssertionError("Invalid resolution phase string " + s);
    }
}
