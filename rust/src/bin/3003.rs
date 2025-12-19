use std::{fmt::Write, io::stdin};

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let mals: Vec<i64> = input
        .split_ascii_whitespace()
        .map(|x| x.parse::<i64>().unwrap())
        .collect();
    let chess: Vec<i64> = vec![1, 1, 2, 2, 2, 8];
    let mut output = String::new();
    for i in 0..6 {
        let _ = write!(output, "{} ", chess[i] - mals[i]);
    }
    print!("{}", output);
}
