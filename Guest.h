#pragma once
#include<cstring>

class Guest
{
private:
	char* ipAddress;
	void setIP(const char* ip);
public:
	Guest();
	Guest(const char* ip);
	Guest(const Guest& other);
	Guest& operator=(const Guest& other);
	~Guest();
};
