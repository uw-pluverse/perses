



class DefAssignAfterIf_2 {
    void test () {
        int i;
        if (false) i = 3;
        System.out.println(i);  
    }
}
