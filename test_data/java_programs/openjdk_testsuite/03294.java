



interface SuperInterface {}

interface CrashUsingReturningThisRefLambdaFromDefaultMetTest extends SuperInterface {
    default Runnable getAction() {
        return () -> {
            SuperInterface.super.getClass();
            this.getClass();
            CrashUsingReturningThisRefLambdaFromDefaultMetTest.this.getClass();
        };
    }
}
