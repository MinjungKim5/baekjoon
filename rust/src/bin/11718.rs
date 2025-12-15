use std::io::{Read, stdin};

fn main() {
    let mut input = String::new();
    stdin().read_to_string(&mut input).unwrap();
    print!("{}", input);
}
