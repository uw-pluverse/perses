

import java.io.*;
import java.util.function.*;

class TESTTargetType {

    public TESTTargetType() {
    }

    public void write(ObjectOutput out) throws IOException {
        Object res = (Predicate<String> & Serializable) ((str) -> str.length() > 3);
        out.writeObject(res);
    }

    public void readCheck(ObjectInput in) throws Exception {
        in.readObject();
    }
}
