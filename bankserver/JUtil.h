#ifndef _JUTIL_H_
#define _JUTIL_H_

#include <string>
using namespace std;

class Convert
{
public:
	static int StringToInt(const string& str);
	static string IntToString(int x);
	static double StringToDouble(const string& str);
	static string DoubleToString(double x);
};

#endif // _JUTIL_H_

