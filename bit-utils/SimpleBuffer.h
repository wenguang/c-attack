#include "headers.h"

using namespace std;

class CSimpleBuffer
{
public:
	CSimpleBuffer();
	~CSimpleBuffer();
	char*  GetBuffer() { return m_buffer; }
	uint GetAllocSize() { return m_alloc_size; }
	uint GetWriteOffset() { return m_write_offset; }
	void IncWriteOffset(uint len) { m_write_offset += len; }

	void Extend(uint len);
	uint Write(void* buf, uint len);
	uint Read(void* buf, uint len);
private:
	char*	m_buffer;
	uint	m_alloc_size;
	uint	m_write_offset;
};