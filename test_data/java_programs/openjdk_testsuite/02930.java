
class MissingError {
    void test() {
       mtest(new Bad(){ Integer i = ""; });
    }

    void mtest(Bad t){ }
}

class Bad {
    String s = 1;
}
