



class T4718134 {
    void f(int x) {
        final int i;
        L: {
            if (x==0) break L;
            try {
                i = 3;
                break L; 
            } finally {
                return; 
            }
        }
        i = 2; 
    }
}
