use std::{
    fmt::Write,
    io::{Read, stdin},
};

fn main() {
    let mut input = String::new();
    stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace().map(|x| x.parse().unwrap());
    let n_of_basket = iter.next().unwrap();
    let mut basket: Vec<usize> = (1..=n_of_basket).collect();
    let m_of_method = iter.next().unwrap();
    for _ in 0..m_of_method {
        let start_idx = iter.next().unwrap() - 1;
        let end_pp_idx = iter.next().unwrap();
        let mut temp = basket[start_idx..end_pp_idx].to_vec();
        temp.reverse();
        basket.splice(start_idx..end_pp_idx, temp);
    }
    let mut output = String::new();
    for e in basket {
        write!(output, "{} ", e).unwrap();
    }
    print!("{}", output);
}
