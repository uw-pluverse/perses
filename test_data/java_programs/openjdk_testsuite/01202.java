



class DuplicateCaseLabel {
    String m(int arg) {
        switch (arg) {
            case 0: return "zero";
            case 1: return "one";
            case 1: return "one";
        }
    }
}
