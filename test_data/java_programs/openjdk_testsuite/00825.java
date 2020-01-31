

package java.lang;

public class Short extends Number
{
    public static Short valueOf(short v) {
        return new Short(v);
    }

    public Short(short v) {
        value = v;
    }

    public short shortValue() {
        return value;
    }

    private short value;
}
