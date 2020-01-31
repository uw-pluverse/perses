



class T4717164 {
    public static void main(String[] args) {
        try {
            try {
                throw new ClassNotFoundException();
            } catch (ClassNotFoundException e) {
                throw e;
            } finally {
                return; 
            }
        } catch (ClassNotFoundException e1) { 
        }
    }
}
