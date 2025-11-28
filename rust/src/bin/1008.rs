use std::io::stdin;

fn main() {
    let mut input_line = String::new();
    stdin().read_line(&mut input_line).unwrap();

    let mut input_iter = input_line.split_whitespace().map(|x| x.parse().unwrap());
    let a: f64 = input_iter.next().unwrap();
    let b: f64 = input_iter.next().unwrap();
    println!("{}", a / b)
}
