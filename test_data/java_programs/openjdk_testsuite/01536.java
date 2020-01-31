



class ConstExprRequired {
    int i = 3;

    String m(int arg) {
        switch (arg) {
            case 0: return "zero";
            case 1: return "one";
            case i: return "i";
        }
    }
}
