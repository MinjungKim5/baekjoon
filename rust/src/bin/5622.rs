use std::io::stdin;

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let words = input.trim().chars();
    let mut sum: i32 = 0;
    for c in words {
        sum += calc_time(c as i32);
    }
    print!("{}", sum);
}

fn calc_time(c: i32) -> i32 {
    if c == 90 {
        return 10;
    }
    let d = if c < 83 { c } else { c - 1 };
    return 3 + (d - 65) / 3;
}
