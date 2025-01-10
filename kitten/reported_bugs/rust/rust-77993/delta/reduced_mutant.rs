#[derive(Clone)]
struct InGroup<F> {
    it: It,
    f: F,
}
fn dates_in_year() -> impl Clone {
    InGroup { f: |d| d }
}
