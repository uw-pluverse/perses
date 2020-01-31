



import org.testng.annotations.Test;

import static org.testng.Assert.assertEquals;



@Test
public class MethodReferenceTestKinds extends MethodReferenceTestKindsSup {

    interface S0 { String get(); }
    interface S1 { String get(MethodReferenceTestKinds x); }
    interface S2 { String get(MethodReferenceTestKinds x, MethodReferenceTestKinds y); }

    interface SXN0 { MethodReferenceTestKindsBase make(MethodReferenceTestKinds x); }
    interface SXN1 { MethodReferenceTestKindsBase make(MethodReferenceTestKinds x, String str); }

    interface SN0 { MethodReferenceTestKindsBase make(); }
    interface SN1 { MethodReferenceTestKindsBase make(String x); }

    class In extends MethodReferenceTestKindsBase {
        In(String val) {
            this.val = val;
        }

        In() {
            this("blank");
        }
    }

    String instanceMethod0() { return "IM:0-" + this; }
    String instanceMethod1(MethodReferenceTestKinds x) { return "IM:1-" + this + x; }

    static String staticMethod0() { return "SM:0"; }
    static String staticMethod1(MethodReferenceTestKinds x) { return "SM:1-" + x; }

    MethodReferenceTestKinds(String val) {
        super(val);
    }

    MethodReferenceTestKinds() {
        super("blank");
    }

    MethodReferenceTestKinds inst(String val) {
        return new MethodReferenceTestKinds(val);
    }

    public void testMRBound() {
        S0 var = this::instanceMethod0;
        assertEquals(var.get(), "IM:0-MethodReferenceTestKinds(blank)");
    }

    public void testMRBoundArg() {
        S1 var = this::instanceMethod1;
        assertEquals(var.get(inst("arg")), "IM:1-MethodReferenceTestKinds(blank)MethodReferenceTestKinds(arg)");
    }

    public void testMRUnbound() {
        S1 var = MethodReferenceTestKinds::instanceMethod0;
        assertEquals(var.get(inst("rcvr")), "IM:0-MethodReferenceTestKinds(rcvr)");
    }

    public void testMRUnboundArg() {
        S2 var = MethodReferenceTestKinds::instanceMethod1;
        assertEquals(var.get(inst("rcvr"), inst("arg")), "IM:1-MethodReferenceTestKinds(rcvr)MethodReferenceTestKinds(arg)");
    }

    public void testMRSuper() {
        S0 var = super::instanceMethod0;
        assertEquals(var.get(), "SIM:0-MethodReferenceTestKinds(blank)");
    }

    public void testMRSuperArg() {
        S1 var = super::instanceMethod1;
        assertEquals(var.get(inst("arg")), "SIM:1-MethodReferenceTestKinds(blank)MethodReferenceTestKinds(arg)");
    }

    public void testMRStatic() {
        S0 var = MethodReferenceTestKinds::staticMethod0;
        assertEquals(var.get(), "SM:0");
    }

    public void testMRStaticArg() {
        S1 var = MethodReferenceTestKinds::staticMethod1;
        assertEquals(var.get(inst("arg")), "SM:1-MethodReferenceTestKinds(arg)");
    }

    public void testMRTopLevel() {
        SN0 var = MethodReferenceTestKindsBase::new;
        assertEquals(var.make().toString(), "MethodReferenceTestKindsBase(blank)");
    }

    public void testMRTopLevelArg() {
        SN1 var = MethodReferenceTestKindsBase::new;
        assertEquals(var.make("name").toString(), "MethodReferenceTestKindsBase(name)");
    }

    public void testMRImplicitInner() {
        SN0 var = MethodReferenceTestKinds.In::new;
        assertEquals(var.make().toString(), "In(blank)");
    }

    public void testMRImplicitInnerArg() {
        SN1 var = MethodReferenceTestKinds.In::new;
        assertEquals(var.make("name").toString(), "In(name)");
    }

}


class MethodReferenceTestKindsBase {
    String val = "unset";

    public String toString() {
        return getClass().getSimpleName() + "(" + val + ")";
    }

    MethodReferenceTestKindsBase(String val) {
        this.val = val;
    }

    MethodReferenceTestKindsBase() {
        this("blank");
    }

}

class MethodReferenceTestKindsSup extends MethodReferenceTestKindsBase {
    String instanceMethod0() { return "SIM:0-" + this; }
    String instanceMethod1(MethodReferenceTestKinds x) { return "SIM:1-" + this + x; }

    MethodReferenceTestKindsSup(String val) {
        super(val);
    }

}
