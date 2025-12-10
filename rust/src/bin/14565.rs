// 문제
// 집합 Zn을 0부터 n-1까지의 정수 집합이라고 하자. Zn ∋ a, b, c 일 때, (a+b) mod n = 0이면 b는 a의 덧셈역이라고 하고 (a*c) mod n = 1이면 c는 a의 곱셈역이라고 한다.

// 정수 N, A가 주어졌을 때 Zn에서의 A의 덧셈역과 곱셈역을 구하시오.

// 단, 곱셈역을 구할 수 없으면 -1을 출력한다.

// 입력
// 첫 번째 줄에 N(2 ≤ N ≤ 1012)과 A(1 ≤ A < N)이 주어진다.

// 출력
// 첫 번째 줄에 A의 N에 대한 덧셈역과 곱셈역을 한 줄에 공백으로 구분하여 출력한다.

// 예제 입력 1
// 26 11
// 예제 출력 1
// 15 19
// 예제 입력 2
// 100 20
// 예제 출력 2
// 80 -1
// 예제 입력 3
// 32760247633 22801763489
// 예제 출력 3
// 9958484144 12390598440

use std::io::stdin;

fn upper_share(a: i128, b: i128) -> i128 {
    return a / b + 1;
}

fn upper_res(a: i128, b: i128) -> i128 {
    if a % b == 0 {
        return 0;
    } else {
        return -(a % b - b);
    }
}

fn module(a: i128, b: i128, prev_mod: i128) -> i128 {
    let u_sh = upper_share(a, b);
    let u_res = upper_res(a, b);
    if u_res == 0 {
        return -1;
    } else if u_res == 1 {
        return u_sh;
    } else {
        if prev_mod == -1 {
            return -1;
        }
        let new_mod = upper_share(a * prev_mod, b);
        return new_mod;
    }
}

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace().map(|x| x.parse().unwrap());
    let a = iter.next().unwrap();
    let b = iter.next().unwrap();
    if b == 1 {
        print!("{} {}", a - b, 1);
        return;
    }
    let mut stacks: Vec<i128> = vec![a, b];
    let mut n = a;
    let mut m = b;
    loop {
        let u_res = upper_res(n, m);
        if u_res <= 1 {
            break;
        }
        n = m;
        m = u_res;
        stacks.push(m);
    }
    let mut mod_result: i128 = 0;
    let stack_len = stacks.len();
    for i in 1..stack_len {
        let a1 = stacks[stack_len - i - 1];
        let b1 = stacks[stack_len - i];
        // println!("{} {} {}", a1, b1, mod_result);
        if mod_result == -1 {
            break;
        }
        mod_result = module(a1, b1, mod_result);
    }
    print!("{} {}", a - b, mod_result);
}
