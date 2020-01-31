



class T4725725 {
    final int x;
    final Object o = new Object() {
            int y = x; 
        };
    {
        x = 12;
    }
}
