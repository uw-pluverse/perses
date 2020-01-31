

class BadBreakContinue {

    static interface SAM {
       void m();
    }

    SAM s1 = ()-> { break; };
    SAM s2 = ()-> { continue; };
    SAM s3 = ()-> {
        SAM s3_1 = ()-> { break; };
        SAM s3_2 = ()-> { continue; };
    };

    void testLabelled() {
        loop: while (true) {
            SAM s1 = ()-> { break loop; };
            SAM s2 = ()-> { continue loop; };
            SAM s3 = ()-> {
                SAM s3_1 = ()-> { break loop; };
                SAM s3_2 = ()-> { continue loop; };
            };
        }
    }

    void testNonLabelled() {
        while (true) {
            SAM s1 = ()-> { break; };
            SAM s2 = ()-> { continue; };
            SAM s3 = ()-> {
                SAM s3_1 = ()-> { break; };
                SAM s3_2 = ()-> { continue; };
            };
        }
    }
}
