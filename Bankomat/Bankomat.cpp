#include <iostream>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include<string>

using namespace std;

int blad = 0, wyplata, wplata;
char opcja1, opcja2;
string PIN;
fstream plik;

void stop_and_clear(int s);
void pause_and_clear();
void exit1();
void error();
int p_odczyt();
void p_operacja(long int b);

long int balans = p_odczyt();

int main()
{
	cout << "Witaj w mBanku.";
	stop_and_clear(1000);
	cout << "Dostepne opcje" << endl;
	cout << "1. Bankomat" << endl;
	cout << "2. Wplatomat" << endl;
	cout << "3. Wyjdz" << endl;
	opcja1 = _getch();
	system("cls");
	switch (opcja1)
	{
	case '1':
		cout << "Witamy w bankomacie mBank" << endl;
		cout << "Prosze wprowadzic swoja karte";
		stop_and_clear(3000);
		cout << "Karta wprowadzona" << endl;
		cout << "Prosze podac swoj numer PIN: ";
		cin >> PIN;
		while ((PIN != "1234") && (blad < 2))
		{
			cout << "Wprowadzono nie poprawny PIN." << endl;
			blad++;
			stop_and_clear(1000);
			cout << "Pozostaly " << 3 - blad << " prob." << endl;
			cout << "Prosze ponownie podac swoj numer PIN: ";
			cin >> PIN;
		}
		if ((PIN != "1234") && (blad == 2))
		{
			system("cls");
			cout << "Karta zostala zablokowana. Prosze skontaktowac sie z obsluga banku lub zadzwonic na infolinie mBank." << endl;
			system("PAUSE");
			return 0;
		}
		cout << "Numer PIN zostal wprowadzony poprawnie." << endl;
		stop_and_clear(1000);
		while (1)
		{
			cout << "Dostepne opcje" << endl;
			cout << "1. Wyplata gotowki." << endl;
			cout << "2. Sprawdzenie stanu konta." << endl;
			cout << "3. Wyjdz" << endl;
			opcja2 = _getch();
			switch (opcja2)
			{
			case '1':
				system("cls");
				cout << "Wprowadz kwote ktora chcesz wyplacic: ";
				cin >> wyplata;
				if (wyplata > balans)
				{
					cout << "Nie ma wstarczajaco funduszy." << endl;
					pause_and_clear();
				}
				else
				{
					balans -= wyplata;
					p_operacja(balans);
					cout << "Wyplacono " << wyplata << " zl." << endl;
					cout << "Na koncie pozostalo " << balans << " zl." << endl;
					pause_and_clear();
				}
				break;
			case '2':
				system("cls");
				cout << "Twoj stan konta wynosi: " << balans << " zl." << endl;
				pause_and_clear(); break;
			case '3':
				exit1();
				return 0;
			default:
				error(); break;
			}
		}
		break;

	case '2':
		cout << "Witamy we wplatomacie mBank" << endl;
		cout << "Prosze wprowadzic swoja karte";
		stop_and_clear(3000);
		cout << "Karta wprowadzona" << endl;
		cout << "Prosze podac podac kwote wplaty: ";
		cin >> wplata;
		balans += wplata;
		p_operacja(balans);
		stop_and_clear(2000);
		cout << "Pieniadze zostaly zdeponowane" << endl;
		stop_and_clear(2000);
		exit1();
		return 0; break;
	case '3':
		exit1();
		return 0;
	default:
		error(); break;
	}
}
void stop_and_clear(int s)
{
	Sleep(s);
	system("cls");
}
void pause_and_clear()
{
	system("PAUSE");
	system("cls");
}
void exit1()
{
	system("cls");
	cout << "Dziekuje za skorzystanie z naszych uslug." << endl;
	system("PAUSE");
}
void error()
{
	cout << "Nie ma takiej opcji." << endl;
	stop_and_clear(1500);
}
int p_odczyt()
{
	string linia;
	int b;
	plik.open("srodki.txt", ios::in);
	if (plik.good() == false)
	{
		cout << "Przepraszamy wystapil problem techniczny" << endl;
		exit(0);
	}
	getline(plik, linia);
	plik.close();
	b = atoi(linia.c_str());
	return b;
}
void p_operacja(long int b)
{
	plik.open("srodki.txt", ios::out);
	plik << b;
	plik.close();
}