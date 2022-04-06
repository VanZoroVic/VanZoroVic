#include <iostream>
#include <string>
#include <WS2tcpip.h>
#include <cstddef>
#include <iostream>
#include <string>
#pragma comment(lib, "ws2_32.lib")

using namespace std;
std::string str;
int tutar;
int bytesReceived, i;
char y[10], c[10], t[10];

void main()
{
	string ipAddress = "127.0.0.1";			
	int port = 54000;						

	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0)
	{
		cerr << "Can't start Winsock, Err #" << wsResult << endl;
		return;
	}

	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET)
	{
		cerr << "Can't create socket, Err #" << WSAGetLastError() << endl;
		WSACleanup();
		return;
	}

	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
	if (connResult == SOCKET_ERROR)
	{
		cerr << "Can't connect to server, Err #" << WSAGetLastError() << endl;
		closesocket(sock);
		WSACleanup();
		return;
	}

	char buf[4096];
	string userInput, kullanici, sifre, kisi, strislem,
		islem, transfer("transfer"), yatir("1"), cek("cek");

	do
	{
	basla:

		if (i == 0)
		{
			system("CLS");
			cout << "\n";
			cout << "Kullanici Adiniz : \n";
			getline(cin, userInput);
			kullanici = userInput;
			Sleep(200);
		}
		if (i == 1)
		{
			cout << "Sifre lutfen  : \n";
			getline(cin, userInput);
			sifre = userInput;
			Sleep(200);
			system("CLS");
		}
		if (kullanici == "emre" && sifre == "1234" || kullanici == "volkan" && sifre == "4567" || kullanici == "behice" && sifre == "7890") 
		{
			if (i == 3)
			{
				cout << "\n";
				cout << "Bakiyeniz: ";	// recv(sock, buf, 4096, 0);
				cout << "\n\n";
				cout << "Isleminizi Secin. \n";
				cout << "Para yatirmak icin  :   yatir\n";
				cout << "Para cekmek icin    :   cek\n";
				cout << "Para transferi icin :   transfer\n";
				getline(cin, userInput);
				Sleep(200);
				islem = userInput;
				str = islem;

				if (str.find('1') == 0)
				{
					islem = yatir;
					if (islem == yatir || str.find('1') == 0)
					{
						cout << "Yatirmak istediginiz tutar: \n";
						cout << "10 TL ve katlari. \n";
						cout << "Tutar = ";
						getline(cin, userInput);
						//tutar = stoi(userInput);
						i = -1;
					}
				}
				if (str.find('c') == 0)
				{
					islem = cek;
					if (islem == cek || str.find('c') == 0)
					{
						cout << "Cekmek istediginiz tutar: \n";
						cout << "10 TL ve katlari. \n";
						cout << "Tutar = ";
						getline(cin, userInput);
						//tutar = stoi(userInput);
						i = -1;
					}
				}
				if (str.find('t') == 0)
				{
					islem = transfer;
					if (islem == transfer || str[0] == t[0])
					{
						cout << "Gonderilecek kisi : (volkanaslan, behiceaslan)\n";
						getline(cin, userInput);
						if (userInput == "volkanaslan" || userInput == "behiceaslan")
						{
							if (userInput == "behiceaslan")
								cout << "Islem ucreti = 5 TL\n\n";

							cout << "Transfer etmek istediginiz tutar: \n";
							getline(cin, userInput);
							if (userInput <= "9") 
							{
								cout << "10 TL ve uzeri transfer yapabilirsiniz.\n";
								system("CLS");
								i = 0;
								goto basla;
							}
						}
					}
				}
			}
		}
		if (userInput.size() > 0)
		{		
			int sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);
			if (sendResult != SOCKET_ERROR)
			{
				i++;
				
				ZeroMemory(buf, 4096);
				bytesReceived = recv(sock, buf, 4096, 0);
				if (bytesReceived > 0)
				{


				}
			}
		}
	} while (userInput.size() > 0);

	closesocket(sock);
	WSACleanup();
}