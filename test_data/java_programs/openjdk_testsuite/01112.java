



@interface Anno {
    String value();
}

@Anno(System.getProperty("user.dir"))
class AttrMustBeConstant { }
