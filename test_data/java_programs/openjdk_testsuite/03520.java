

class TwrLint implements AutoCloseable {
    private static void test1() {
        try(TwrLint r1 = new TwrLint();
            TwrLint r2 = new TwrLint();
            TwrLint r3 = new TwrLint()) {
            r1.close();   
            r2.close(42); 
            
        }

    }

    @SuppressWarnings("try")
    private static void test2() {
        try(@SuppressWarnings("deprecation") AutoCloseable r4 =
            new DeprecatedAutoCloseable()) {
            
        } catch(Exception e) {
            ;
        }
    }

    
    @Override
    public void close () {
        return;
    }

    
    public void close (int arg) {
        return;
    }
}

@Deprecated
class DeprecatedAutoCloseable implements AutoCloseable {
    public DeprecatedAutoCloseable(){super();}

    @Override
    public void close () {
        return;
    }
}
