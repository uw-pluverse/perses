



class LocalBreakAndContinue {

    static interface SAM {
       void m();
    }

    SAM s1 = ()-> { while (true) break; };
    SAM s2 = ()-> { while (true) continue; };
}
