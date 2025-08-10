use cxx::{CxxVector, UniquePtr};
use std::pin::Pin;

use crate::ftheta::project_points;

#[cxx::bridge]
mod ffi {

    extern "Rust" {
        fn say_hello();
        fn print_vec(vec: Pin<&mut CxxVector<f32>>);
        fn project_points_impl(
            camera_params: &CxxVector<f32>,
            distortion_params: &CxxVector<f32>,
            p3ds: &CxxVector<f32>,
            p2ds: Pin<&mut CxxVector<f32>>,
        );
    }
}

pub fn say_hello() {
    println!("Hello from Rust!");
}

fn print_vec(vec: Pin<&mut CxxVector<f32>>) {
    vec.iter_mut().for_each(|i| {
        println!("{}", i);
        unsafe {
            let a = i.get_unchecked_mut();
            *a = 255.0 - *a;
        }
    });
}

fn project_points_impl(
    camera_params: &CxxVector<f32>,
    distortion_params: &CxxVector<f32>,
    p3ds: &CxxVector<f32>,
    p2ds: Pin<&mut CxxVector<f32>>,
) {
    if p3ds.len() / 3 != p2ds.len() / 2 {
        panic!("aaa")
    }
}
