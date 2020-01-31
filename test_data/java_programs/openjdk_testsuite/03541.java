



import java.io.FileInputStream;
import java.io.IOException;
import java.io.File;


public class TestTwr09 {

    
    String test1() {
        String ret = null;
        try (ResCloseable tr = new ResCloseable(new ResCloseable("throw from inner resource ctor",3))) {
            ret = "FAIL";
        } catch (RuntimeException re) {
            ret = re.getMessage();
        }
        return ret;
    }

    
    String test2() {
        String ret = null;
        byte[] buf = new byte[1];
        try (java.io.ByteArrayInputStream tr = new java.io.ByteArrayInputStream(buf);
            ResCloseable str = new ResCloseable("throw from inner resource ctor",3)) {
            ret = "FAIL";
        } catch (final IOException fe) {
            ret = "FAIL test2";
        } catch (RuntimeException re) {
            ret = "PASS test2";
        }
        System.out.println("Ret = " + ret);
        return ret;
    }

    public static void main(String... args) {
        TestTwr09 t = new TestTwr09();
        if (t.test1().compareTo("throw from inner resource ctor") != 0) {
            throw new RuntimeException("FAIL-test1");
        }
        if (t.test2().compareTo("PASS test2") != 0) {
            throw new RuntimeException("FAIL-test2");
        }
    }
}


class ResCloseable implements AutoCloseable {

    ResCloseable testres = null;
    String msg = "default";
    boolean bOpen = false;

    public ResCloseable() {
        bOpen = true;
    }

    public ResCloseable(ResCloseable tr) {
        bOpen = true;
        msg = tr.getMsg();
    }

    public ResCloseable(String s) {
        bOpen = true;
        msg = s;
    }

    public ResCloseable(String msg, int c) {
        bOpen = true;
        if (c == 3) {
            throw new RuntimeException(msg);
        }
    }

    @Override
    public void close() {
        bOpen = false;
    }

    public boolean isOpen() {
        return bOpen;
    }

    public String getMsg() {
        return msg;
    }
}

