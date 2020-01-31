



enum Color { red, green, blue }

@interface Colored {
    Color value() default Color.red;
}
