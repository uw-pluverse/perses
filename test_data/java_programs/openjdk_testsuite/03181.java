

import java.io.*;

interface INameOfCapturedArgs extends Serializable {
    int get();
}

class TESTNameOfCapturedArgs {

    public TESTNameOfCapturedArgs() {
    }

    public void write(ObjectOutput out) throws IOException {
        int x = 44;
        INameOfCapturedArgs res = () -> x;
        out.writeObject(res);
    }

    public void readCheck(ObjectInput in) throws Exception {
        INameOfCapturedArgs lam = (INameOfCapturedArgs) in.readObject();
        int val = lam.get();
        if (val != 44) {
            throw new IllegalArgumentException("Expected 44");
        }
    }
}
