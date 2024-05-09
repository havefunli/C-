#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

int main() {
	//string s1("abc");
	//string s2 = s1;
	//string s3 = s1;

	/*string str("Hello Bit.");

	str.reserve(111);

	str.resize(5);

	str.reserve(50);

	cout << str.size() << ":" << str.capacity() << endl;

	return 0;*/

	/*string strText = "How are you?";

	string strSeparator = " ";

	string strResult;

	int size_pos = 0;

	int size_prev_pos = 0;

	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)

	{

		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);

		cout << strResult << " ";

		size_prev_pos = ++size_pos;

	}

	if (size_prev_pos != strText.size())

	{

		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);

		cout << strResult << " ";

	}

	cout << endl;

	return 0;*/

	/*string word;

	getline(cin,word);

	if(word.find(" ")!=string::npos)
		cout << (word.size() - word.find_last_of(" ") - 1);
	else
		cout << word.size();*/

	string str;
	getline(cin, str);
	string s1;
	string s2(0);

	for (size_t i = 0; i < str.size(); i++){
		if (isalnum(str[i])) {
			s1 += tolower(str[i]);
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			s1 += str[i];
		}
	}

	cout << str << endl;
	cout << s1 << endl;
	cout << s1 << endl;


	string s("abc");
	string sgood;
	for (char ch : s) {
		if (isalnum(ch)) {
			sgood += tolower(ch);
		}
	}
	string sgood_rev(sgood.rbegin(), sgood.rend());
	return sgood == sgood_rev;
}