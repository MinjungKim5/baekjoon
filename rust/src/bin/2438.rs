// 문제
// 첫째 줄에는 별 1개, 둘째 줄에는 별 2개, N번째 줄에는 별 N개를 찍는 문제

// 입력
// 첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

// 출력
// 첫째 줄부터 N번째 줄까지 차례대로 별을 출력한다.

// 예제 입력 1
// 5
// 예제 출력 1
// *
// **
// ***
// ****
// *****

use std::fmt::Write;
use std::io::stdin;

fn main() {
    let mut input = String::new();
    let mut output = String::new();
    stdin().read_line(&mut input).unwrap();
    let n: i64 = input.trim().parse().unwrap();
    for i in 1..n + 1 {
        let mut line = String::new();
        for _ in 0..i {
            line.push_str("*");
        }
        writeln!(output, "{}", line).unwrap();
    }
    print!("{}", output);
}
