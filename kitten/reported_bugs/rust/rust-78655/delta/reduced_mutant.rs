const FOO: *const u32 = {
    let x;
    &x
};
fn main() {
    let FOO = FOO;
}
