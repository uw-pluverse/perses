







#![feature(rustc_attrs)]
#![deny(unused_attributes)]

#[rustc_layout_scalar_valid_range_start(10)]
#[rustc_layout_scalar_valid_range_end(30)]
struct RestrictedRange(u32);
const OKAY_RANGE: RestrictedRange = unsafe { RestrictedRange(20) };

fn main() {
    OKAY_RANGE.0;
}
