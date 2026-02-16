// 문제
// N*M크기의 두 행렬 A와 B가 주어졌을 때, 두 행렬을 더하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 행렬의 크기 N 과 M이 주어진다. 둘째 줄부터 N개의 줄에 행렬 A의 원소 M개가 차례대로 주어진다. 이어서 N개의 줄에 행렬 B의 원소 M개가 차례대로 주어진다. N과 M은 100보다 작거나 같고, 행렬의 원소는 절댓값이 100보다 작거나 같은 정수이다.

// 출력
// 첫째 줄부터 N개의 줄에 행렬 A와 B를 더한 행렬을 출력한다. 행렬의 각 원소는 공백으로 구분한다.

// 예제 입력 1
// 3 3
// 1 1 1
// 2 2 2
// 0 1 0
// 3 3 3
// 4 4 4
// 5 5 100
// 예제 출력 1
// 4 4 4
// 6 6 6
// 5 6 100

use std::{fmt::Write, io::stdin};

fn main() {
    let mut first_input = String::new();
    stdin().read_line(&mut first_input).unwrap();
    let mut firstline = first_input.split_ascii_whitespace();
    let n = firstline.next().unwrap().parse::<usize>().unwrap();
    let m = firstline.next().unwrap().parse::<usize>().unwrap();

    let mut vec1: Vec<usize> = Vec::new();
    for _i in 0..2 * n {
        let mut line_input = String::new();
        stdin().read_line(&mut line_input).unwrap();
        let line = line_input.split_ascii_whitespace();
        line.for_each(|x| vec1.push(x.parse::<usize>().unwrap()));
    }
    let mut output = String::new();
    for i in 0..n * m {
        let _ = write!(output, "{}", vec1[i] + vec1[i + n * m]);
        if (i + 1) % m == 0 {
            let _ = write!(output, "\n");
        } else {
            let _ = write!(output, " ");
        }
    }
    print!("{}", output);
}
