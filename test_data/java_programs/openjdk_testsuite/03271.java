



import static java.lang.Thread.holdsLock;
import static java.lang.Thread.holdsLock; 

class DoubleStaticImport {
    public void test() {
        holdsLock(null);
    }
}
