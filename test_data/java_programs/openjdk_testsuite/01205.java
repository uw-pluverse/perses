





class IncompatibleTypesInConditional {

    interface A { }
    interface B { }

    B b = true ? (A)null : (B)null;
}
