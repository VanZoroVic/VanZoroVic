#include <iostream>
#include <WS2tcpip.h>
#include <string>
#include <fstream>
#include <istream>
#include <sstream>
#include <conio.h>
#include <windows.h>
#include <typeinfo>

int sifre, tutar, sonuc, ucret = 0;
int  kullaniciEmre = 1234, kullaniciEmreSifre = 1234,
kullaniciVolkan = 4567, kullaniciVolkanSifre = 4567,
kullaniciBehice = 7890, kullaniciBehiceSifre = 7890;
int dizi[10][10];

#pragma comment (lib, "ws2_32.lib")

using namespace std;

void main()
{
	WSADATA wsData;
	WORD ver = MAKEWORD(2, 2);

	int wsOk = WSAStartup(ver, &wsData);
	if (wsOk != 0)
	{
		cerr << "Can't Initialize winsock! Quitting" << endl;
		return;
	}

	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET)
	{
		cerr << "Can't create a socket! Quitting" << endl;
		return;
	}

	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(54000);
	hint.sin_addr.S_un.S_addr = INADDR_ANY;

	bind(listening, (sockaddr*)&hint, sizeof(hint));

	listen(listening, SOMAXCONN);

	sockaddr_in client;
	int clientSize = sizeof(client);

	SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

	char host[NI_MAXHOST];
	char service[NI_MAXSERV];

	ZeroMemory(host, NI_MAXHOST);
	ZeroMemory(service, NI_MAXSERV);

	if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
	{
		cout << host << " connected on port " << service << endl;
	}
	else
	{
		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
		cout << host << " connected on port " <<
			ntohs(client.sin_port) << endl;
	}

	closesocket(listening);

	char buf[4096];

	while (true)
	{
		ZeroMemory(buf, 4096);

		int bytesReceived = recv(clientSocket, buf, 4096, 0);
		if (bytesReceived == SOCKET_ERROR)
		{
			cerr << "Error in recv(). Quitting" << endl;
			break;
		}

		if (bytesReceived == 0)
		{
			cout << "Client disconnected " << endl;
			break;
		}

		string emre("emre"), emreaslan("emreaslan"),
			volkan("volkan"), volkanaslan("volkanaslan"),
			behice("behice"), behiceaslan("behiceaslan"),
			islem, kisi, transfer("t"), yatir("y"),
			cek("c"), kullanici;

		kullanici = string(buf, 0, bytesReceived);

		if (yatir == kullanici)
		{
			islem = yatir;
			dizi[1][1] = 1;
		}
		else if (cek == kullanici)
		{
			islem = cek;
			dizi[1][1] = 2;
		}
		else if (transfer == kullanici)
		{
			islem = transfer;
			dizi[1][1] = 3;
		}
		if (emre == kullanici || dizi[0][0] == 1234)
		{
			system("CLS");
			for (int i = 0; i < 1; i++)
			{
				dizi[0][0] = kullaniciEmre;
			}
			if ("1234" == kullanici || dizi[0][1] == 1234)
			{
				for (int j = 0; j < 1; j++)
				{
					dizi[0][1] = kullaniciEmreSifre;
				}
				cout << "Emre Hesabinda " << bytesReceived << "\n";
				cout << "Emre Hesabinda " << kullanici << "\n";
				cout << "Emre Hesabinda " << buf << "--\n";
				cout << "Emre Hesabinda " << string(buf, 0, bytesReceived) << "//" << endl;

				if (kullaniciEmre == dizi[0][0] && kullaniciEmreSifre == dizi[0][1]) 
				{
					ifstream dosyaOku("EmreBakiye.txt");
					string satir = "";
					if (dosyaOku.is_open()) 
					{
						while (getline(dosyaOku, satir)) 
						{
							string strbakiye = satir;
							int bakiye = stoi(strbakiye);
							cout << "Emre ASLAN Hosgeldiniz. \n";
							cout << "\n";
							cout << "Bakiyeniz: " << bakiye;
							cout << "\n\n";
							cout << "Isleminizi Secin. \n";
							cout << "Para yatirmak icin  :   y\n";
							cout << "Para cekmek icin    :   c\n";
							cout << "Para transferi icin :   t\n";

							if (yatir == kullanici)
							{
								islem = yatir;
								dizi[1][1] = 1;
							}
							else if (cek == kullanici)
							{
								islem = cek;
								dizi[1][1] = 2;
							}
							else if (transfer == kullanici)
							{
								islem = transfer;
								dizi[1][1] = 3;
							}
							if (yatir == islem || dizi[1][1] == 1)
							{
								islem = yatir;
								cout << "Yatirmak istediginiz tutar = ";								
								bakiye = bakiye + tutar;
								dizi[0][0] = 0;
								dizi[0][1] = 0;								
							}
							if (cek == islem || dizi[1][1] == 2)
							{
								islem = cek;
								cout << "Cekmek istediginiz tutar = ";
								dizi[0][0] = 0;
								dizi[0][1] = 0;
							}
							if (transfer == islem || dizi[1][1] == 3)
							{
								islem = transfer;
								cout << "Transfer istediginiz tutar = ";
								dizi[0][0] = 0;
								dizi[0][1] = 0;
							}
							string strsonuc;
							strsonuc = to_string(sonuc);
							ofstream dosyaYaz("EmreBakiye.txt");
							if (dosyaYaz.is_open()) 
							{
								dosyaYaz << strsonuc;
								dosyaYaz.close();
							}
							dosyaOku.close();
						}
					}
				}
			}
		}
		if (volkan == kullanici || dizi[0][0] == 4567)
		{
			system("CLS");
			for (int i = 0; i < 1; i++)
			{
				dizi[0][0] = kullaniciVolkan;
			}
			if ("4567" == kullanici || dizi[0][1] == 4567)
			{
				for (int j = 0; j < 1; j++)
				{
					dizi[0][1] = kullaniciVolkanSifre;
				}
				cout << "Volkan Hesabinda " << bytesReceived << "\n";
				cout << "Volkan Hesabinda " << kullanici << "\n";
				cout << "Volkan Hesabinda " << buf << "--\n";
				cout << "Volkan Hesabinda " << string(buf, 0, bytesReceived) << "//" << endl;

				if (kullaniciVolkan == dizi[0][0] && kullaniciVolkanSifre == dizi[0][1]) 
				{					
					ifstream dosyaOku("VolkanBakiye.txt");
					string satir = "";
					if (dosyaOku.is_open()) 
					{
						while (getline(dosyaOku, satir)) 
						{
							string strbakiye = satir;
							int bakiye = stoi(strbakiye);
							cout << "Volkan ASLAN Hosgeldiniz. \n";
							cout << "\n";
							cout << "Bakiyeniz: " << bakiye;
							cout << "\n\n";
							cout << "Isleminizi Secin. \n";
							cout << "Para yatirmak icin  :   y\n";
							cout << "Para cekmek icin    :   c\n";
							cout << "Para transferi icin :   t\n";

							if (yatir == kullanici)
							{
								islem = yatir;
								dizi[1][1] = 1;
							}
							else if (cek == kullanici)
							{
								islem = cek;
								dizi[1][1] = 2;
							}
							else if (transfer == kullanici)
							{
								islem = transfer;
								dizi[1][1] = 3;
							}
							if (yatir == islem || dizi[1][1] == 1)
							{
								islem = yatir;
								cout << "Yatirmak istediginiz tutar = ";
								bakiye = bakiye + tutar;
								dizi[0][0] = 0;
								dizi[0][1] = 0;
							}
							if (cek == islem || dizi[1][1] == 2)
							{
								islem = cek;
								cout << "Cekmek istediginiz tutar = ";
								dizi[0][0] = 0;
								dizi[0][1] = 0;
							}
							if (transfer == islem || dizi[1][1] == 3)
							{
								islem = transfer;
								cout << "Transfer istediginiz tutar = ";
								dizi[0][0] = 0;
								dizi[0][1] = 0;
							}
							string strsonuc;
							strsonuc = to_string(sonuc);
							ofstream dosyaYaz("VolkanBakiye.txt");
							if (dosyaYaz.is_open()) 
							{
								dosyaYaz << strsonuc;
								dosyaYaz.close();
							}
							dosyaOku.close();
						}
					}
				}
			}
		}
		send(clientSocket, buf, bytesReceived + 1, 0);
	}
	closesocket(clientSocket);
	WSACleanup();
	system("pause");
}