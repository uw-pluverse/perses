



enum E { A, B, C }

@interface Anno {
    E value();
}

@Anno(E.valueOf("A"))
class EnumAnnoValueMustBeEnumConstant { }
