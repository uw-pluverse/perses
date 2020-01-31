

import java.io.*;
import java.nio.*;
import java.nio.channels.*;


public class CheckClassFileVersion {

    static String get(String fn) throws IOException {
        ByteBuffer bb = ByteBuffer.allocate(1024);
        FileChannel fc = new FileInputStream(fn).getChannel();
        try {
            bb.clear();
            if (fc.read(bb) < 0)
                throw new IOException("Could not read any bytes");
            bb.flip();
            int minor = bb.getShort(4);
            int major = bb.getShort(6);
            return major + "." + minor;
        } finally {
            fc.close();
        }
    }

    public static void main(String[] args) throws IOException {
        String cfv = get(args[0]);
        if (args.length == 1) {
            System.out.println(cfv);
            return;
        }
        if (!cfv.equals(args[1])) {
            System.err.println("Class-file version mismatch: Expected "
                               + args[1] + ", got " + cfv);
            System.exit(1);
        }
    }

}
