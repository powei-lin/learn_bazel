load("@crates//:defs.bzl", "aliases", "all_crate_deps")
load("@rules_rust//rust:defs.bzl", "rust_binary", "rust_library")
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_binary")
load("//tools/bazel:rust_cxx_bridge.bzl", "rust_cxx_bridge")

package(default_visibility = ["//visibility:public"])

rust_library(
    name = "rustlib",
    edition = "2024",
    visibility = ["//visibility:public"],
    aliases = aliases(),
    srcs = glob(["src/**/*.rs"]),
    deps = all_crate_deps(
        normal = True,
    ),
    proc_macro_deps = all_crate_deps(
        proc_macro = True,
    ),
)

rust_cxx_bridge(
    name = "bridge",
    src = "src/bridge.rs",
    deps = [
        ":rustlib"
    ]
)

cc_library(
    name = "ftheta",
    srcs = glob([
        "cpp/*.cpp",
    ]),
    hdrs = glob([
        "cpp/*.h",
    ]),
    deps = [
        ":bridge",
        "@opencv//:opencv",
    ],
    linkstatic = True,
)