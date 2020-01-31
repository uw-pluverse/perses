

package java.lang;

public class Integer extends Number
{
    public static Integer valueOf(int v) {
        return new Integer(v);
    }

    public Integer(int v) {
        value = v;
    }

    public int integerValue() {
        return value;
    }

    private int value;
}
