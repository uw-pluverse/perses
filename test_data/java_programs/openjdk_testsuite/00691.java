
@TraceResolve
class AbstractMerge {

    interface A {
        @Candidate(applicable=Phase.BASIC)
        java.io.Serializable m1();
        @Candidate(applicable=Phase.BASIC)
        java.io.Serializable m2();
        @Candidate(applicable=Phase.BASIC)
        java.io.Serializable m3();
        @Candidate(applicable=Phase.BASIC)
        java.io.Serializable m4();
        @Candidate(applicable=Phase.BASIC)
        java.io.Serializable m5();
        @Candidate(applicable=Phase.BASIC)
        java.io.Serializable m6();
    }

    interface B {
        @Candidate(applicable=Phase.BASIC)
        Cloneable m1();
        @Candidate(applicable=Phase.BASIC)
        Cloneable m2();
        @Candidate(applicable=Phase.BASIC)
        Cloneable m3();
        @Candidate(applicable=Phase.BASIC)
        Cloneable m4();
        @Candidate(applicable=Phase.BASIC)
        Cloneable m5();
        @Candidate(applicable=Phase.BASIC)
        Cloneable m6();
    }

    interface C {
        @Candidate(applicable=Phase.BASIC, mostSpecific=true)
        Object[] m1();
        @Candidate(applicable=Phase.BASIC, mostSpecific=true)
        Object[] m2();
        @Candidate(applicable=Phase.BASIC, mostSpecific=true)
        Object[] m3();
        @Candidate(applicable=Phase.BASIC, mostSpecific=true)
        Object[] m4();
        @Candidate(applicable=Phase.BASIC, mostSpecific=true)
        Object[] m5();
        @Candidate(applicable=Phase.BASIC, mostSpecific=true)
        Object[] m6();
    }

    interface ABC extends A, B, C { }
    interface ACB extends A, C, B { }
    interface BAC extends B, A, C { }
    interface BCA extends B, C, A { }
    interface CAB extends C, A, B { }
    interface CBA extends C, B, A { }

    {
        ABC abc = null;
        abc.m1();
    }

    {
        ACB acb = null;
        acb.m2();
    }

    {
        BAC bac = null;
        bac.m3();
    }

    {
        BCA bca = null;
        bca.m4();
    }

    {
        CAB cab = null;
        cab.m5();
    }

    {
        CBA cba = null;
        cba.m6();
    }
}
