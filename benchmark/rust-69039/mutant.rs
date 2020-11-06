#![feature(generators, generator_trait)]

use std::{
    io,
    ops::{Generator, GeneratorState},
};

fn my_scenario() -> impl Generator<String, Yield = &'static str, Return = String> {
    |_arg: String| {
        let my_name = yield "What is your name?";
        let my_mood = yield "How are you feeling?";
        format!("{} is {}", my_name.trim(), my_mood.trim())
    }
}

fn main() {
    let mut my_session = Box::pin(my_scenario());

    loop {
        let mut line = String::new();

        match my_session.as_mut().resume(line) {
            GeneratorState::Yielded(prompt) => {
                println!("{}", prompt);
            }
            GeneratorState::Complete(v) => {
                println!("{}", v);
                break;
            }
        }

        line = String::new();
        io::stdin().read_line(&mut line).unwrap();
    }
}

