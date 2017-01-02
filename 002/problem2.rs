
fn main() {
    const MAX: i32 = 4000000;
    let mut sum: i32 = 2;

    let mut two_back: i32 = 1;
    let mut one_back: i32 = 2;
    let mut next: i32 = two_back + one_back;
    

    while next < MAX {
        println!("{}", next);
        if next % 2 == 0 {
            sum += next;
        }
        two_back = one_back;
        one_back = next;
        next = two_back + one_back;
    }


    println!("answer: {}", sum);

    
}
