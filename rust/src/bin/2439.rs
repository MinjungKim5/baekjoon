use std::fmt::Write;
use std::io::stdin;

fn main() {
    let mut input = String::new();
    let mut output = String::new();
    stdin().read_line(&mut input).unwrap();
    let n: i64 = input.trim().parse().unwrap();
    for i in 1..n + 1 {
        let mut line = String::new();
        for j in 1..n + 1 {
            let sym = if n - i - j >= 0 { " " } else { "*" };
            line.push_str(sym);
        }
        writeln!(output, "{}", line).unwrap();
    }
    print!("{}", output);
}
