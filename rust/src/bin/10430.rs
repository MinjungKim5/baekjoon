// 문제
// (A+B)%C는 ((A%C) + (B%C))%C 와 같을까?

// (A×B)%C는 ((A%C) × (B%C))%C 와 같을까?

// 세 수 A, B, C가 주어졌을 때, 위의 네 가지 값을 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 A, B, C가 순서대로 주어진다. (2 ≤ A, B, C ≤ 10000)

// 출력
// 첫째 줄에 (A+B)%C, 둘째 줄에 ((A%C) + (B%C))%C, 셋째 줄에 (A×B)%C, 넷째 줄에 ((A%C) × (B%C))%C를 출력한다.

// 예제 입력 1
// 5 8 4
// 예제 출력 1
// 1
// 1
// 0
// 0

use std::io::stdin;

fn main() {
    let mut input_line = String::new();
    stdin().read_line(&mut input_line).unwrap();
    let mut input_iter = input_line
        .split_whitespace()
        .map(|x| x.parse::<i64>().unwrap());
    let a = input_iter.next().unwrap();
    let b = input_iter.next().unwrap();
    let c = input_iter.next().unwrap();
    println!("{}", (a + b) % c);
    println!("{}", ((a % c) + (b % c)) % c);
    println!("{}", (a * b) % c);
    println!("{}", ((a % c) * (b % c)) % c);
}
