



class TargetType31 {

    interface SAM {
        void m(int x);
    }

    void m(SAM s) { }

    void testAssignmentContext() {
        SAM s1 = (SAM)(x-> { System.out.println("Hello!"); });
        SAM s2 = (SAM)((x-> { System.out.println("Hello!"); }));
        SAM s3 = (SAM)(((x-> { System.out.println("Hello!"); })));
    }

    void testMethodContext() {
        m((SAM)(x-> { System.out.println("Hello!"); }));
        m((SAM)((x-> { System.out.println("Hello!"); })));
        m((SAM)(((x-> { System.out.println("Hello!"); }))));
    }
}
