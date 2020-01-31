

package base;

public class Base extends PackagePrivate { }

class PackagePrivate {
    protected int refTobaseBase() {
        return 0;
    }
    protected int refTotestOtherPackageTest() {
        return 0;
    }
    protected int refTotestTarget11() {
        return 0;
    }
    protected int refTotestCurPackagePrivateExt11() {
        return 0;
    }
    protected int refTobaseBase;
    protected int refTotestOtherPackageTest;
    protected int refTotestTarget11;
    protected int refTotestCurPackagePrivateExt11;
}
