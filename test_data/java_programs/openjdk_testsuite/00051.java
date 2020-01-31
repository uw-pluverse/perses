



public class X {
    <T extends X> T f1() throws Exception { return null; }
    <U extends X> U f2() throws Exception { return f1(); }
}
