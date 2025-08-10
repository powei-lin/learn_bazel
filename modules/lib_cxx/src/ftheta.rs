use rayon::prelude::*;

fn f_theta(k2: f32, k3: f32, k4: f32, k5: f32, k6: f32, theta: f32) -> f32 {
    let theta2 = theta * theta;
    let theta3 = theta2 * theta;
    let theta4 = theta3 * theta;
    let theta5 = theta4 * theta;
    let theta6 = theta5 * theta;

    theta + k2 * theta2 + k3 * theta3 + k4 * theta4 + k5 * theta5 + k6 * theta6
}

fn df_dtheta(k2: f32, k3: f32, k4: f32, k5: f32, k6: f32, theta: f32) -> f32 {
    let theta2 = theta * theta;
    let theta3 = theta2 * theta;
    let theta4 = theta3 * theta;
    let theta5 = theta4 * theta;

    1.0 + 2.0 * k2 * theta
        + 3.0 * k3 * theta2
        + 4.0 * k4 * theta3
        + 5.0 * k5 * theta4
        + 6.0 * k6 * theta5
}

pub fn project_one(camera_params: &[f32], distortion_params: &[f32], p3d: &[f32; 3]) -> [f32; 2] {
    // let params = self.params();
    let xn = p3d[0] / p3d[2];
    let yn = p3d[1] / p3d[2];
    let r2 = xn * xn + yn * yn;
    let r = r2.sqrt();
    let theta = r.atan();

    let fx = camera_params[0];
    let fy = camera_params[1];
    let cx = camera_params[2];
    let cy = camera_params[3];

    let k2 = distortion_params[1];
    let k3 = distortion_params[2];
    let k4 = distortion_params[3];
    let k5 = distortion_params[4];
    let k6 = distortion_params[5];

    let theta_d = f_theta(k2, k3, k4, k5, k6, theta);
    let d = theta_d / r;
    let px = fx * (xn * d) + cx;
    let py = fy * (yn * d) + cy;
    [px, py]
}

pub fn project_points(
    camera_params: &[f32],
    distortion_params: &[f32],
    p3ds: &[f32],
) -> Vec<[f32; 2]> {
    let fx = camera_params[0];
    let fy = camera_params[1];
    let cx = camera_params[2];
    let cy = camera_params[3];

    let k2 = distortion_params[1];
    let k3 = distortion_params[2];
    let k4 = distortion_params[3];
    let k5 = distortion_params[4];
    let k6 = distortion_params[5];

    p3ds.par_chunks(3)
        .map(|p3d| {
            let xn = p3d[0] / p3d[2];
            let yn = p3d[1] / p3d[2];
            let r2 = xn * xn + yn * yn;
            let r = r2.sqrt();
            let theta = r.atan();

            let theta_d = f_theta(k2, k3, k4, k5, k6, theta);
            let d = theta_d / r;
            let px = fx * (xn * d) + cx;
            let py = fy * (yn * d) + cy;
            [px, py]
        })
        .collect()
}
