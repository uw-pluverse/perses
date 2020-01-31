



class InitializerCompletion_4 {
    static boolean stop = true;
    static {
        if (stop)
            throw new RuntimeException();
    }
}
