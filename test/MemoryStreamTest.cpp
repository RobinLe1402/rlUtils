#include "MemoryStreamTest.hpp"

#include <rlUtils/MemoryStream.hpp>

bool TestMemoryStream()
{
	constexpr char oTESTDATA[] =
	{
		'\r',
		'\n',
		1,
		0
	};

	rlUtils::MemoryStream memstream(oTESTDATA, sizeof(oTESTDATA));

	if (memstream.tellg() != 0)
		return false;

	char szBuf[2] = {};
	if (!memstream.read(szBuf, 1) || szBuf[0] != '\r')
		return false;

	if (!memstream.read(szBuf, 2) || szBuf[0] != '\n' || szBuf[1] != 1)
		return false;

	if (!memstream.read(szBuf, 1) || szBuf[0] != 0)
		return false;

	if (memstream.tellg() != 4)
		return false;

	if (memstream.peek() != EOF)
		return false;

	return true;
}
