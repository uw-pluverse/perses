



@interface Anno {
    Class value();
}

@Anno(Class.forName("java.lang.Object"))
class AnnoValueMustBeClassLiteral { }
