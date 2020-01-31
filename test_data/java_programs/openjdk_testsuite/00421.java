



import java.util.*;

class CastTest {

    

    private class AA<T> { }

    private class AB<T> extends AA<T> { }
    private class AC<T> extends AA<Vector<T>> { }
    private class AD<T> extends AA<Vector<? extends T>> { }
    private class AE<T> extends AA<Vector<? super T>> { }
    private class AF<T> extends AA<T[]> { }
    private class AG<T> extends AA<String> { }

    private void parameterTransfer() {
        Object o;

        o = (AB<String>) (AA<String>) null; 
        o = (AB<String>) (AA<Number>) null; 
        o = (AC<String>) (AA<Vector<String>>) null; 
        o = (AC<String>) (AA<Vector<Number>>) null; 
        o = (AC<String>) (AA<Stack<String>>) null; 

        o = (AD<Number>) (AA<Vector<? extends Number>>) null; 
        o = (AD<String>) (AA<Vector<? extends Number>>) null; 
        o = (AD<?>) (AA<Vector<? extends Object>>) null; 
        o = (AD<Object>) (AA<Vector<?>>) null; 

        o = (AE<String>) (AA<Vector<? super String>>) null; 
        o = (AE<Number>) (AA<Vector<? super String>>) null; 

        o = (AF<String>) (AA<String[]>) null; 
        o = (AF<String>) (AA<Number[]>) null; 

        o = (AG<?>) (AA<String>) null; 
        o = (AG<?>) (AA<Number>) null; 
    }

    

    private class BA<T> { }
    private class BB<T, S> { }

    private class BC<T> extends BA<Integer> { }
    private class BD<T> extends BB<T, T> { }

    private void inconsistentMatches() {
        Object o;

        o = (BC<?>) (BA<Integer>) null; 
        o = (BC<?>) (BA<String>) null; 
        o = (BD<String>) (BB<String, String>) null; 
        o = (BD<String>) (BB<String, Number>) null; 
        o = (BD<String>) (BB<Number, String>) null; 
    }

    private void whyMustEverythingBeSo_______Complicated() {
        
        BD<Number> bd = new BD<Number>();
        BB<? extends Number, ? super Integer> bb = bd;
        
        
    }

    

    private interface CA<T> { }
    private interface CB<T> extends CA<T> { }
    private interface CC<T> extends CA<T> { }

    private class CD<T> implements CB<T> { }
    private interface CE<T> extends CC<T> { }

    private interface CF<S> { }
    private interface CG<T> { }
    private class CH<S, T> implements CF<S>, CG<T> { }
    private interface CI<S> extends CF<S> { }
    private interface CJ<T> extends CG<T> { }
    private interface CK<S, T> extends CI<S>, CJ<T> { }

    private void supertypeParameterTransfer() {
        Object o;
        CD<?> cd = (CE<?>) null; 
        CE<?> ce = (CD<?>) null; 
        o = (CE<String>) (CD<String>) null; 
        o = (CE<Number>) (CD<String>) null; 

        
        
    }

    

    private interface DA<T> { }
    private interface DB<T> extends DA<T> { }
    private interface DC<T> extends DA<Integer> { }

    private <N extends Number, I extends Integer, R extends Runnable, S extends String> void disjointness() {
        Object o;

        
        o = (DA<Number>) (DA<Integer>) null; 
        o = (DA<? extends Number>) (DA<Integer>) null; 
        o = (DA<? extends Integer>) (DA<Number>) null; 
        o = (DA<? super Integer>) (DA<Number>) null; 
        o = (DA<? super Number>) (DA<Integer>) null; 
        o = (DA<?>) (DA<Integer>) null; 

        o = (DA<? extends Runnable>) (DA<? extends Number>) null; 
        o = (DA<? extends Runnable>) (DA<? extends String>) null; 

        o = (DA<? super Integer>) (DA<? extends Number>) null; 
        o = (DA<? super Number>) (DA<? extends Integer>) null; 
        o = (DA<?>) (DA<? extends Integer>) null; 

        o = (DA<? super String>) (DA<? super Number>) null; 
        o = (DA<?>) (DA<? super String>) null; 

        o = (DA<?>) (DA<?>) null; 

        
        o = (DA<? extends Number>) (DA<I>) null; 
        o = (DA<? extends Integer>) (DA<N>) null; 
        o = (DA<? extends String>) (DA<I>) null; 

        o = (DA<I>) (DA<? extends Number>) null; 
        o = (DA<N>) (DA<? extends Integer>) null; 
        o = (DA<N>) (DA<? extends Runnable>) null; 

        o = (DA<N>) (DA<I>) null; 
        o = (DA<N>) (DA<R>) null; 
        o = (DA<S>) (DA<R>) null; 

        
        o = (DA) (DB<Number>) null; 
        o = (DA<Number>) (DB) null; 
        o = (DA<?>) (DB) null; 
        o = (DA<? extends Object>) (DB) null; 
        o = (DA<? extends Number>) (DB) null; 

        o = (DB) (DA<Number>) null; 
        o = (DB<Number>) (DA) null; 
        o = (DB<?>) (DA) null; 
        o = (DB<? extends Object>) (DA) null; 
        o = (DB<? extends Number>) (DA) null; 

        o = (DC<?>) (DA<?>) null; 
        o = (DC<?>) (DA<? super String>) null; 
    }

}
