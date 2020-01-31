

import p.A;

class Test1 {
    String ss = "      p.A      yes";
    String sa = "p.A   p.A#publ yes";
    String sq = "p.A   p.A#prot no ";
    String sr = "Test2 p.A#prot no ";
    String sx = "p.A   p.A#priv no ";

    String s2 = "      Test2      yes";
    String s3 = "Test2 Test2#stat yes";

    static class Test1a {
        String s1 = "Test2 Test2#priv no";
    }
}

class Test2 extends A {
    private int priv;
    static int stat;

    String ss = "      p.A      yes";
    String sa = "p.A   p.A#publ yes";
    String sq = "p.A   p.A#prot no ";
    String sr = "Test2 p.A#prot yes";
    String sx = "p.A   p.A#priv no ";

    static class Test2a {
        String s1 = "Test2 Test2#priv yes";
    }
}
