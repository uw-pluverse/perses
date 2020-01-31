



class LabelInUse {
    void m(String... args) {
        label:
        for (String a1: args) {
            label:
            for (String a2: args) {
                System.out.println(a1 + " " + a2);
            }
        }
    }
}

