# pybindprofile
pybind 性能测试

```shell
export https_proxy="http://127.0.0.1:1080"
export http_proxy="http://127.0.0.1:1080"
``` 

## test

```shell
bazel run  src_cpp:number_arr_test
bazel run  src_cpp:data_owner_test
bazel run  src_cpp:operation_test
bazel run  src_cpp:wrapper_test
```