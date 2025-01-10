fn sof<T>() -> T {}
fn test<T>() {
    let _: [u8; sof::<T>()];
}
