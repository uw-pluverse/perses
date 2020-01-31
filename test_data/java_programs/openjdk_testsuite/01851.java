



import javax.lang.model.type.TypeKind;
import static javax.lang.model.type.TypeKind.*;
import javax.lang.model.util.*;
import java.util.*;

public class TestTypeKind {
    static int testIsPrimitive() {
        int failures = 0;
        
        Set<TypeKind> primitives = EnumSet.of(BOOLEAN,  
                                              BYTE,     
                                              CHAR,     
                                              DOUBLE,   
                                              FLOAT,    
                                              INT,      
                                              LONG,     
                                              SHORT);   

        for(TypeKind tk : TypeKind.values()) {
            boolean primitiveness;
            if ((primitiveness=tk.isPrimitive()) != primitives.contains(tk) ) {
                failures++;
                System.err.println("Unexpected isPrimitive value " + primitiveness +
                                   "for " + tk);
            }
        }
        return failures;
    }

    public static void main(String... argv) {
        int failures  = 0;
        failures += testIsPrimitive();
        if (failures > 0)
            throw new RuntimeException();
    }
}
