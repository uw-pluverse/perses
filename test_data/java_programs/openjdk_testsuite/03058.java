

class MostSpecific09 {

    interface I {
        String xoo(String x);
    }

    interface J {
        void xoo(int x);
    }

    static void foo(I i) {}
    static void foo(J j) {}

    static void moo(I i) {}
    static void moo(J j) {}

    void m() {
        foo((x) -> { return x += 1; });
        foo((x) -> { return ""; });
        foo((x) -> { System.out.println(""); });
        foo((x) -> { return ""; System.out.println(""); });
        foo((x) -> { throw new RuntimeException(); });
        foo((x) -> { while (true); });

        foo((x) -> x += 1);
        foo((x) -> "");
    }

    
    void m1() {
        boolean cond = true;
        foo((x) -> {
            if (cond) {
                return "";
            }
            System.out.println("");
        });

        foo((x)->{
            class Bar {
                String m() {
                    return "from Bar.m()";
                }
            }
            class Boo {
                Bar b = new Bar (){
                    String m() {
                        return "from Bar$1.m()";
                    }
                };
            }
            moo((y) -> { return ""; });
            return;
        });

        foo((x)->{
            class Bar {
                void m() {}
            }
            class Boo {
                Bar b = new Bar (){
                    void m() {
                        return;
                    }
                };
            }
            moo((y) -> { System.out.println(""); });
            return "";
        });
    }
}
