


class T8020715 {
    
    private static  void  makeTask1() {
        class LocalClass {
            private Runnable r = () -> {};
        }
    }

    
    private  void  makeTask2() {
        class LocalClass {
            private Runnable r = () -> {};
        }
    }

    
    private class InnerClass {
        private Runnable r = () -> {};
    }
}
