#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <typeinfo>
int kullanici, sifre, tutar, sonuc, islem, transfer, ucret = 0;
int  kullaniciEmreSifre = 1234, kullaniciVolkanSifre = 4567, kullaniciBehiceSifre = 7890, kisi = 0;
int kullaniciEmre = 1234, kullaniciVolkan = 4567, kullaniciBehice = 7890;
using namespace std;

int main()
{
basla:
	char karakter;
	cout << "Kullanici kodlari ve sifreleri. \n";
	cout << "emre & sifre = 1234 \n";
	cout << "volkan & sifre = 4567 \n";
	cout << "behice & sifre = 7890 \n";
	cout << "\n";
	cout << "Kullanici Kodunuz : \n";
	cin >> kullanici;
	cout << "Sifre lutfen  : \n";
	cin >> sifre;
	system("CLS");

	if (kullaniciEmre == kullanici && kullaniciEmreSifre == sifre)
	{
	basla1:
		ifstream dosyaOku("EmreBakiye.txt");
		string satir = "";
		if (dosyaOku.is_open())
		{
			while (getline(dosyaOku, satir))
			{
				string strbakiye = satir;
				int bakiye = stoi(strbakiye);
				if (transfer >> 0 && kisi == 1 && sifre == 1234)
				{
					bakiye = bakiye + transfer;
					cout << "Hesabiniza " << transfer << " TL para geldi.\n";
					Sleep(2000);
					kisi = 0;
					system("CLS");
				}
				cout << "\n";
				cout << "Bakiyeniz: " << bakiye;
				cout << "\n\n";
				cout << "Isleminizi Secin. \n";
				cout << "Para yatirmak icin  :   1\n";
				cout << "Para cekmek icin    :   2\n";
				cout << "Para transferi icin :   3\n";
				cin >> islem;

				if (islem == 1)
				{
					cout << "Yatirmak istediginiz tutar: ";
					cin >> tutar;
					sonuc = bakiye + tutar;
				}
				else if (islem == 2)
				{
					cout << "Cekmek istediginiz tutar: ";
					cin >> tutar;
					if (bakiye >= tutar)
					{
						sonuc = bakiye - tutar;
					}
					else
					{
						cout << "Yetersiz Bakiye. \n";
						goto hata;
					}
				}
				else if (islem == 3)
				{
				kisi1:
					cout << "Gonderilecek kisi :\n";
					cin >> kisi;
					if (kisi == 2 || kisi == 3)
					{
						if (kisi == 3)
						{
							cout << "Islem ucreti = 5 TL\n\n";
						}
						cout << "Transfer etmek istediginiz tutar: \n";
						cin >> transfer;
						if (transfer <= 9)
						{
							cout << "10 TL ve uzeri transfer yapabilirsiniz.\n";
							goto hata;
						}
						if (bakiye >= transfer)
						{
							if (kisi == 2)
								sonuc = bakiye - transfer;
							else if (kisi == 3)
							{
								ucret = transfer + 5;
								if (bakiye >= ucret)
								{
									sonuc = bakiye - transfer - 5;
								}
								else
								{
									transfer = 0;
									cout << "Yetersiz Bakiye. \nIslem ucreti: 5 TL \n\n";
									sonuc = bakiye;
									goto hata;
								}
							}
						}
						else
						{
							cout << "Yetersiz Bakiye. \n";
							transfer = 0;
							goto hata;
						}
					}
					else
					{
						cout << "Yanlis tusladiniz. Tekrar deneyiniz.\n";
						goto kisi1;
					}
				}
				else
				{
					cout << "Yanlis secim. Tekrar deneyiniz. \n\n";
					sonuc = bakiye;
					goto hata;
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
	else if (kullaniciVolkan == kullanici && kullaniciVolkanSifre == sifre)
	{
	basla2:
		ifstream dosyaOku("VolkanBakiye.txt");
		string satir = "";
		if (dosyaOku.is_open())
		{
			while (getline(dosyaOku, satir))
			{
				string strbakiye = satir;
				int bakiye = stoi(strbakiye);
				if (transfer >> 0 && kisi == 2 && sifre == 4567)
				{
					bakiye = bakiye + transfer;
					cout << "Hesabiniza " << transfer << " TL para geldi.\n";
					Sleep(2000);
					kisi = 0;
					system("CLS");
				}
				cout << "\n";
				cout << "Bakiyeniz: " << bakiye;
				cout << "\n\n";
				cout << "Isleminizi Secin. \n";
				cout << "Para yatirmak icin  :   1\n";
				cout << "Para cekmek icin    :   2\n";
				cout << "Para transferi icin :   3\n";
				cin >> islem;
				if (islem == 1)
				{
					cout << "Yatirmak istediginiz tutar: ";
					cin >> tutar;
					sonuc = bakiye + tutar;
				}
				else if (islem == 2)
				{
					cout << "Cekmek istediginiz tutar: ";
					cin >> tutar;
					if (bakiye >= tutar)
					{
						sonuc = bakiye - tutar;
					}
					else
					{
						cout << "Yetersiz Bakiye. \n";
						goto hata;
					}
				}
				else if (islem == 3)
				{
				kisi2:
					cout << "Gonderilecek kisi :\n";
					cin >> kisi;
					if (kisi == 1 || kisi == 3)
					{
						if (kisi == 3)
						{
							cout << "Islem ucreti = 5 TL\n\n";
						}
						cout << "Transfer etmek istediginiz tutar: \n";
						cin >> transfer;
						if (transfer <= 9)
						{
							cout << "10 TL ve uzeri transfer yapabilirsiniz.\n";
							goto hata;
						}
						if (bakiye >= transfer)
						{
							if (kisi == 1)
								sonuc = bakiye - transfer;
							else if (kisi == 3)
							{
								ucret = transfer + 5;
								if (bakiye >= ucret)
								{
									sonuc = bakiye - transfer - 5;
								}
								else
								{
									transfer = 0;
									cout << "Yetersiz Bakiye. \nIslem ucreti: 5 TL \n\n";
									sonuc = bakiye;
									goto hata;
								}
							}
						}
						else
						{
							cout << "Yetersiz Bakiye. \n";
							transfer = 0;
							goto hata;
						}
					}
					else
					{
						cout << "Yanlis tusladiniz. Tekrar deneyiniz.\n";
						goto kisi2;
					}
				}
				else
				{
					cout << "Yanlis secim. Tekrar deneyiniz. \n\n";
					sonuc = bakiye;
					goto hata;
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
	else if (kullaniciBehice == kullanici && kullaniciBehiceSifre == sifre)
	{
	basla3:
		ifstream dosyaOku("BehiceBakiye.txt");
		string satir = "";
		if (dosyaOku.is_open())
		{
			while (getline(dosyaOku, satir))
			{
				string strbakiye = satir;
				int bakiye = stoi(strbakiye);
				if (transfer >> 0 && kisi == 3 && sifre == 7890)
				{
					bakiye = bakiye + transfer;
					cout << "Hesabiniza " << transfer << " TL para geldi.\n";
					Sleep(2000);
					kisi = 0;
					system("CLS");
				}
				cout << "\n";
				cout << "Bakiyeniz: " << bakiye;
				cout << "\n\n";
				cout << "Isleminizi Secin. \n";
				cout << "Para yatirmak icin  :   1\n";
				cout << "Para cekmek icin    :   2\n";
				cout << "Para transferi icin :   3\n";
				cin >> islem;
				if (islem == 1)
				{
					cout << "Yatirmak istediginiz tutar: ";
					cin >> tutar;
					sonuc = bakiye + tutar;
				}
				else if (islem == 2)
				{
					cout << "Cekmek istediginiz tutar: ";
					cin >> tutar;
					if (bakiye >= tutar)
					{
						sonuc = bakiye - tutar;
					}
					else
					{
						cout << "Yetersiz Bakiye. \n";
						goto hata;
					}
				}
				else if (islem == 3)
				{
				kisi3:
					cout << "Gonderilecek kisi :\n";
					cin >> kisi;
					if (kisi == 1 || kisi == 2)
					{
						cout << "Islem ucreti = 5 TL\n\n";
						cout << "Transfer etmek istediginiz tutar: \n";
						cin >> transfer;
						if (transfer <= 9)
						{
							cout << "10 TL ve uzeri transfer yapabilirsiniz.\n";
							goto hata;
						}
						ucret = transfer + 5;
						if (bakiye >= ucret)
							sonuc = bakiye - transfer - 5;
						else
						{
							transfer = 0;
							cout << "Yetersiz Bakiye. \nIslem ucreti: 5 TL \n\n";
							sonuc = bakiye;
							goto hata;
						}
					}
					else
					{
						cout << "Yanlis tusladiniz. Tekrar deneyiniz.\n";
						transfer = 0;
						goto kisi3;
					}
				}
				else
				{
					cout << "Yanlis secim. Tekrar deneyiniz. \n\n";
					sonuc = bakiye;
					goto hata;
				}
				string strsonuc;
				strsonuc = to_string(sonuc);
				ofstream dosyaYaz("BehiceBakiye.txt");
				if (dosyaYaz.is_open())
				{
					dosyaYaz << strsonuc;
					dosyaYaz.close();
				}
				dosyaOku.close();
			}
		}
	}
	else
	{
		cout << "Kullanici kodunuzu ya da sifrenizi yanlis girdiniz.\nLutfen tekrar deneyiniz.\n\n";
		cout << "Ana ekrana yonlendiriliyorsunuz. Lutfen bekleyiniz.\n";
		Sleep(2500);
		system("CLS");
		//user = "0";
		//sifre = 0;
		goto basla;
	}
hata:
	cout << "\nBaska islem yapmak istermisiniz(E/H) : " << endl;
	cin >> karakter;
	if (karakter == 'e' || karakter == 'E')
	{
		cout << endl;
		system("CLS");
		if (kullaniciEmre == kullanici && kullaniciEmreSifre == sifre)
			goto basla1;
		else if (kullaniciVolkan == kullanici && kullaniciVolkanSifre == sifre)
			goto basla2;
		else if (kullaniciBehice == kullanici && kullaniciBehiceSifre == sifre)
			goto basla3;
	}
	else
	{
		cout << "Iyi Gunler Dileriz. \n";
		Sleep(2000);
		system("CLS");
		goto basla;
	}
	return 0;
}