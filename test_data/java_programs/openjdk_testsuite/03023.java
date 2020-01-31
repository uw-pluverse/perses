



class TargetType25 {

    interface F<A, B> {
        B f(A a);
    }

    <Z> void m1(F<String, Z> f) {  }
    <Z> void m2(F<String, F<String, Z>> f) {  }
    <Z> void m3(F<String, F<String, F<String, Z>>> f) {  }

    void testExprLambdaInMethodContext() {
        m1(s1 -> 1);
        m2(s1 -> s2 -> 1);
        m3(s1 -> s2 -> s3 -> 1);
    }

    void testExprLambdaInAssignmentContext() {
        F<String, Integer> fn1 = s1 -> 1;
        F<String, F<String, Integer>> fn2 = s1 -> s2 -> 1;
        F<String, F<String, F<String, Integer>>> fn3 = s1 -> s2 -> s3 -> 1;
    }

    void testStatementLambdaInMethodContext() {
        m1(s1 -> { return 1; });
        m2(s1 -> { return s2 -> { return 1; }; });
        m3(s1 -> { return s2 -> { return s3 -> { return 1; }; }; });
    }

    void testStatementLambdaInAssignmentContext() {
        F<String, Integer> fn1 = s1 -> { return 1; };
        F<String, F<String, Integer>> fn2 = s1 -> { return s2 -> { return 1; }; };
        F<String, F<String, F<String, Integer>>> fn3 = s1 -> { return s2 -> { return s3 -> { return 1; }; }; };
    }
}
