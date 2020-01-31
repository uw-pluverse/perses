



import java.util.*;
import java.lang.reflect.*;
import java.lang.annotation.*;



@ExpectedModifiers(Modifier.FINAL)
public enum EnumImplicitPrivateConstructor {
    RED(255, 0, 0),
    GREEN(0, 255, 0),
    BLUE(0, 0, 255);

    private int r, g, b;
    EnumImplicitPrivateConstructor(int r, int g, int b) {
        this.r = r;
        this.g = g;
        this.b = b;
    }

    
    public static void main(String argv[]) throws Exception {
        boolean passed = true;

        Collection<Class> classes = new LinkedHashSet<Class>();

        classes.add(Class.forName("EnumImplicitPrivateConstructor"));
        classes.add(Class.forName("EnumImplicitPrivateConstructor$AnotherEnum"));
        classes.add(Class.forName("EnumImplicitPrivateConstructor$YetAnotherEnum"));
        classes.add(Class.forName("EnumImplicitPrivateConstructor$OneMoreEnum"));

        
        for(Enum e: YetAnotherEnum.values())
            classes.add(e.getClass());

        for(Class clazz: classes) {
            System.out.println("Testing class " + clazz);

            int classModifiers = clazz.getModifiers();

            
            ExpectedModifiers em = (ExpectedModifiers)clazz.getAnnotation(ExpectedModifiers.class);
            if (em != null) {
                System.out.println("\tTesting expected modifiers");
                int expected = em.value();

                if (expected != (classModifiers & (Modifier.ABSTRACT|Modifier.FINAL|Modifier.STATIC))) {
                    passed = false;
                    System.out.println("\tFAILED: Expected 0x" + Integer.toHexString(expected) +
                                       " got 0x" +Integer.toHexString(classModifiers));
                }
            }

            for(Constructor ctor: clazz.getDeclaredConstructors() ) {
                System.out.println("\tTesting constructor " + ctor);

                
                try {
                    ctor.setAccessible(true);
                } catch (java.security.AccessControlException ex) {
                }

                int modifiers = ctor.getModifiers();

                
                if (clazz.isEnum()) {
                    if ((modifiers & Modifier.PRIVATE) == 0 &&
                        ! ctor.isSynthetic() ) {
                        passed = false;
                        System.out.println("\tFAILED: Constructor not marked private: modifiers 0x" +
                                           Integer.toHexString(modifiers));
                    }
                }

                try {
                    
                    Object o = null;
                    try {
                        o = ctor.newInstance("abc", 123);
                    } catch (IllegalAccessException ex) {
                    }

                    

                    if (o != null) {
                        passed = false;
                        System.err.println("Error: Created new enum object!");
                        System.err.println(o.getClass());
                        System.err.println(o.toString());
                    }
                } catch (IllegalArgumentException iae) {}

            }
        }

        if (!passed)
            throw new RuntimeException("Error during testing.");
    }


    
    @ExpectedModifiers(Modifier.FINAL|Modifier.STATIC)
    enum AnotherEnum {
        YELLOW,
        CYAN,
        MAGENTA;
    }

    
    @ExpectedModifiers(Modifier.STATIC)
    enum YetAnotherEnum {
        GREEN {
            int value(){ return 1;}
        },

        ORANGE {
            int value(){ return 2;}
        },

        VIOLET {
            int value(){ return 3;}
        };

        int value(){ return 0;}
    }

    
    @ExpectedModifiers(Modifier.ABSTRACT|Modifier.STATIC)
    enum OneMoreEnum {
        SANGUINE {
            int value(){ return 1;}
        },

        VERDANT {
            int value(){ return 2;}
        },

        CERULEAN {
            int value(){ return 3;}
        };

        abstract int value();
    }
}

@Retention(RetentionPolicy.RUNTIME)
@interface ExpectedModifiers {
    int value();
}
