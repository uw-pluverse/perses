



package _enum.def;

enum Def {
    red;

    {
        int i = 4;
        switch (i) {
        case N: break;
        }
    }

    public final static int N = 12;

    Def() {
        k = N;
    }

    int k;
}
