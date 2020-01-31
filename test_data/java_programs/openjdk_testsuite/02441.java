



package recovery1;

@interface MyAnnotation {
    String value();
    Marker marker() default @Marker;
}

interface MyBean {
    @MyAnnotation (value="baz", markerToo="not default")
    public String getFoo();
}
