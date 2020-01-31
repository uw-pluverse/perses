


class GraphicalInstaller  {
    private BackgroundInstaller backgroundInstaller;

    private void installNext() {
        final Integer x = 0;
        class X {
          Object o = new Object() { int y = x; };
        };
        new X();
        if (false) {
            new Runnable(){
                public void run() {
                }
            };
        }
    }

    private void installSuiteCommon() {
        backgroundInstaller = new BackgroundInstaller();
    }

    private static class BackgroundInstaller {
        private BackgroundInstaller() {
        }
    }
}
