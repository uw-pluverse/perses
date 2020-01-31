

package java.lang;

public class Character
{
    public static Character valueOf(char v) {
        return new Character(v);
    }

    public Character(char v) {
        value = v;
    }

    public char characterValue() {
        return value;
    }

    private char value;
}
