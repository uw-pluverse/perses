



import com.sun.tools.javac.util.*;

public class T6366196 {
    public static final int MIDLINE = Position.MAXPOS>>>Position.LINESHIFT; 

    public static void main(String[] args) {
        positiveTest(10, Position.MAXCOLUMN);
        negativeTest(20, Position.MAXCOLUMN + 1);
        positiveTest(MIDLINE, Position.MAXCOLUMN);
        positiveTest(Position.MAXLINE, 40);
        negativeTest(Position.MAXLINE, Position.MAXCOLUMN);
        negativeTest(Position.MAXLINE + 1, 1);
    }

    public static void positiveTest(int line, int col) {
        if (Position.encodePosition(line, col) == Position.NOPOS) {
            throw new Error("test failed at line = " + line + ", column = " + col);
        } else {
            System.out.println("test passed at line = " + line + ", column = " + col);
        }
    }

    public static void negativeTest(int line, int col) {
        if (Position.encodePosition(line, col) != Position.NOPOS) {
            throw new Error("test failed at line = " + line + ", column = " + col);
        } else {
            System.out.println("test passed at line = " + line + ", column = " + col);
        }
    }
}
