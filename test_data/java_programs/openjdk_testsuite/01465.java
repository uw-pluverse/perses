



class AnonClassImplInterfaceNoQualForNew {
    interface Intf {}
    AnonClassImplInterfaceNoQualForNew x;

    Object o = x.new Intf() { };
}
