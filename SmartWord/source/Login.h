#ifndef LOGIN_H
#define LOGIN_H

#include <string>
#include <vector>

class Login
{
public:
    Login();
    virtual ~Login();
	void CallHelper();
	void GotoProcessor();
private:
	std::string user_name_;
};

#endif // LOGIN_H
