use std::io::stdin;

fn main() {
    let mut word = String::new();
    stdin().read_line(&mut word).unwrap();
    let mut idx_str = String::new();
    stdin().read_line(&mut idx_str).unwrap();
    let idx: usize = idx_str.trim().parse().unwrap();
    print!("{}", word.chars().nth(idx - 1).unwrap());
}
