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
	std::printf("");
#endif
```
