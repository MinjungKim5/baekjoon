fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let c = input.trim().chars().next().unwrap() as u8;
    print!("{}", c)
}
