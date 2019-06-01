#pragma once
#include "User.h"

class VIP : virtual public User
{
public:
	VIP(const char* uName, const char* Password, const char* Title, const char* ip);
	
	VIP();
	VIP(const VIP& other);
	VIP& operator=(const VIP& other);
	~VIP();

	void setVipTitle(const char* newTitle);
	void print() const;
};