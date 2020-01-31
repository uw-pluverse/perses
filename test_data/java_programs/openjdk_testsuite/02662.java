



class T4717165 {
    void f() {
        int i;
        a: try {
            break a;
        } finally {
            return;
        }
        i = 12; 
    }
}
