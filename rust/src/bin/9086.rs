use std::io::{Read, stdin};

fn main() {
    let mut input = String::new();
    stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();
    let _ = iter.next().unwrap();
    for i in iter {
        let first = i.chars().next().unwrap();
        let last = i.chars().next_back().unwrap();
        println!("{}{}", first, last);
    }
}
