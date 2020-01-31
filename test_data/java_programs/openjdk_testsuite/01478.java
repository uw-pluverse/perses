




class EnumLabelUnqualified {
    enum E { A, B, C };

    void m(E e) {
        switch (e) {
            case E.A:
                System.out.println("A");
        }
    }
}
