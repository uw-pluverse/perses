



import java.io.*;

abstract class AChurchBoolean {
    public abstract <Return, Parameter, Throws extends Throwable>
    Return accept(IVisitor<Return, Parameter, Throws> visitor, Parameter parameter) throws Throws;

    public interface IVisitor<Return, Parameter, Throws extends Throwable> {
        public Return caseTrue(Parameter parameter) throws Throws;
        public Return caseFalse(Parameter parameter) throws Throws;
    }
}

class TrueChurchBoolean extends AChurchBoolean {
    private static TrueChurchBoolean instance = new TrueChurchBoolean();
    private TrueChurchBoolean() {}
    public static TrueChurchBoolean singleton() {
        return instance;
    }
    public <Return, Parameter, Throws extends Throwable>
    Return accept(IVisitor<Return, Parameter, Throws> visitor, Parameter parameter) throws Throws {
        return visitor.caseTrue(parameter);
    }
}

class FalseChurchBoolean extends AChurchBoolean {
    private static FalseChurchBoolean instance = new FalseChurchBoolean();
    private FalseChurchBoolean() {}
    public static FalseChurchBoolean singleton() {
        return instance;
    }
    public <Return, Parameter, Throws extends Throwable>
    Return accept(IVisitor<Return, Parameter, Throws> visitor, Parameter parameter) throws Throws {
        return visitor.caseFalse(parameter);
    }
}

class Pair<T,U> {
    private T first;
    private U second;
    Pair(T first, U second) {
        this.first = first;
        this.second = second;
    }
    T getFirst() {
        return first;
    }
    U getSecond() {
        return second;
    }
}


class ChurchBooleanTest {
    private AChurchBoolean bool;
    public ChurchBooleanTest(AChurchBoolean bool) {
        this.bool = bool;
    }
    public AChurchBoolean readIf(File file, byte[] output) throws IOException {
        return bool.accept(new AChurchBoolean.IVisitor<AChurchBoolean, Pair<File, byte[]>, IOException>() {
            public AChurchBoolean caseTrue(Pair<File, byte[]> parameter) throws IOException {
                FileInputStream input = new FileInputStream(parameter.getFirst()); 
                input.read(parameter.getSecond()); 
                input.close(); 
                return TrueChurchBoolean.singleton();
            }
            public AChurchBoolean caseFalse(Pair<File, byte[]> parameter) throws IOException {
                return FalseChurchBoolean.singleton();
            }
        }, new Pair<File, byte[]>(file, output));
    }
}
