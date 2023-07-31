package(default_visibility = ["//visibility:public"])

load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "number_arr",
    srcs = [
        "NumberArr.cc",
    ],
    hdrs = [
        "NumberArr.h",
    ],
)
cc_library(
    name = "data_owner",
    srcs = [
        "DataOwner.cc",
    ],
    hdrs = [
        "DataOwner.h",
    ],
    deps = [
        "//src_cpp:number_arr"
    ]
)



cc_library(
    name = "operation",
    srcs = [
        "Operation.cc",
    ],
    hdrs = [
        "Operation.h",
    ],
    deps =[
        "//src_cpp:number_arr",
        "//src_cpp:data_owner"
    ]
)



cc_binary(
    name = "number_arr_test",
    srcs = [
        "NumberArrTest.cc",
    ],
    deps = [
        "//src_cpp:number_arr",
    ],
)
cc_binary(
    name = "data_owner_test",
    srcs = [
        "DataOwnerTest.cc",
    ],
    deps = [
        "//src_cpp:data_owner",
    ],
)
cc_binary(
    name = "operation_test",
    srcs = [
        "OperationTest.cc",
    ],
    deps = [
        "//src_cpp:number_arr",
        "//src_cpp:data_owner",
        "//src_cpp:operation",
    ],
)

cc_binary(
    name = "wrapper_test",
    srcs = [
        "WrapperTest.cc",
    ],
    deps = [
        "//src_cpp:number_arr",
        "//src_cpp:data_owner",
        "//src_cpp:operation",
    ],
)

