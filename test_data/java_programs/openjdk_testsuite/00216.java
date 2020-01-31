

public class DiamondPlusUnexistingMethodRefCrashTest<T> {
    DiamondPlusUnexistingMethodRefCrashTest<String> m =
        new DiamondPlusUnexistingMethodRefCrashTest<>(DiamondPlusUnexistingMethodRefCrashTest::doNotExists);
}
