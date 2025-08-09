use cxx::CxxVector;
use std::pin::Pin;

#[cxx::bridge]
mod ffi {

    extern "Rust" {
        fn say_hello();
        fn print_vec(vec: Pin<&mut CxxVector<f32>>);
    }
}

pub fn say_hello() {
    println!("Hello from Rust!");
}

fn print_vec(vec: Pin<&mut CxxVector<f32>>) {
    vec
        .iter_mut()
        .for_each(|i|{
            println!("{}", i);
            unsafe {
                let a = i.get_unchecked_mut();
                *a = 255.0 - *a;
            }
        });
}
