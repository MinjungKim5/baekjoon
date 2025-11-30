use std::io::stdin;

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let dan: i32 = input.trim().parse().unwrap();
    for i in 1..10 {
        println!("{} * {} = {}", dan, i, dan * i);
    }
}
