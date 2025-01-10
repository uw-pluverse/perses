

const VAR_FIVE: &'static [&[&'static str]] = &[&["test"], &["other one"]];

const VAR_SEVEN: &[&(&str, &'static [&'static str])] = &[&("one", &["other one"])];

static STATIC_VAR_FOUR: (&str, (&str, &'static str), &'static str) = ("on", ("th", "th"), "on");

static STATIC_VAR_FIVE: &'static [&[&'static str]] = &[&["test"], &["other one"]];

static STATIC_VAR_SEVEN: &[&(&str, &'static [&'static str])] = &[&("one", &["other one"])];

fn main() {}
