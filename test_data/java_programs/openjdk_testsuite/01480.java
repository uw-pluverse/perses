



class Base {
    Base(int i) { }
}

class CantRefBeforeConstr extends Base {
    int i;

    CantRefBeforeConstr() {
        super(i);
    }
}
