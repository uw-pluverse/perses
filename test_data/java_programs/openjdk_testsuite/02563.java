
class MissingAnnotationValue<K> {
  MissingAnnotationValue<@A ?> l;
}

@interface A { int field(); }
