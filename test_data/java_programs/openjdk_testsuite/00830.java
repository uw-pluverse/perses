

package java.lang;

public class Boolean
{
    public static Boolean valueOf(boolean v) {
        return new Boolean(v);
    }

    public Boolean(boolean v) {
        value = v;
    }

    public boolean booleanValue() {
        return value;
    }

    private boolean value;
}
