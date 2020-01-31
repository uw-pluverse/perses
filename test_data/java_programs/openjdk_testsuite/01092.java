



public class IllDefinedOrderOfInit {
    int i = m();
    int j = 0;
    IllDefinedOrderOfInit() {
        if (j != 0) {
            throw new Error();
        }
    }
    int m() { j = 5; return j++; }
    static public void main(String args[]) {
        new IllDefinedOrderOfInit();
    }
}
