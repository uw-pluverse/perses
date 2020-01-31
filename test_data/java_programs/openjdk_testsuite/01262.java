





@interface Anno { }

class AnnotationsAfterTypeParamsNotSupportedInSource {
    <T> @Anno int m() {
        return 0;
    }
}
