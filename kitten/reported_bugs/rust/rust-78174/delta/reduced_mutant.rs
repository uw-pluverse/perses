struct ArpIPv4<'a> {}
impl<'a> ArpIPv4<'a> {
    const LENGTH: usize;
    fn to_buffer() -> [u8; Self::LENGTH] {}
}
