



package Multibound1;

interface A {}
interface B {}
class C<T extends A&B> {}
class D implements A {}
class E extends C<D> {}
