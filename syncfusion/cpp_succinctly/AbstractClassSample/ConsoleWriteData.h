#pragma once
#include "IWriteData.h"

class ConsoleWriteData : public IWriteData {
public:
	ConsoleWriteData(void) {}
	virtual ~ConsoleWriteData(void) {}

	virtual void Write(const wchar_t* value);
	virtual void Write(double value);
	virtual void Write(int value);

	virtual void WriteLine(void);
	virtual void WriteLine(const wchar_t* value);
	virtual void WriteLine(double value);
	virtual void WriteLine(int value);
};
