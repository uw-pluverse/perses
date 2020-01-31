



public class T6541876b {

    enum ENUM {
        ENUM_CONST {
            public AbstractClass method() {
                return new AbstractClass() {
                    public boolean method() {
                        return true;
                    }
                };
            }
        };

        public abstract AbstractClass method();

        private abstract class AbstractClass {
            public abstract boolean method();
        }
    }

    public static void main(String[] args) {
        ENUM.ENUM_CONST.method();
    }
}
