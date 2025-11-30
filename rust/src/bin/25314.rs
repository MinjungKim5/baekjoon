use std::io::stdin;

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let n: i64 = input.trim().parse().unwrap();
    let mut output = String::new();
    for _ in 0..n / 4 {
        output.push_str("long ");
    }
    output.push_str("int");
    print!("{}", output)
}
