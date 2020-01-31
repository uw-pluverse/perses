

import java.io.*;

interface IOrderOfCapturedArgs extends Serializable {
    String get();
}

class TESTOrderOfCapturedArgs {

    public TESTOrderOfCapturedArgs() {
    }

    public void write(ObjectOutput out) throws IOException {
        String a = "fu";
        String b = "bar";
        IOrderOfCapturedArgs res = () -> a + b;
        out.writeObject(res);
    }

    public void readCheck(ObjectInput in) throws Exception {
        IOrderOfCapturedArgs lam = (IOrderOfCapturedArgs) in.readObject();
        Object val = lam.get();
        if (!val.equals("fubar")) {
            throw new IllegalArgumentException("Expected 'fubar'");
        }
    }
}
