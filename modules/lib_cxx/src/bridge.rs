use cxx::CxxVector;

#[cxx::bridge]
mod ffi {
    extern "Rust" {
        fn say_hello();
        fn print_vec(vec: &CxxVector<f32>);
    }
}

pub fn say_hello() {
    println!("Hello from Rust!");
}

fn print_vec(vec: &CxxVector<f32>) {
    vec
        .iter()
        .for_each(|i|{
            println!("{}", i);
        });
}
