#ifndef RLUTILS_OS
#define RLUTILS_OS





namespace rlUtils
{
	
	enum class OS
	{
		Android,
		iOS,
		iOSSimulator,
		Linux,
		MacOS,
		MacCatalyst,
		POSIX,
		UNIX,
		Windows
	};

#define RLUTILS_OS_ANDROID      'A'
#define RLUTILS_OS_IOS          'I'
#define RLUTILS_OS_IOSSIMULATOR 'i'
#define RLUTILS_OS_LINUX        'L'
#define RLUTILS_OS_MACOS        'M'
#define RLUTILS_OS_MACCATALYST  'm'
#define RLUTILS_OS_POSIX        'P'
#define RLUTILS_OS_UNIX         'U'
#define RLUTILS_OS_WINDOWS      'W'

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	
	constexpr OS CurrentOS = OS::Windows;
#define RLUTILS_OS_CURRENT RLUTILS_OS_WINDOWS

#elif __APPLE__
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR // iOS, tvOS, or watchOS Simulator

	constexpr OS CurrentOS = OS::iOSSimulator;
#define RLUTILS_OS_CURRENT RLUTILS_OS_IOSSIMULATOR

#elif TARGET_OS_MACCATALYST // Mac's Catalyst (ports iOS API into Mac, like UIKit)

	constexpr OS CurrentOS = OS::MacCatalyst;
#define RLUTILS_OS_CURRENT RLUTILS_OS_MACCATALYST

#elif TARGET_OS_IPHONE // iOS, tvOS, or watchOS device

	constexpr OS CurrentOS = OS::iOS;
#define RLUTILS_OS_CURRENT RLUTILS_OS_IOS

#elif TARGET_OS_MAC // Other kinds of Apple platforms

	constexpr OS CurrentOS = OS::MacOS;
#define RLUTILS_OS_CURRENT RLUTILS_OS_MACOS

#else
#   error "Unknown Apple platform"
#endif
#elif __ANDROID__

	constexpr OS CurrentOS = OS::Android;
#define RLUTILS_OS_CURRENT RLUTILS_OS_ANDROID

#elif __linux__

	constexpr OS CurrentOS = OS::Linux;
#define RLUTILS_OS_CURRENT RLUTILS_OS_LINUX

#elif __unix__ // all unices not caught above

	constexpr OS CurrentOS = OS::UNIX;
#define RLUTILS_OS_CURRENT RLUTILS_OS_UNIX

#elif defined(_POSIX_VERSION)

	constexpr OS CurrentOS = OS::POSIX;
#define RLUTILS_OS_CURRENT RLUTILS_OS_POSIX

#else
#   error "Unknown compiler"
#endif


}





#endif // RLUTILS_OS