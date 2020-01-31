





@interface Anno { }

class TypeAnnotationsNotSupported {
    void m() {
        int i = (@Anno int) 3.14;
    }
}
