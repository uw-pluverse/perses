

package test;

class Target11 extends CurPackagePrivateExt11 {
    void run() {
        new Runnable() {
            public void run() {
                Target11.super.refTotestCurPackagePrivateBase11();
                Target11.super.refTotestCurPackagePrivateBase11 =
                        Target11.super.refTotestCurPackagePrivateBase11 + 1;
                Target11.super.refTotestCurPackagePrivateExt11();
                Target11.super.refTotestCurPackagePrivateExt11 =
                        Target11.super.refTotestCurPackagePrivateExt11 + 1;
                Target11.super.toString();
                refTotestCurPackagePrivateBase11();
                refTotestCurPackagePrivateBase11 =
                        refTotestCurPackagePrivateBase11 + 1;
                refTotestTarget11();
                refTotestTarget11 = refTotestTarget11 + 1;
                Target11.this.refTotestCurPackagePrivateBase11();
                Target11.this.refTotestCurPackagePrivateBase11 =
                        Target11.this.refTotestCurPackagePrivateBase11 + 1;
                Target11.this.refTotestTarget11();
                Target11.this.refTotestTarget11 =
                        Target11.this.refTotestTarget11 + 1;
            }
        }.run();
        super.refTotestCurPackagePrivateBase11();
        super.refTotestCurPackagePrivateBase11 =
                super.refTotestCurPackagePrivateBase11 + 1;
        super.refTotestCurPackagePrivateExt11();
        super.refTotestCurPackagePrivateExt11 =
                super.refTotestCurPackagePrivateExt11 + 1;
        super.toString();

        Target11.super.refTotestCurPackagePrivateBase11();
        Target11.super.refTotestCurPackagePrivateBase11 =
                Target11.super.refTotestCurPackagePrivateBase11 + 1;
        Target11.super.refTotestCurPackagePrivateExt11();
        Target11.super.refTotestCurPackagePrivateExt11 =
                Target11.super.refTotestCurPackagePrivateExt11 + 1;

        refTotestCurPackagePrivateBase11();
        refTotestCurPackagePrivateBase11 = refTotestCurPackagePrivateBase11 + 1;
        refTotestTarget11 = refTotestTarget11 + 1;
    }
}

class CurPackagePrivateBase11 extends base.Base {
    protected void refTotestCurPackagePrivateBase11() {}
    protected int refTotestCurPackagePrivateBase11;
}

class CurPackagePrivateExt11 extends CurPackagePrivateBase11 { }
