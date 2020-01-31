



class UnreachableCatch {

    void test() {
        try {
            throw new java.io.FileNotFoundException();
        }
        catch(java.io.FileNotFoundException exc) { }
        catch(java.io.IOException exc) { } 
    }
}
