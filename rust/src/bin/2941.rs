use std::io::stdin;

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let m1 = input.matches("=").count();
    let m2 = input.matches("-").count();
    let m3 = input.matches("lj").count();
    let m4 = input.matches("nj").count();
    let m5 = input.matches("dz=").count();
    print!("{}", input.trim().len() - m1 - m2 - m3 - m4 - m5);
}
