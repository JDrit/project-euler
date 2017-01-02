

fn main() {
    println!("{}", usize::max_value());
    println!("{}", LIMIT_SIZE);
    const LIMIT: i64 = 600851475143;
    const LIMIT_SIZE: usize = 600851475143;
    let mut results: Vec<i64> = Vec::new();
    let mut sieve: [bool; LIMIT_SIZE] = [false; LIMIT_SIZE];

    let mut x: i64 = 1;
    let mut y: i64 = 1;

    while x * x < LIMIT {
        while y * y < LIMIT {
            println!("{} {}", x, y);
            let n = (4 * x * x) + (y * y);
            if n < LIMIT && (n % 12 == 1 || n % 12 == 5) {
                //sieve[n as usize] ^= true;            
            }
            let m = (3 * x * x) + (y * y);
            if n < LIMIT && n % 12 == 7 {
                //sieve[n as usize] ^= true;
            }
            let o = (3 * x * x) - (y * y);
            if x > y && o < LIMIT && o % 12 == 11 {
                //sieve[n as usize] ^= true;                
            }

            y += 1;
        }

        x += 1
    }
    
}
