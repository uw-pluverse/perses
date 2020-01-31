

import com.sun.tools.classfile.*;


class AttributeVisitor<R, P> implements Attribute.Visitor<R, P> {
    public R visitBootstrapMethods(BootstrapMethods_attribute attr, P p) { return null; }
    public R visitDefault(DefaultAttribute attr, P p) { return null; }
    public R visitAnnotationDefault(AnnotationDefault_attribute attr, P p) { return null; }
    public R visitCharacterRangeTable(CharacterRangeTable_attribute attr, P p) { return null; }
    public R visitCode(Code_attribute attr, P p) { return null; }
    public R visitCompilationID(CompilationID_attribute attr, P p) { return null; }
    public R visitConstantValue(ConstantValue_attribute attr, P p) { return null; }
    public R visitDeprecated(Deprecated_attribute attr, P p) { return null; }
    public R visitEnclosingMethod(EnclosingMethod_attribute attr, P p) { return null; }
    public R visitExceptions(Exceptions_attribute attr, P p) { return null; }
    public R visitInnerClasses(InnerClasses_attribute attr, P p) { return null; }
    public R visitLineNumberTable(LineNumberTable_attribute attr, P p) { return null; }
    public R visitLocalVariableTable(LocalVariableTable_attribute attr, P p) { return null; }
    public R visitLocalVariableTypeTable(LocalVariableTypeTable_attribute attr, P p) { return null; }
    public R visitMethodParameters(MethodParameters_attribute attr, P p) { return null; }
    public R visitRuntimeVisibleAnnotations(RuntimeVisibleAnnotations_attribute attr, P p) { return null; }
    public R visitRuntimeInvisibleAnnotations(RuntimeInvisibleAnnotations_attribute attr, P p) { return null; }
    public R visitRuntimeVisibleParameterAnnotations(RuntimeVisibleParameterAnnotations_attribute attr, P p) { return null; }
    public R visitRuntimeInvisibleParameterAnnotations(RuntimeInvisibleParameterAnnotations_attribute attr, P p) { return null; }
    public R visitRuntimeVisibleTypeAnnotations(RuntimeVisibleTypeAnnotations_attribute attr, P p) { return null; }
    public R visitRuntimeInvisibleTypeAnnotations(RuntimeInvisibleTypeAnnotations_attribute attr, P p) { return null; }
    public R visitSignature(Signature_attribute attr, P p) { return null; }
    public R visitSourceDebugExtension(SourceDebugExtension_attribute attr, P p) { return null; }
    public R visitSourceFile(SourceFile_attribute attr, P p) { return null; }
    public R visitSourceID(SourceID_attribute attr, P p) { return null; }
    public R visitStackMap(StackMap_attribute attr, P p) { return null; }
    public R visitStackMapTable(StackMapTable_attribute attr, P p) { return null; }
    public R visitSynthetic(Synthetic_attribute attr, P p) { return null; }
}
