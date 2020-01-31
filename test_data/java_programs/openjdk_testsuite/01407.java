



@interface Anno1 {
    String value();
}

@interface Anno2 {
    Anno1 value();
}

@Anno2("3")
class AnnoValueMustBeAnnotation { }
