
class MissingAnnotationValue<K> {
  MissingAnnotationValue<@A String> l;
}

@interface A { int field(); }
