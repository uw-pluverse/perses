

import java.io.*;

interface ITargetName extends Serializable {
    String get();
}

class TESTTargetName {

    public TESTTargetName() {
    }

    public void write(ObjectOutput out) throws IOException {
        ITargetName resist = () -> "fubar";
        out.writeObject(resist);
    }

    public void readCheck(ObjectInput in) throws Exception {
        ITargetName lam = (ITargetName) in.readObject();
        Object val = lam.get();
        if (!val.equals("fubar")) {
            throw new IllegalArgumentException("Expected 'fubar'");
        }
    }
}
