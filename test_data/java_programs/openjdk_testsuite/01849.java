


import java.lang.annotation.*;
import java.math.BigDecimal;
import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.*;
import javax.lang.model.element.*;
import javax.lang.model.type.*;
import javax.lang.model.util.*;

@P0
@P1
@P2
@S1
public class Plurality extends JavacTestingAbstractProcessor {
    private boolean executed = false;

    public boolean process(Set<? extends TypeElement> annotations,
                           RoundEnvironment roundEnv) {
        if (!roundEnv.processingOver()) {
            executed = true;
            
            Element e = elements.getTypeElement("Plurality");
            Class[] classes = null;

            P0 p0 = e.getAnnotation(P0.class);
            try {
                classes = p0.value();
            } catch (MirroredTypesException mtse) {
                if (mtse instanceof MirroredTypeException) {
                    throw new RuntimeException("Wrong exception type!");
                }

                List<? extends TypeMirror> types = mtse.getTypeMirrors();
                if (types.size() != 0)
                    throw new RuntimeException("List size != 0: " +
                                               types);
            }

            P1 p1 = e.getAnnotation(P1.class);
            try {
                classes = p1.value();
            } catch (MirroredTypesException mtse) {
                if (mtse instanceof MirroredTypeException) {
                    throw new RuntimeException("Wrong exception type!");
                }

                List<? extends TypeMirror> types = mtse.getTypeMirrors();
                if (types.size() != 1)
                    throw new RuntimeException("List size != 1: " +
                                               types);
                checkTypeListMatchesClasses(types,
                                            this.getClass().getAnnotation(P1.class).value());
            }


            P2 p2 = e.getAnnotation(P2.class);
            try {
                classes = p2.value();
            } catch(MirroredTypesException mtse) {
                if (mtse instanceof MirroredTypeException) {
                    throw new RuntimeException("Wrong exception type!");
                }

                List<? extends TypeMirror> types = mtse.getTypeMirrors();
                if (types.size() != 2)
                    throw new RuntimeException("List size != 2: " +
                                               types);
                checkTypeListMatchesClasses(types,
                                            this.getClass().getAnnotation(P2.class).value());
            }

            Class<?> clazz = null;
            S1 s1 = e.getAnnotation(S1.class);
            try {
                clazz = s1.value();
            } catch(MirroredTypesException mtse) {
                List<? extends TypeMirror> types = mtse.getTypeMirrors();
                if (types.size() != 1)
                    throw new RuntimeException("List size != 1: " +
                                               types);
                Class<?>[] clazzes = new Class<?>[1];
                clazzes[0] = this.getClass().getAnnotation(S1.class).value();
                checkTypeListMatchesClasses(types,
                                            clazzes);
            }

            try {
                clazz = s1.value();
            } catch(MirroredTypeException mte) {
                TypeMirror type = mte.getTypeMirror();
                if (type == null) {
                    throw new RuntimeException("Expected null");
                }
                List<TypeMirror> types = new ArrayList<>();
                types.add(type);
                Class<?>[] clazzes = new Class<?>[1];
                clazzes[0] = this.getClass().getAnnotation(S1.class).value();
                checkTypeListMatchesClasses(types, clazzes);
            }
        } else {
            if (!executed) {
                throw new RuntimeException("Didn't seem to do anything!");
            }
        }
        return true;
    }

    private static void checkTypeListMatchesClasses(List<? extends TypeMirror> types,
                                               Class<?>[] classes) {
        if (types.size() != classes.length)
            throw new RuntimeException("Size mismatch:\n\t" + types +
                                       "\n\t" + Arrays.toString(classes));
        int i = -1;
        for(Class<?> clazz : classes) {
            i++;
            String canonicalName = clazz.getCanonicalName();
            String toStringName = types.get(i).toString();
            if (!canonicalName.equals(toStringName))
                throw new RuntimeException("Mismatched names: " +
                                           canonicalName + "\t" +
                                           toStringName);
        }
    }
}

@Retention(RetentionPolicy.RUNTIME)
@interface P0 {
    Class[] value() default {};
}

@Retention(RetentionPolicy.RUNTIME)
@interface P1 {
    Class[] value() default {Integer.class};
}

@Retention(RetentionPolicy.RUNTIME)
@interface P2 {
    Class[] value() default {String.class, Number.class};
}

@Retention(RetentionPolicy.RUNTIME)
@interface S1 {
    Class value() default BigDecimal.class;
}
