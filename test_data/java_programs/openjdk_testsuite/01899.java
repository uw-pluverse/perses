



import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import javax.annotation.processing.*;
import javax.lang.model.SourceVersion;
import javax.lang.model.element.*;
import javax.lang.model.type.*;
import javax.lang.model.util.*;

public class TypeParamBounds extends JavacTestingAbstractProcessor {
    public boolean process(Set<? extends TypeElement> annoTypes,
                           RoundEnvironment round) {
        if (!round.processingOver())
            doit(annoTypes, round);
        return true;
    }

    private void doit(Set<? extends TypeElement> annoTypes,
                      RoundEnvironment round) {
        TypeElement gen = elements.getTypeElement("TypeParamBounds.Gen");

        
        
        
        for (TypeParameterElement tparam : gen.getTypeParameters()) {
            System.out.println(tparam);
            List<? extends TypeMirror> bounds = tparam.getBounds();
            String[] expected = Gen.boundNames.get(tparam + "");

            if (bounds.size() != expected.length)
                throw new AssertionError();
            int i = 0;
            for (TypeMirror bound : bounds) {
                Name got = types.asElement(bound).getSimpleName();
                String shoulda = expected[i++];
                System.out.println("  " + got);
                if (!got.contentEquals(shoulda))
                    throw new AssertionError(shoulda);
            }
        }
    }


    
    static class Gen<T, U extends Object, V extends Number, W extends U,
                     X extends Runnable, Y extends CharSequence & Runnable,
                     Z extends Object & Runnable> {

        
        static Map<String, String[]> boundNames =
                new HashMap<String, String[]>();

        static {
            boundNames.put("T", new String[] {"Object"});
            boundNames.put("U", new String[] {"Object"});
            boundNames.put("V", new String[] {"Number"});
            boundNames.put("W", new String[] {"U"});
            boundNames.put("X", new String[] {"Runnable"});
            boundNames.put("Y", new String[] {"CharSequence", "Runnable"});
            boundNames.put("Z", new String[] {"Object", "Runnable"});
        }
    }
}
