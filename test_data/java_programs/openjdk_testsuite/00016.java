

package P2;

public class usePub extends P1.pub {
    void bar () {
        P1.pubExposePriv pd = new P1.pubExposePriv(new P1.pub());
        P1.pubExposePriv pe = new P1.pubExposePriv(new P1.pub()){};
        P1.pubExposePriv pf = new P1.pubExposePriv(null){};
        P1.pub p = new P1.pub();
        p.foo();
        this.foo();
        foo();
    }

    public static void main(String[] args) {
        (new usePub()).bar();
    }
}
