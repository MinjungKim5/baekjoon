use std::fmt::Write;
use std::io::{Read, stdin};

fn main() {
    let mut input = String::new();
    let mut output = String::new();
    stdin().read_to_string(&mut input).unwrap();
    let mut iter = input
        .split_ascii_whitespace()
        .flat_map(|x| x.parse::<i64>());
    let n = iter.next().unwrap();
    for _ in 0..n {
        let a = iter.next().unwrap();
        let b = iter.next().unwrap();
        writeln!(output, "{}", a + b).unwrap();
    }

    print!("{}", output)
}
