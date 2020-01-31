



package PackageClassClash;

public class PackageClassClash {
    
    
    private void foo() {}
    class Inner {
        private void bar() { foo(); }
    }
}
