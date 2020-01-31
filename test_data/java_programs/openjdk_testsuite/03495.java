



import java.security.*;
public class T6379327 {
    public static void main(String[] args) {
        final String name = args[0];
        try {
            new PrivilegedExceptionAction() {
                public Object run() throws ClassNotFoundException {
                    return Class.forName(name);
                }
            };
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
