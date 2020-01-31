



class T4718142a {
    public static void main(String[] args) {
        final int i;
        for (int n=0; n<10; n++) {
            b: {
                try {
                    if (true) break b;
                } finally {
                    i = n;
                    System.out.println("i = " + i);
                }
                return;
            }
        }
    }
}
