




class LocalVarNeedsFinal {
    Runnable m() {
        int i = 3;
        return new Runnable() {
            public void run() {
                System.out.println(i);
            }
        };
    }
}
