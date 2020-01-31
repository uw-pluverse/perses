

class BadAccess03 {
    void test() {
        int k = 0;
        int n = 2; 
        Runnable r = ()-> { k = n; }; 
    }
}
