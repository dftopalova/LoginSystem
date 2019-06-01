#include "Guest.h"

void Guest::setIP(const char * ip)
{
	if (ip == nullptr)
		return;
	int len = strlen(ip) + 1;
	delete[] this->ipAddress;
	this->ipAddress = new char[len];
	strcpy_s(ipAddress, len, ip);
}

Guest::Guest()
	:ipAddress(nullptr)
{
	setIP("");
}

Guest::Guest(const char * ip)
	: ipAddress(nullptr)
{
	setIP(ip);
}

Guest::Guest(const Guest & other)
	:ipAddress(nullptr)
{
	setIP(other.ipAddress);
}

Guest & Guest::operator=(const Guest & other)
{
	if (this != &other)
	{
		setIP(other.ipAddress);
	}
	return *this;
}

Guest::~Guest()
{
	delete[] this->ipAddress;
}
