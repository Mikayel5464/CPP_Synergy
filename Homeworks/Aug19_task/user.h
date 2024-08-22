#ifndef __User_H__
#define __User_H__

class User {
private:
	std::string fullname;
	std::string email;
	std::string password;
public:
	User();
	User(std::string, std::string, std::string);
	
	void setFullName(std::string);
	void setEmail(std::string);
	void setPassword(std::string);
	std::string getFullName();
	std::string getEmail();
	std::string getPassword();
	
	void changePassword(std::string);
	void updateEmail(std::string);

	void foo(User*);
};

#endif
