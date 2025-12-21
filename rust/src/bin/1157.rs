use std::io::stdin;

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let binding = input.trim().to_uppercase();
    let mut alphabet_freq: Vec<i64> = vec![0; 26];
    for c in binding.chars() {
        let idx = c as usize - 65;
        alphabet_freq[idx] += 1;
    }
    let mut maxval = 0;
    let mut maxidx = 0;
    for i in 0..26 {
        if alphabet_freq[i] > maxval {
            maxval = alphabet_freq[i];
            maxidx = i as u8;
        }
    }
    if alphabet_freq.iter().filter(|x| **x == maxval).count() > 1 {
        print!("?");
    } else {
        print!("{}", (maxidx + 65) as char)
    }
}
