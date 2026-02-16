use std::io::stdin;

fn main() {
    let mut max: usize = 0;
    let mut idx: (usize, usize) = (0, 0);
    for i in 0..9 {
        let mut input = String::new();
        stdin().read_line(&mut input).unwrap();
        let line: Vec<usize> = input
            .split_ascii_whitespace()
            .map(|s| s.parse::<usize>().unwrap())
            .collect();
        for j in 0..line.len() {
            if line[j] > max {
                max = line[j];
                idx = (i, j);
            }
        }
    }

    println!("{}", max);
    println!("{} {}", idx.0 + 1, idx.1 + 1);
}
