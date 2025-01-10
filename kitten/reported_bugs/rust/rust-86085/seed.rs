#![feature(format_args_capture)]

fn main() {
    format!(concat!("{foo}"));
    format!(concat!("{ba", "r} {}"), 1);
}
