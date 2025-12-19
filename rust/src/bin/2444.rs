use std::{fmt::Write, io::stdin};

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let x: i64 = input.trim().parse().unwrap();
    let midnum = x - 1;
    let mut output = String::new();

    for row in 0..x {
        let mut line = String::new();
        for column in 0..2 * x - 1 {
            if column >= midnum - row && column <= midnum + row {
                let _ = write!(line, "*");
            } else {
                let _ = write!(line, " ");
            }
        }
        let _ = writeln!(output, "{}", line.trim_end());
    }
    for row in x..2 * x - 1 {
        let rev_row = 2 * x - 2 - row;
        let mut line = String::new();
        for column in 0..2 * x - 1 {
            if column >= midnum - rev_row && column <= midnum + rev_row {
                let _ = write!(line, "*");
            } else {
                let _ = write!(line, " ");
            }
        }
        let _ = writeln!(output, "{}", line.trim_end());
    }
    print!("{}", output)
}
