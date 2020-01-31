



class LambdaConv17 {
    interface SAM {
       void m() throws Exception;
    }

    SAM s = ()-> { try (AutoCloseable ac = null){ } };
}
