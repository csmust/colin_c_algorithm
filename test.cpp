#include<string.h>
#include<iostream>
#include<stdlib.h>
// #include<string.h>

using namespace std;
int main()
{
	//C风格字符串
	char  str1[] = "helloworld";
	cout << str1 << endl;

	//C++风格字符串 如果报错就 #include<string>
	// string str2 = "helloworld2";
	// cout << str2 << endl;

	string s = "h";
	cout << s.size() << endl;
	// system("pause");

	return 0;

}
