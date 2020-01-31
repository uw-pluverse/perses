



public class MethodRefNewInnerBootstrap {

    interface Constructor {
        public MyTest execute(int i);
    }

    public class MyTest {
        public MyTest(int i) { System.out.println("Constructor executed " + i); }
    }

    public Constructor getConstructor() {
        return MyTest::new;
    }

    public static void main(String argv[]) {
        new MethodRefNewInnerBootstrap().call();
    }

    public void call() {
        MyTest mt = new MyTest(0);

        Constructor c1 = MyTest::new;
        c1.execute(1);

        Constructor c2 = getConstructor();
        c2.execute(2);

        Constructor c3 = new Constructor() {
            public MyTest execute(int i) {
                return new MyTest(3);
            }
        };
        c3.execute(3);

        Constructor c4 = new Constructor() {
            public MyTest execute(int i) {
                Constructor c = MyTest::new;
                return c.execute(i);
            }
        };
        c4.execute(4);
    }
}
