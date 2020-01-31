

package java.lang;

public class Long extends Number
{
    public static Long valueOf(long v) {
        return new Long(v);
    }

    public Long(long v) {
        value = v;
    }

    public long longValue() {
        return value;
    }

    private long value;
}
