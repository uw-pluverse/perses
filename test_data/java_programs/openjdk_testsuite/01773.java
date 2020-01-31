



class FallThrough {
    int x;
    void f(int i) {
        switch (i) {
        case 0:
            x = 0;
        case 1:
        case 2:
            x = 2;
            break;
        default:
            x = 3;
        }
    }
}
