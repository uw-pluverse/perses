



public class Private {
    private void m() {}
}

class Bar extends Private {
    @Override
    private void m() {}
}
