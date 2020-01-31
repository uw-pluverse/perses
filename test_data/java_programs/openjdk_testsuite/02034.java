



class InitializerCompletion_2 {
    boolean stop = true;
    {
        if (stop)
            throw new RuntimeException();
    }
}
