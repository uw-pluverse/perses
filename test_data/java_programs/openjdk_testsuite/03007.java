



class T8016081 {
    interface fint { int get(); }

    @interface atype {
        fint fld = ()->1;
    }

    @atype class T {}
}
