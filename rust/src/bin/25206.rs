use std::io::stdin;

fn main() {
    let mut total_hakjum: f64 = 0.0;
    let mut total_scores: f64 = 0.0;
    for _ in 0..20 {
        let mut input = String::new();
        stdin().read_line(&mut input).unwrap();
        let mut iter = input.split_ascii_whitespace();
        let _ = iter.next().unwrap();
        let hakjum = iter.next().unwrap().parse::<f64>().unwrap();
        let score_str = iter.next().unwrap();
        if score_str == "P" {
            continue;
        }
        total_hakjum += hakjum;
        total_scores += hakjum * map_score_str_to_score(score_str)
    }

    print!("{}", total_scores / total_hakjum);
}

fn map_score_str_to_score(score_str: &str) -> f64 {
    match score_str {
        "A+" => return 4.5,
        "A0" => return 4.0,
        "B+" => return 3.5,
        "B0" => return 3.0,
        "C+" => return 2.5,
        "C0" => return 2.0,
        "D+" => return 1.5,
        "D0" => return 1.0,
        "F" => return 0.0,
        _ => 0.0,
    }
}
