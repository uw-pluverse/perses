




import java.io.Serializable;

public class WarnSerializableLambda {
    interface SAM {
        void apply(String s);
    }

    private void m1() {
        SAM s = (SAM & Serializable) c -> {
            packageField = "";
        };
    }

    String packageField;
}
