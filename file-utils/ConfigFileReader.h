#include "headers.h"

class CConfigFileReader
{
public:
	CConfigFileReader(const char* filename);
	~CConfigFileReader();

	char* GetConfigName(const char* name);
private:
	void _LoadFile(const char* filename);
	void _ParseLine(char* line);
	char* _TrimSpace(char* name);

	bool					m_load_ok;
	map<string, string>*	m_config_map;
};
