



import java.lang.annotation.Annotation;
import java.util.List;
import javax.lang.model.element.*;
import javax.lang.model.type.*;
import javax.lang.model.util.*;

public class TestIntersectionTypeVisitors {
    public static void main(String... args) throws Exception {
        IntersectionType it = new TestIntersectionType();

        boolean result = it.accept(new TypeKindVisitor8Child(), null) &&
            it.accept(new SimpleTypeVisitor8Child(), null) &&
            it.accept(new SimpleTypeVisitor6Child(), null);

        if (!result)
            throw new RuntimeException();
    }

    static class TestIntersectionType implements IntersectionType {
        TestIntersectionType() {}

        @Override
        public List<? extends TypeMirror> getBounds() {
            throw new UnsupportedOperationException();
        }

        @Override
        public <R,P> R accept(TypeVisitor<R,P> v,
                       P p) {
            return v.visitIntersection(this, p);
        }

        @Override
        public TypeKind getKind() {
            return TypeKind.INTERSECTION;
        }

        @Override
        public <A extends Annotation> A getAnnotation(Class<A> annotationType) {
            throw new UnsupportedOperationException();
        }

        @Override
        public List<? extends AnnotationMirror> getAnnotationMirrors() {
            throw new UnsupportedOperationException();
        }

        @Override
        public <A extends Annotation> A[] getAnnotationsByType(Class<A> annotationType) {
            throw new UnsupportedOperationException();
        }
    }

    static class TypeKindVisitor8Child extends TypeKindVisitor8<Boolean, Void> {
        TypeKindVisitor8Child() {
            super(false);
        }

        @Override
        public Boolean visitIntersection(IntersectionType t, Void p) {
            super.visitIntersection(t, p); 
            return true;
        }
    }

    static class SimpleTypeVisitor8Child extends SimpleTypeVisitor8<Boolean, Void> {
        SimpleTypeVisitor8Child() {
            super(false);
        }

        @Override
        public Boolean visitIntersection(IntersectionType t, Void p) {
            super.visitIntersection(t, p);  
            return true;
        }
    }

    static class SimpleTypeVisitor6Child extends SimpleTypeVisitor6<Boolean, Void> {
        SimpleTypeVisitor6Child() {
            super(false);
        }

        @Override
        public Boolean visitIntersection(IntersectionType t, Void p) {
            try {
                super.visitIntersection(t, p);
                return false;
            } catch (UnknownTypeException ute) {
                return true; 
            }
        }
    }
}
