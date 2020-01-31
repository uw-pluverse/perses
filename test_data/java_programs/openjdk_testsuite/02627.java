



class DUSwitch {
    void foo() {
        int c = 6;
        final int a1;

        switch (c%(a1=4)) {
        case 1:
            c+=1;
            break;
        case 2:
            c+=a1;
            System.out.println("case2 "+c);
        default:
            a1=4;
            c+=a1;
            System.out.println("default "+c);
            break;
        }
    }
}
