

package P1;

public class pubExposePriv extends priv {
    public priv baz() { return new priv(); }
    public void bar(priv p) {}
    public pubExposePriv(priv p) {}
}
