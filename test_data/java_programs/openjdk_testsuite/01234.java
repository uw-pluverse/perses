




class PossibleFallThrough {
    void m(int i) {
        switch (i) {
            case 0:
                System.out.println(0);
            case 1:
                System.out.println(1);
        }
    }
}

