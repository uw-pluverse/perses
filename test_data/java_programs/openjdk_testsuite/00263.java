



interface I1 { Number m(); }
interface I2 { String m(); }

public class T4856983a {
    <T extends I1 & I2> T f() { return null; }
}
