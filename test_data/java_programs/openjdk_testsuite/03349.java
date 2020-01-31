



public class SuperField extends B {
    class IC extends B {
        IC(String name) { super(name); }
        void doCheck() {
            if (SuperField.super.ref.name != "obj.super.ref")
                throw new Error();
        }
    }
    protected B ref = null;

    SuperField(String name) { super(name); }

    public static void main(String[] args) {
        SuperField obj = new SuperField("obj");
        obj.ref = new SuperField("obj.ref");
        obj.put(new SuperField("obj.super.ref"));
        IC ins = obj.new IC("ins");
        ins.doCheck();
    }

}

class B {
    String name;
    protected B ref;

    B(String name) { this.name = name; }
    void put(B b) { ref = b; }

    class S {
        String get() { return name; }
    }
}
