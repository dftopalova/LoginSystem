#pragma once
#include"Guest.h"
#include<iostream>

class User : public Guest
{
private:
	char* userName;
	char* password;
	char* title;

	void encrypt(const char* str, char* encrypted);
	void setPassword(const char* newPassword);
	void setUserName(const char* uName);
	void setTitle(const char* Title);
	const char* getPassword() const;
	const char* getTitle() const;

public:
	User();
	User(const char* Name, const char* passw, const char* Title, const char* ip);
	User(const User& other);
	User& operator=(const User& other);
	~User();

	const char* getUserName() const; 
	void setNewPassword(const char* oldPassword, const char* newPassword);
	void print() const;
	  
	friend class Admin; // so Admin will have access to userName
	friend class VIP; // so VIP will have access to title
};