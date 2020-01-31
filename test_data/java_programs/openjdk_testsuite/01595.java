



abstract class SerializableAbstractClassWithNonAbstractMethodsTest implements java.io.Serializable {
    void m1() {}
    abstract void m2();

    abstract class AWithUID implements java.io.Serializable {
        private static final long serialVersionUID = 0;
        void m(){}
    }

    interface IDefault extends java.io.Serializable {
        default int m() { return 1; }
    }

    interface IDefaultAndUID extends java.io.Serializable {
        static final long serialVersionUID = 0;
        default int m() { return 1; }
    }
}
