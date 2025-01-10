fn main() {
    static foo: dyn Fn() -> u32 = || -> u32 {

        0
    };
}
