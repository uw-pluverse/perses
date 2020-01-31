

import java.lang.annotation.*;



class RepeatingTypeAnnotations {
    
    @RTA @RTA Object fr1 = null;
    Object fr2 = new @RTA @RTA Object();
    
    Object fs = new @TA @TA Object();
    
    Object ft = new @TA @TA Object();
    Object fe = new @TA @TA Object();

    
    Object foo() {
        Object o = new @RTA @RTA Object();
        o = new @TA @RTA @RTA Object();
        o = new @RTA @TA @RTA Object();
        
        o = new @RTA @TA @RTA @TA Object();
        
        return new @TA @TA Object();
    }

    
    Object bar() {
        Object o = new @RTA @RTA MyList<@RTA @RTA Object>();
        o = new @TA @RTA MyList<@TA @RTA Object>();
        o = new @TA @RTA @RTA MyList<@RTA @TA @RTA Object>();
        
        o = new @TA @TA MyList<@RTA @RTA Object>();
        
        o = new @RTA @RTA MyList<@TA @TA Object>();
        
        return new @TA @TA MyList<@RTA @RTA Object>();
    }

    
    void oneArg() {
        Object o = new @RTA @RTA Object();
        
        o = new @TA @TA Object();
        o = new @RTA @TA @RTA Object();

        o = new MyList<@RTA @RTA Object>();
        
        o = new MyList<@TA @TA Object>();
        
        o = new @TA @TA MyList<@TA @TA Object>();
        
        this.<@TA @TA String>newList();

        this.<@RTA @RTA MyList<@RTA @RTA String>>newList();
        
        this.<@TA @TA MyList<@TA @TA String>>newList();

        o = (@RTA @RTA MyList<@RTA @RTA Object>) o;
        
        o = (@TA @TA MyList<@TA @TA Object>) o;

        this.<@RTA @RTA String, @RTA @RTA Object>newMap();
        
        this.<@TA @TA String, @TA @TA Object>newMap();

        this.<@RTA @RTA String @RTA @RTA []>newList();
        
        this.<@TA @TA String @TA @TA []>newList();

        this.<@RTA @RTA String @RTA @RTA [] @RTA @RTA [], MyList<@RTA @RTA String> @RTA @RTA []>newMap();
        
        this.<String @TA @TA [] @TA @TA [], MyList<@TA @TA String> @TA @TA []>newMap();
    }

    static <E> void newList() { }
    static <K, V> void newMap() { }
}

class MyList<E> { }


@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface TA { }

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface TAs {
    TA[] value();
}

@Repeatable(RTAs.class)
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface RTA { }

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface RTAs {
    RTA[] value();
}
