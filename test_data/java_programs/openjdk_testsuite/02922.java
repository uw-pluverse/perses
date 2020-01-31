



class TargetType30 {

    interface SAM {
        void m(int x);
    }

    void m(SAM s) { }

    void testAssignmentContext() {
        SAM s1 = (x-> { System.out.println("Hello!"); });
        SAM s2 = ((x-> { System.out.println("Hello!"); }));
        SAM s3 = (((x-> { System.out.println("Hello!"); })));
    }

    void testMethodContext() {
        m((x-> { System.out.println("Hello!"); }));
        m(((x-> { System.out.println("Hello!"); })));
        m((((x-> { System.out.println("Hello!"); }))));
    }
}
