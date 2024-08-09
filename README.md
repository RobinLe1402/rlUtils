# rlUtils - My C++ Utility Toolkit

This repository contains code I wrote for use across multiple of my projects.
In part, the code might be header-only, however, I recommend including the static library in any
case, as I might move code into `.cpp` files at any point.


## List of Utilities

### OS
Check the operating system the code is being compiled on via `constexpr` values or preprocessor
definitions.

The following OS's are supported at the moment:
- Android
- iOS
- iOSSimulator
- Linux
- MacOS
- MacCatalyst
- POSIX
- UNIX
- Windows

#### Sample code
```cpp
if constexpr (rlUtils::CurrentOS == rlUtils::OS::Windows)
	std::printf("Have you ever considered switching to Linux? :)");
	
#if RLUTILS_OS_CURRENT == RLUTILS_OS_MACOS
	std::printf("Have you ever considered switching to Linux? :)");
#endif
```


### Endian
Get the current endian + convert between endians with `inline constexpr` functions.

The following endians can be detected:
- Little Endian
- Big Endian
- Mixed Endian

You can convert between the following endians:
- Little Endian
- Big Endian


#### Sample code
```cpp
file.read(&i16, sizeof(i16));
i16 = rlUtils::ChangeEndian::BEToHost(i16);

// ...

i64 = rlUtils::ChangeEndian::HostToLE(i64);
file.write(&i64, sizeof(i64));
```
