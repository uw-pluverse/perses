

class T7086595 {

    String s = "x";
    String s = nonExistent;

    int foo() {
        String s = "x";
        String s = nonExistent;
    }

    static int bar() {
        String s = "x";
        String s = nonExistent;
    }

    {
        String s = "x";
        String s = nonExistent;
    }

    static {
        String s = "x";
        String s = nonExistent;
    }
}
