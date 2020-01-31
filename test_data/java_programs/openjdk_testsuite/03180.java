

import java.io.*;

interface ITypesOfCapturedArgs extends Serializable {
    Object get();
}

class TESTTypesOfCapturedArgs {

    public TESTTypesOfCapturedArgs() {
    }

    public void write(ObjectOutput out) throws IOException {
        String x = "hi";
        ITypesOfCapturedArgs res = () -> x;
        out.writeObject(res);
    }

    public void readCheck(ObjectInput in) throws Exception {
        ITypesOfCapturedArgs lam = (ITypesOfCapturedArgs) in.readObject();
        Object val = lam.get();
        if (!val.equals("hi")) {
            throw new IllegalArgumentException("Expected 'hi'");
        }
    }
}
