// 문제
// 두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 A와 B가 주어진다. (0 < A, B < 10)

// 출력
// 첫째 줄에 A+B를 출력한다.

// 예제 입력 1
// 1 2
// 예제 출력 1
// 3

use std::io::stdin;

fn main() {
    let mut input_line = String::new();
    stdin().read_line(&mut input_line).unwrap();
    let input_arr = input_line.split_whitespace();
    let mut sum: i64 = 0;
    for val in input_arr {
        let n: i64 = val.parse().unwrap();
        sum += n;
    }
    println!("{}", sum);
}
