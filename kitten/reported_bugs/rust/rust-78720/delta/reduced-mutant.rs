fn server() -> impl {
    ().map2(|| "")
}
trait FilterBase2 {
    fn map2<F>(self, F) -> Map2<F> {}
}
struct Map2<segment2> {
    _func: F,
}
impl<F> FilterBase2 for F {}
