

import java.io.Serializable;

public class WarnSerializableLambdaTestb {
     public void foo(Secret1 secret) {
         Object o = (Runnable & java.io.Serializable) () -> { secret.test(); };
     }

     public void bar(Secret2 secret) {
         Object o = (Runnable & java.io.Serializable) () -> { secret.test(); };
     }

     private class Secret1 {
         public void test() {}
     }

     static private class Secret2 {
         public void test() {}
     }

     class TestInner {
        private int j = 0;
        void m() {
            Serializable s = new Serializable() {
                int i;
                void m() {
                    i = 0;  
                    System.out.println(j); 
                }
            };
        }
    }

    class TestInner2 {
        class W implements Serializable {
            public int p = 0;
            class I {
                public int r = 0;
                class K implements Serializable {
                    void m() {
                        p = 1;  
                        r = 2;  
                    }
                }
            }
        }
    }
}
