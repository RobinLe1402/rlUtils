#include "EndianTest.hpp"

#include <rlUtils/Endian.hpp>

#include <cstdint>

namespace
{

	template <typename T>
	union byteint
	{
		uint8_t bytes[sizeof(T)];
		T val;
	};
	using byteint16 = byteint<uint16_t>;
	using byteint32 = byteint<uint32_t>;
	using byteint64 = byteint<uint64_t>;

}

bool TestEndianConversionToHost()
{
	constexpr byteint16 bi16 = { .bytes = { 0x01,0x02 } };
	constexpr byteint32 bi32 = { .bytes = { 0x01,0x02,0x03,0x04 } };
	constexpr byteint64 bi64 = { .bytes = { 0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08 } };

	constexpr uint16_t i16B = 0x0102;
	constexpr uint16_t i16L = 0x0201;
	constexpr uint32_t i32B = 0x01020304;
	constexpr uint32_t i32L = 0x04030201;
	constexpr uint64_t i64B = 0x0102030405060708;
	constexpr uint64_t i64L = 0x0807060504030201;

	return rlUtils::ChangeEndian::BEtoHost(bi16.val) == i16B &&
	       rlUtils::ChangeEndian::LEtoHost(bi16.val) == i16L &&
	       rlUtils::ChangeEndian::BEtoHost(bi32.val) == i32B &&
	       rlUtils::ChangeEndian::LEtoHost(bi32.val) == i32L &&
	       rlUtils::ChangeEndian::BEtoHost(bi64.val) == i64B &&
	       rlUtils::ChangeEndian::LEtoHost(bi64.val) == i64L;
}

bool TestEndianConversionFromHost()
{
	constexpr uint16_t i16 = 0x0102;
	constexpr uint32_t i32 = 0x01020304;
	constexpr uint64_t i64 = 0x0102030405060708;

	namespace ce = rlUtils::ChangeEndian;

	return ce::BEtoHost(ce::HostToBE(i16)) == i16 &&
	       ce::LEtoHost(ce::HostToLE(i16)) == i16 &&
	       ce::BEtoHost(ce::HostToBE(i32)) == i32 &&
	       ce::LEtoHost(ce::HostToLE(i32)) == i32 &&
	       ce::BEtoHost(ce::HostToBE(i64)) == i64 &&
	       ce::LEtoHost(ce::HostToLE(i64)) == i64;
}
