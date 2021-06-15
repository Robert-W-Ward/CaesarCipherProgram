#include <iostream>
#include <sstream>
#include <string>
using namespace std;

enum choices
{
	_Encrypt=1, _Decrypt, _EXIT
};
string Encrypt(string message,int key)
{
	string result{""};
	for(char& x : message)
	{
		if(isupper(x))
		{
			result += char(int(x + key - 65) % 26 + 65);
		}
		else
		{
			result += char(int(x + key - 97) % 26 + 97);
		}
	}
	
	return result;
}
string Decrypt(string message,int key)
{
	string result{""};
	
	for(char& x : message)
	{
		if(isupper(x))
		{
			char N = char(int(x - key % 26));
			if(65 <= N&&N <= 90)
			{
				result += N;
			}
			else if(int(N) > 90)
			{
				N = N - 'Z' + 'A' - 1;
				result += N;
			}
			else if(int(N) < 65)
			{
				N = N + 'Z' - 'A' + 1;
				result += N;
			}

		}
		else
		{
			char N = char(int(x - key % 26));
			if(97 <= N&&N <= 122)
			{
				result += N;
			}
			else if(N > 122)
			{
				N = N - 'z' + 'a' - 1;
				result += N;
			}
			else if(N < 97)
			{
				N = N + 'z' - 'a' + 1;
				result += N;
			}
		}
		
	}
	return result;
}
int main()
{
	int choice{0};
	int key{0};
	bool isRunning{ true };
	string message;

	while(isRunning)
	{

		cout << " 1.Encrypt\n 2.Decrypt\n 3.exit\n";
		
		cin >> choice;

		switch(choice)
		{
		case choices::_Encrypt:
			cout << "Enter a Message containing only letters and without spaces to encrypt\n";			

			cin >> message;

			cin.clear();

			cout << "Enter a value between 0 and 25\n";

			cin >> key;
			
			cout << "The encrypted message is :" << Encrypt(message, key)<<"\n";
			break;
		case choices::_Decrypt:
			cout << "Enter a message that has been encrypted using the Caesar Cipher\n";
			cin >> message;
			cout << "Enter the known cipher key between 0 and 25\n";
			cin >> key;
			cout<<"The decrypted message is :"<<Decrypt(message, key)<<"\n";
			break;
		case choices::_EXIT:
			isRunning = false;
			break;
		default:
			break;
		}
	}
			
		
}

