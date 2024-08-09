#ifndef RLUTILS_ENDIAN
#define RLUTILS_ENDIAN





#include <cstdint>



namespace rlUtils
{

	enum class Endian
	{
		Big,
		Mixed,
		Little
	};

	constexpr Endian SystemEndian =
		(const uint8_t &)0x01020304 == 0x01 ? Endian::Big :
		(const uint8_t &)0x01020304 == 0x04 ? Endian::Little :
		Endian::Mixed;



	constexpr inline uint16_t SwapEndian(uint16_t val)
	{
		return (val >> 8) | (val << 8);
	}

	constexpr inline uint32_t SwapEndian(uint32_t val)
	{
		return ((val >> 24) & 0x000000FF) |
		       ((val >>  8) & 0x0000FF00) |
		       ((val <<  8) & 0x00FF0000) |
		       ((val << 24) & 0xFF000000);
	}

	constexpr inline uint64_t SwapEndian(uint64_t val)
	{
		return ((val >> 56) & 0x00000000000000FF) |
		       ((val >> 40) & 0x000000000000FF00) |
		       ((val >> 24) & 0x0000000000FF0000) |
		       ((val >>  8) & 0x00000000FF000000) |
		       ((val <<  8) & 0x000000FF00000000) |
		       ((val << 24) & 0x0000FF0000000000) |
		       ((val << 40) & 0x00FF000000000000) |
		       ((val << 56) & 0xFF00000000000000);
	}



	namespace ChangeEndian
	{

#define DECLARE_LETOHOST(type)                                                  \
		constexpr inline type LEtoHost(type iLE)                                \
		{                                                                       \
			static_assert(SystemEndian != Endian::Mixed,                        \
				"rlUtils doesn't support conversions involving mixed endian."); \
			                                                                    \
			if constexpr (SystemEndian == Endian::Little)                       \
				return iLE;	                                                    \
			else                                                                \
				return SwapEndian(iLE);                                         \
		}

		DECLARE_LETOHOST(uint16_t)
		DECLARE_LETOHOST(uint32_t)
		DECLARE_LETOHOST(uint64_t)

#undef DECLARE_LETOHOST



#define DECLARE_BETOHOST(type)                                                  \
		constexpr inline type BEtoHost(type iBE)                                \
		{                                                                       \
			static_assert(SystemEndian != Endian::Mixed,                        \
				"rlUtils doesn't support conversions involving mixed endian."); \
			                                                                    \
			if constexpr (SystemEndian == Endian::Little)                       \
				return SwapEndian(iBE);	                                        \
			else                                                                \
				return iBE;                                                     \
		}

		DECLARE_BETOHOST(uint16_t)
		DECLARE_BETOHOST(uint32_t)
		DECLARE_BETOHOST(uint64_t)

#undef DECLARE_BETOHOST



#define DECLARE_HOSTTOLE(type)                                                  \
		constexpr inline type HostToLE(type iHost)                              \
		{                                                                       \
			static_assert(SystemEndian != Endian::Mixed,                        \
				"rlUtils doesn't support conversions involving mixed endian."); \
			                                                                    \
			if constexpr (SystemEndian == Endian::Little)                       \
				return iHost;	                                                \
			else                                                                \
				return SwapEndian(iHost);                                       \
		}

		DECLARE_HOSTTOLE(uint16_t)
		DECLARE_HOSTTOLE(uint32_t)
		DECLARE_HOSTTOLE(uint64_t)

#undef DECLARE_HOSTTOLE



#define DECLARE_HOSTTOBE(type)                                                  \
		constexpr inline type HostToBE(type iHost)                              \
		{                                                                       \
			static_assert(SystemEndian != Endian::Mixed,                        \
				"rlUtils doesn't support conversions involving mixed endian."); \
			                                                                    \
			if constexpr (SystemEndian == Endian::Little)                       \
				return SwapEndian(iHost);	                                    \
			else                                                                \
				return iHost;                                                   \
		}

		DECLARE_HOSTTOBE(uint16_t)
		DECLARE_HOSTTOBE(uint32_t)
		DECLARE_HOSTTOBE(uint64_t)

#undef DECLARE_HOSTTOBE

	}

}





#endif // RLUTILS_ENDIAN