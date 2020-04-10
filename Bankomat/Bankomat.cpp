#include <iostream>
#include <Windows.h>
#include <fstream>

using namespace std;

int opcja1, opcja2, blad = 0, balans = 1000, wyplata, wplata;
string PIN;
fstream plik;

void stop_and_clear(int s);
void pause_and_clear();
void exit();
void error();

int main()
{
	cout << "Witaj w mBanku.";
	stop_and_clear(1000);
	cout << "Dostepne opcje" << endl;
	cout << "1. Bankomat" << endl;
	cout << "2. Wplatomat" << endl;
	cout << "3. Wyjdz" << endl;
	cout << "Wybieram: ";
	cin >> opcja1;
	system("cls");
	switch (opcja1)
	{
	case 1:
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
			cout << "Wybieram: ";
			cin >> opcja2;
			switch (opcja2)
			{
			case 1:
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
					cout << "Wyplacono " << wyplata << " zl." << endl;
					cout << "Na koncie pozostalo " << balans << " zl." << endl;
					pause_and_clear();
				}
				break;
			case 2:
				system("cls");
				cout << "Twoj stan konta wynosi: " << balans << " zl." << endl;
				pause_and_clear(); break;
			case 3:
				exit();
				return 0;
			default:
				error(); break;
			}
		}
		break;

	case 2:
		cout << "Witamy we wplatomacie mBank" << endl;
		cout << "Prosze wprowadzic swoja karte";
		stop_and_clear(3000);
		cout << "Karta wprowadzona" << endl;
		cout << "Prosze podac podac kwote wplaty: ";
		cin >> wplata;
		balans += wplata;
		stop_and_clear(2000);
		cout << "Pieniadze zostaly zdeponowane" << endl;
		stop_and_clear(2000);
		exit();
		return 0;
		break;
	case 3:
		exit();
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
void exit()
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