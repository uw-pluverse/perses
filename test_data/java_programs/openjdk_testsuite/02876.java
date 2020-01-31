

class TargetType24 {

    interface F<A, B> {
        B f(A a);
    }

    interface FSub<A, B> extends F<A,B> { }

    static class Array<A> {
        boolean forAll(final F<A, Boolean> f) {
            return false;
        }

        String forAll(final FSub<A, String> f) {
            return "";
        }

        String forAll2(final FSub<A, String> f) {
            return "";
        }
    }

    void test(Array<String> as, final Array<Character> ac) {
        final boolean b1 = as.forAll((String s) -> ac.forAll((Character c) -> false)); 
        final boolean b2 = as.forAll(s -> ac.forAll(c -> false)); 
        final boolean b3 = as.forAll((String s) -> ac.forAll(c -> false)); 
        final boolean b4 = as.forAll(s -> ac.forAll((Character c) -> false)); 
        final String s1 = as.forAll2(s -> ac.forAll2(c -> "")); 
        final boolean b5 = as.forAll(s -> ac.forAll(c -> "" )); 
        final String s2 = as.forAll2(s -> ac.forAll2(c -> false)); 
        final boolean b6 = as.forAll((F<String, Boolean>)s -> ac.forAll((F<Character, Boolean>)c -> "")); 
        final String s3 = as.forAll((FSub<String, String>)s -> ac.forAll((FSub<Character, String>)c -> false)); 
    }
}
