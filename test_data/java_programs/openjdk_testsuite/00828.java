

package java.lang;

public class Byte
{
    public static Byte valueOf(byte v) {
        return new Byte(v);
    }

    public Byte(byte v) {
        value = v;
    }

    public byte byteValue() {
        return value;
    }

    private byte value;
}
