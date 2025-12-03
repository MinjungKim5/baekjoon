// 문제
// N개의 정수가 주어진다. 이때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 정수의 개수 N (1 ≤ N ≤ 1,000,000)이 주어진다.
// 둘째 줄에는 N개의 정수를 공백으로 구분해서 주어진다.
// 모든 정수는 -1,000,000보다 크거나 같고, 1,000,000보다 작거나 같은 정수이다.

// 출력
// 첫째 줄에 주어진 정수 N개의 최솟값과 최댓값을 공백으로 구분해 출력한다.

// 예제 입력 1
// 5
// 20 10 35 30 7
// 예제 출력 1
// 7 35

use std::io::stdin;

fn main() {
    let mut input_lines = stdin().lines();
    let _ = input_lines.next().unwrap().unwrap();
    let line = input_lines.next().unwrap().unwrap();
    let iter = line
        .split_ascii_whitespace()
        .map(|x| x.parse::<i64>().unwrap());
    let mut min = i64::MAX;
    let mut max = i64::MIN;
    for i in iter {
        if i < min {
            min = i;
        }
        if i > max {
            max = i;
        }
    }

    print!("{} {}", min, max)
}
