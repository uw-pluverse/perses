

@Processor.A(a=some.path.to.SomeUnknownClass$Inner.class)
class Source1{}

@Processor.B(a=SomeUnknownClass.class)
class Source2{}

@Processor.C(a=SomeUnknownClass.clas) 
class Source3{}
