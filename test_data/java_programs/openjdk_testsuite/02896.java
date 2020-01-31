



class T8051958 {
    Runnable inst_r = ()-> {
        final int x;
        x = 1;
    };

    Runnable static_r = ()-> {
        final int x;
        x = 1;
    };

    {
        Runnable inst_r = ()-> {
            final int x;
            x = 1;
        };
    }

    static {
        Runnable static_r = ()-> {
            final int x;
            x = 1;
        };
    }

    void instTest() {
        Runnable static_r = ()-> {
            final int x;
            x = 1;
        };
    }

    static void staticTest() {
        Runnable static_r = ()-> {
            final int x;
            x = 1;
        };
    }
}
