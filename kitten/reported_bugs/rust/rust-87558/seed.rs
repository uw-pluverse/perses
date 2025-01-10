struct ErrorKind;
struct Error(ErrorKind);

impl From<nope::Thing> for Error {
    fn from(_: nope::Thing) -> Self {
        unimplemented!()
    }
}

impl From<ErrorKind> for Error {
    fn from(_: ErrorKind) -> Self {
        unimplemented!()
    }
}

fn main() {}
