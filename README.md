# loadParams

ROS paramみたいにパラメータやファイルパスをビルドレスで設定できる環境が欲しかった．

### 動作環境

|||
|:--:|:--:|
|C++|C++11以上|
|gcc|gcc-5.6以上|
|cmake|cmake-3.5以上|


### Build

```
{workspace}$ mkdir build
$ cd build 
$ cmake ..
$ make
```

### 対応している型

- std::string
- bool
- int
- unsigned long
- unsigned long long
- float
- double
- long double
