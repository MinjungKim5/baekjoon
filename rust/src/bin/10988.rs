use std::io::stdin;

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let word: Vec<char> = input.trim().chars().collect();
    let mut is_palindrome: i64 = 1;
    for i in 0..word.len() {
        if word[i] != word[word.len() - 1 - i] {
            is_palindrome = 0;
        }
    }
    print!("{}", is_palindrome)
}
