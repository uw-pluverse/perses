



interface InterfaceObjectInheritance {
    class Inner {
        static void bar(InterfaceObjectInheritance i) {
            try {
                
                
                
                i.finalize();
            } catch (Throwable t) {
            }
        }
    }
}
