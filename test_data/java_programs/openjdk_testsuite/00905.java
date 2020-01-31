



import java.util.*;

public enum Enum1 {
    red, green, blue;

    public static void main(String[] args) {
        if (!Arrays.asList(values()).toString().equals("[red, green, blue]"))
            throw new Error();
    }
}
