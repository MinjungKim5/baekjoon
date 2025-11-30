use std::fmt::Write;
use std::io::stdin;

fn main() {
    let mut input = String::new();
    let mut output = String::new();
    loop {
        if let Ok(0) = stdin().read_line(&mut input) {
            break;
        }
    }

    let input_vec: Vec<i64> = input
        .split_ascii_whitespace()
        .map(|x| x.parse::<i64>().unwrap())
        .collect();
    for i in 0..input_vec.len() / 2 {
        let sum = input_vec[2 * i] + input_vec[2 * i + 1];
        writeln!(output, "{}", sum).unwrap();
    }
    print!("{}", output);
}
