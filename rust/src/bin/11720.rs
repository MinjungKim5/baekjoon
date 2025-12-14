use std::io::stdin;

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut String::new()).unwrap();
    stdin().read_line(&mut input).unwrap();
    let iter = input.trim().chars().map(|x| x.to_digit(10).unwrap());
    let mut sum = 0;
    for i in iter {
        sum += i;
    }
    print!("{}", sum)
}
