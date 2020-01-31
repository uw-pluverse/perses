



enum Color { red, green, blue }

@interface Colored {
    Color value();
}

@Colored(Color.green)
class Martian {
}
