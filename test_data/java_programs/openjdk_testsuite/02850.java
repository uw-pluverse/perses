



public class SkipLazyConstantCreationForMethodRefTest<T> {
    SkipLazyConstantCreationForMethodRefTest(int a, boolean b) {}
    SkipLazyConstantCreationForMethodRefTest() {}
}

class SubClass<T> extends SkipLazyConstantCreationForMethodRefTest {
    SubClass(int a, boolean b) {}
}

interface SAM {
    SubClass<SkipLazyConstantCreationForMethodRefTest> m(int a, boolean b);
}

interface Tester1 {
    SAM s11 = SubClass<SkipLazyConstantCreationForMethodRefTest>::<Object>new;
    SAM s12 = (SubClass<SkipLazyConstantCreationForMethodRefTest>::<Object>new);
    SAM s13 = (SAM)SubClass<SkipLazyConstantCreationForMethodRefTest>::<Object>new;
    SAM s14 = true ? s11 : s12;
    SAM s15 = true ? s11 : (SAM)SubClass<SkipLazyConstantCreationForMethodRefTest>::<Object>new;
    SAM s16 = true ? (SAM)SubClass<SkipLazyConstantCreationForMethodRefTest>::<Object>new : s12;
}

interface Tester2 {
    SAM s21 = Tester1.s11;
}
