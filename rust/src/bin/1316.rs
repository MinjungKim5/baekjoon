use std::io::{Read, stdin};

fn main() {
    let mut input = String::new();
    stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();
    let n_of_words = iter.next().unwrap().parse::<usize>().unwrap();
    let mut count = 0;
    for _ in 0..n_of_words {
        let mut last_char = 27;
        let mut chr_vec: Vec<bool> = vec![false; 26];
        let word = iter.next().unwrap().chars();
        let mut group_word = true;
        for chr in word {
            let chr_num = chr as usize - 97;
            if chr_num != last_char && chr_vec[chr_num] {
                group_word = false;
                break;
            }
            chr_vec[chr_num] = true;
            last_char = chr_num;
        }
        if group_word {
            count += 1;
        }
    }
    print!("{}", count);
}
