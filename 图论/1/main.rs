use std::io;

fn read_line() -> (usize, usize) {
    let input = &mut String::new();
    io::stdin().read_line( input).unwrap();
    let mut lr = input.split_whitespace();
    let n = lr.next().unwrap().parse().unwrap();
    let m = lr.next().unwrap().parse().unwrap();
    (n,m)
}

fn main() {
    const MAX: usize = 100;
    let mut matrix = [[0usize; MAX]; MAX];
    while true {
        let (n, m) = read_line();
        if n == 0 && m == 0 {
            break;
        }
        for _ in 1..=m {
            let (u, v) = read_line();
            matrix[u-1][v-1] = 1usize;
        }
        for i in 0..n {
            let mut od = 0usize;
            for j in 0..n {
                od += matrix[i][j];
            }
            if i == 0 {
                print!("{}", od);
            } else {
                print!(" {}", od);
            }
        }
        println!();
        for i in 0..n {
            let mut id = 0usize;
            for j in 0..n {
                id += matrix[j][i];
            }
            if i == 0 {
                print!("{}", id);
            } else {
                print!(" {}", id);
            }
        }
        println!();
    }
}
