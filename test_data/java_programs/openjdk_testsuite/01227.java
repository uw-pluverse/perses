



@interface Anno {
    int value();
}

@Anno(value=1, value=2)
class DuplicateAnnotationMemberValue { }
