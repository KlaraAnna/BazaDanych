#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<windows.h>
#include<locale.h>
#include<iomanip>

using namespace std;

int czyakcja = 0;
int r = 0;

struct osoba
{
    string imie;
    string nazwisko;
    string pesel;
    string miasto;
    string zawod;
    int wiek;
    string plec;
};

osoba a;
vector <osoba> v;

void gotoxy(int x, int y)
{
    DWORD STD_OUTPUT_HANDLE;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position;

    position.X = x - 1;
    position.Y = y - 1;

    SetConsoleCursorPosition(hConsole, position);
}

bool sortingByName(osoba A, osoba B)
{
    if (A.imie == B.imie)
    {
        return A.nazwisko < B.nazwisko;
    }
    return A.imie < B.imie;
}
bool sortingBynaz(osoba A, osoba B)
{
    if (A.nazwisko == B.nazwisko)
    {
        return A.imie < B.imie;
    }
    return A.nazwisko < B.nazwisko;
}
bool sortingByMiasto(osoba A, osoba B)
{
    if (A.miasto == B.miasto)
    {
        return A.imie < B.imie;
    }
    return A.miasto < B.miasto;
}
bool sortingByZaw(osoba A, osoba B)
{
    if (A.zawod == B.zawod)
    {
        return A.imie < B.imie;
    }
    return A.zawod < B.zawod;;
}
bool sortingByWiek(osoba A, osoba B)
{
    if (A.wiek == B.wiek)
    {
        return A.imie < B.imie;
    }
    return A.wiek < B.wiek;
}
bool sortingByPlec(osoba A, osoba B)
{
    if (A.plec == B.plec)
    {
        return A.imie < B.imie;
    }
    return A.plec < B.plec;
}
bool sortingByPesel(osoba A, osoba B)
{
    if (A.pesel == B.pesel)
    {
        return A.imie < B.imie;
    }
    return A.pesel < B.pesel;
}


/*
void graphicwzór()
{
    cout << "" << endl;
    gotoxy(37, 3);
    cout << "" << endl;
    gotoxy(37, 4);
    cout << "" << endl;
    gotoxy(37, 5);
    cout << "" << endl;

    gotoxy(4, 7);
    cout << "Aby wybrać opcję wciśnij odpowiednią cyfrę i potwierdź za pomocą klawisza enter." << endl;
    gotoxy(4, 8);
    cout << "" << endl;
    gotoxy(4, 9);
    cout << "" << endl;
    gotoxy(4, 10);
    cout << "" << endl;
    gotoxy(4, 11);
    cout << "" << endl;


    gotoxy(4, 20);
    cout << " ____________________________";
    gotoxy(4, 21);
    cout << "|  ________________________  |";
    gotoxy(4, 22);
    cout << "| |                        | |";
    gotoxy(4, 23);
    cout << "| |                        | |";
    gotoxy(4, 24);
    cout << "| |                        | |"; \
        gotoxy(4, 25);
    cout << "| |                        | |";
    gotoxy(4, 26);
    cout << "| |________________________| |";
    gotoxy(4, 27);
    cout << "|____________________________|";

}
*/

bool czypesel()
{

    int sum;
    if (a.pesel.length() != 11)
    {
        cout << "wpisałeś nieprawidłowy pesel" << endl;
        return 0;
    }

    sum = (1 * (a.pesel[0] - '0')) + (3 * (a.pesel[1] - '0')) + (7 * (a.pesel[2] - '0')) + (9 * (a.pesel[3] - '0')) + (1 * (a.pesel[4] - '0')) + (3 * (a.pesel[5] - '0')) + (7 * (a.pesel[6] - '0')) + (9 * (a.pesel[7] - '0')) + (1 * (a.pesel[8] - '0')) + (3 * (a.pesel[9] - '0'));

    sum %= 10;
    sum = 10 - sum;
    sum %= 10;

    if (sum == (a.pesel[10] - '0'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void czy()
{
    cout << "Jeśli chcesz wrócić do menu wybierz 1, a jeśli chcesz wyjść z programu wybierz 2" << endl;

    int opcja;
    bool a = false;

    do
    {
        cin >> opcja;

        switch (opcja)
        {
        case(1):
        {
            system("CLS");
            czyakcja = 0;
            break;
        }
        case 2:
        {
            cout << "papa" << endl;
            break;
        }
        default:
        {
            cout << "wpisałeś coś źle, spróbuj jeszcze raz" << endl;
            a = true;
            break;
        }
        }
    } while (a == true);
}


void graphicmenu()
{
    system("CLS");

    gotoxy(37, 2);
    cout << " _ __ ___   ___ _ __  _   _" << endl;
    gotoxy(37, 3);
    cout << "| '_ ` _ \\ / _ | '_ \\| | | |" << endl;
    gotoxy(37, 4);
    cout << "| | | | | |  __| | | | |_| |" << endl;
    gotoxy(37, 5);
    cout << "|_| |_| |_|\\___|_| |_|\\__,_|" << endl;
    gotoxy(4, 7);
    cout << "Aby wybrać opcję wciśnij odpowiednią cyfrę i potwierdź za pomocą klawisza enter." << endl;
    gotoxy(4, 8);
    cout << "1. Wypisywanie danych z bazy" << endl;
    gotoxy(4, 9);
    cout << "2. Dodawnanie osoby do bazy" << endl;
    gotoxy(4, 10);
    cout << "3. Usuwanie osoby z bazy" << endl;
    gotoxy(4, 11);
    cout << "4. Edycja danych w bazie" << endl;
    gotoxy(4, 12);
    cout << "5. Sortowanie bazy danych" << endl;
    gotoxy(4, 13);
    cout << "6. Wyszukiwanie w bazie danych" << endl;
    gotoxy(4, 14);
    cout << "7. Statystyki z bazy danych" << endl;
    gotoxy(4, 15);
    cout << "8. Archiwizowanie bazy danych" << endl;
    gotoxy(4, 16);
    cout << "9. Instrukcja programu" << endl;
    gotoxy(4, 17);
    cout << "10. Opcje bazy danych" << endl;
    gotoxy(4, 18);
    cout << "11. Wyjście z programu" << endl;

    gotoxy(38, 8);
    cout << "                          _._";
    gotoxy(38, 9);
    cout << "                        _/:|:";
    gotoxy(38, 10);
    cout << "                       /||||||.";
    gotoxy(38, 11);
    cout << "                       ||||||||.";
    gotoxy(38, 12);
    cout << "                     /|||||||||:";
    gotoxy(38, 13);
    cout << "                     /|||||||||||";
    gotoxy(38, 14);
    cout << "                    .|||||||||||||";
    gotoxy(38, 15);
    cout << "                    | ||||||||||||:";
    gotoxy(38, 16);
    cout << "                  _/| |||||||||||||:_=---.._";
    gotoxy(38, 17);
    cout << "                  | | |||||:'''':||  '~-._  '-.";
    gotoxy(38, 18);
    cout << "                _/| | ||'         '-._   _:    ;";
    gotoxy(38, 19);
    cout << "                | | | '               '~~     _;";
    gotoxy(38, 20);
    cout << "                | '                _.=._    _-~";
    gotoxy(38, 21);
    cout << "             _.~                  {     '-_'";
    gotoxy(38, 22);
    cout << "     _.--=.-~       _.._          {_       }";
    gotoxy(38, 23);
    cout << " _.-~   @-,        {    '-._     _. '~==+  |";
    gotoxy(38, 24);
    cout << "('          }       \_      \_.=~       |  |";
    gotoxy(38, 25);
    cout << "`======='  /_         ~-_    )         <_oo_>";
    gotoxy(38, 26);
    cout << "  `-----~~/ /'===...===' +   /";
    gotoxy(38, 27);
    cout << "         <_oo_>         /  //";
    gotoxy(38, 28);
    cout << "                       /  // ";
    gotoxy(38, 29);
    cout << "                      <_oo_>";

    gotoxy(4, 20);
    cout << " _______________________________";
    gotoxy(4, 21);
    cout << "|  ___________________________  |";
    gotoxy(4, 22);
    cout << "| |                           | |";
    gotoxy(4, 23);
    cout << "| |                           | |";
    gotoxy(4, 24);
    cout << "| |                           | |"; \
        gotoxy(4, 25);
    cout << "| |                           | |";
    gotoxy(4, 26);
    cout << "| |___________________________| |";
    gotoxy(4, 27);
    cout << "|_______________________________|";

    gotoxy(7, 24);
    cout << "Twoja opcja: ";
}
void graphic1()
{
    gotoxy(25, 2);
    cout << "                      _                               _" << endl;
    gotoxy(25, 3);
    cout << "__      ___   _ _ __ (_)___ _   ___      ____ _ _ __ (_) ___" << endl;
    gotoxy(25, 4);
    cout << "\\ \\ /\\ / | | | | '_ \\| / __| | | \\ \\ /\\ / / _` | '_ \\| |/ _ \\" << endl;
    gotoxy(25, 5);
    cout << " \\ V  V /| |_| | |_) | \\__ | |_| |\ V  V | (_| | | | | |  __/" << endl;
    gotoxy(25, 6);
    cout << "  \\_/\\_/  \\__, | .__/|_|___/\\__, | \\_/\\_/ \\__,_|_| |_|_|\\___|";
    gotoxy(25, 7);
    cout << "          |___/|_|          |___/";

    gotoxy(4, 9);
    cout << "Aby wybrać opcję wciśnij odpowiednią cyfrę i potwierdź za pomocą klawisza enter." << endl;
    gotoxy(4, 10);
    cout << "1. wypisywanie z pliku tekstowego" << endl;
    gotoxy(4, 11);
    cout << "2. wypisywanie z wektora" << endl;
    gotoxy(4, 12);
    cout << "3. Wypisz same imiona i nazwiska" << endl;
    gotoxy(4, 13);
    cout << "4. Wypisz same pesele" << endl;

    gotoxy(41, 12);
    cout << "                        . - ~ ~ ~ - .";
    gotoxy(41, 13);
    cout << "      ..     _      .-~               ~-.";
    gotoxy(41, 14);
    cout << "     //|     \ `..~                      `.";
    gotoxy(41, 15);
    cout << "    || |      }  }              /       \\  \\";
    gotoxy(41, 16);
    cout << "(\\   \\\\ \\~^..'                 |         }  \\";
    gotoxy(41, 17);
    cout << " \\`.-~  o      /       }       |        /    \\";
    gotoxy(41, 18);
    cout << " (__          |       /        |       /      `.";
    gotoxy(41, 19);
    cout << "  `- - ~ ~ -._|      /_ - ~ ~ ^|      /- _      `";
    gotoxy(41, 20);
    cout << "              |     /          |     /     ~-.     ~- _";
    gotoxy(41, 21);
    cout << "              |_____|          |_____|         ~ - . _ _~_-_";

    gotoxy(4, 15);
    cout << " _______________________________";
    gotoxy(4, 16);
    cout << "|  ___________________________  |";
    gotoxy(4, 17);
    cout << "| |                           | |";
    gotoxy(4, 18);
    cout << "| |                           | |";
    gotoxy(4, 19);
    cout << "| |                           | |"; \
        gotoxy(4, 20);
    cout << "| |                           | |";
    gotoxy(4, 21);
    cout << "| |___________________________| |";
    gotoxy(4, 22);
    cout << "|_______________________________|";

    gotoxy(7, 19);
    cout << "Twoja opcja: ";
}
void graphic2()
{
    gotoxy(33, 2);
    cout << "     _           _                           _" << endl;
    gotoxy(33, 3);
    cout << "  __| | ___   __| | __ ___      ____ _ _ __ (_) ___" << endl;
    gotoxy(33, 4);
    cout << " / _` |/ _ \\ / _` |/ _` \\ \\ /\\ / / _` | '_ \\| |/ _ \\" << endl;
    gotoxy(33, 5);
    cout << "| (_| | (_) | (_| | (_| |\\ V  V | (_| | | | | |  __/" << endl;
    gotoxy(33, 6);
    cout << " \\__,_|\\___/ \\__,_|\\__,_| \\_/\\_/ \\__,_|_| |_|_|\\___|" << endl;

    gotoxy(36, 12);
    cout << "              .-\"'\"-.";
    gotoxy(36, 13);
    cout << "             |       |  ";
    gotoxy(36, 14);
    cout << "           (`-._____.-')";
    gotoxy(36, 15);
    cout << "        ..  `-._____.-'  ..";
    gotoxy(36, 16);
    cout << "      .', :./'.== ==.`\.: ,`.";
    gotoxy(36, 17);
    cout << "     : (  :   ___ ___   :  ) ;";
    gotoxy(36, 18);
    cout << "     '._.:    |0| |0|    :._.'";
    gotoxy(36, 19);
    cout << "        /     `-'_`-'     \\";
    gotoxy(36, 20);
    cout << "      _.|       / \\       |._";
    gotoxy(36, 21);
    cout << "    .'.-|      (   )      |-.`.";
    gotoxy(36, 22);
    cout << "   //'  |  .-\"`\"`-'\"`\"-.  |  `\\\\ ";
    gotoxy(36, 23);
    cout << "  ||    | `~\":-... -:\"~`  |   ||";
    gotoxy(36, 24);
    cout << "  ||     \.    `---'    ./     ||";
    gotoxy(36, 25);
    cout << "  ||       '-._     _.-'       ||";
    gotoxy(36, 26);
    cout << " /  \\       _/ `~:~` \\_       /  \\";
    gotoxy(36, 27);
    cout << "||||\\)   .-'    / \\    `-.   (/||||";
    gotoxy(36, 28);
    cout << "\\|||    (`.___.')-(`.___.')    |||/";
    gotoxy(36, 29);
    cout << " '\"'     `-----'   `-----'     '\"'";




}

void wyszukiwanie6()
{
    system("CLS");
    int opcja;
    string search;
    int wsearch;
    int czujka = 0;

    cout << "wybierz opcję" << endl;
    cout << "1. wyszukiwanie po imieniu" << endl;
    cout << "2. wyszukiwanie po nazwisku" << endl;
    cout << "3. wyszukiwanie po peselu" << endl;
    cout << "4. wyszukiwanie po mieście" << endl;
    cout << "5. wyszukiwanie po zawodzie" << endl;
    cout << "6. wyszukiwanie po płci" << endl;
    cout << "7. wyszukiwanie po wieku" << endl;

    bool a = false;
    do
    {
        cin >> opcja;

        switch (opcja)
        {
        case 1:
        {
            do
            {
                cout << "wprowadź imie do wyszukania" << endl;
                cin >> search;

                for (int i = 0; i < v.size(); i++)
                {
                    if (search == v[i].imie)
                    {
                        czujka++;
                        cout << v[i].imie << " " << v[i].nazwisko << " " << v[i].pesel << " " << v[i].miasto << " " << v[i].zawod << " " << v[i].wiek << " " << v[i].plec << " " << "numer wersu: " << i + 1 << endl;
                    }
                }
                if (czujka == 0)
                {
                    cout << "takiej osoby nie ma" << endl;
                }
            } while (czujka == 0);
            break;
        }

        case 2:
        {
            do
            {
                cout << "wprowadź nazwisko do wyszukania" << endl;
                cin >> search;

                for (int i = 0; i < v.size(); i++)
                {
                    if (search == v[i].nazwisko)
                    {
                        czujka++;
                        cout << v[i].imie << " " << v[i].nazwisko << " " << v[i].pesel << " " << v[i].miasto << " " << v[i].zawod << " " << v[i].wiek << " " << v[i].plec << " " << "numer wersu: " << i + 1 << endl;
                    }
                }
                if (czujka == 0)
                {
                    cout << "takiej osoby nie ma" << endl;
                }
            } while (czujka == 0);
            break;
        }

        case 3:
        {
            do
            {
                cout << "wprowadź pesel do wyszukania" << endl;
                cin >> search;

                for (int i = 0; i < v.size(); i++)
                {
                    if (search == v[i].pesel)
                    {
                        czujka++;
                        cout << v[i].imie << " " << v[i].nazwisko << " " << v[i].pesel << " " << v[i].miasto << " " << v[i].zawod << " " << v[i].wiek << " " << v[i].plec << " " << "numer wersu: " << i + 1 << endl;
                    }
                }
                if (czujka == 0)
                {
                    cout << "takiej osoby nie ma" << endl;
                }
            } while (czujka == 0);
            break;
        }

        case 4:
        {
            do
            {
                cout << "wprowadź miasto do wyszukania" << endl;
                cin >> search;

                for (int i = 0; i < v.size(); i++)
                {
                    if (search == v[i].miasto)
                    {
                        czujka++;
                        cout << v[i].imie << " " << v[i].nazwisko << " " << v[i].pesel << " " << v[i].miasto << " " << v[i].zawod << " " << v[i].wiek << " " << v[i].plec << " " << "numer wersu: " << i + 1 << endl;
                    }
                }
                if (czujka == 0)
                {
                    cout << "takiej osoby nie ma" << endl;
                }
            } while (czujka == 0);
            break;
        }

        case 5:
        {
            do
            {
                cout << "wprowadź zawód do wyszukania" << endl;
                cin >> search;

                for (int i = 0; i < v.size(); i++)
                {
                    if (search == v[i].zawod)
                    {
                        czujka++;
                        cout << v[i].imie << " " << v[i].nazwisko << " " << v[i].pesel << " " << v[i].miasto << " " << v[i].zawod << " " << v[i].wiek << " " << v[i].plec << " " << "numer wersu: " << i + 1 << endl;
                    }
                }
                if (czujka == 0)
                {
                    cout << "takiej osoby nie ma" << endl;
                }
            } while (czujka == 0);
            break;
        }

        case 6:
        {
            do
            {
                cout << "wprowadź płeć do wyszukania" << endl;
                cin >> search;

                for (int i = 0; i < v.size(); i++)
                {
                    if (search == v[i].plec)
                    {
                        czujka++;
                        cout << v[i].imie << " " << v[i].nazwisko << " " << v[i].pesel << " " << v[i].miasto << " " << v[i].zawod << " " << v[i].wiek << " " << v[i].plec << " " << "numer wersu: " << i + 1 << endl;
                    }
                }
                if (czujka == 0)
                {
                    cout << "takiej osoby nie ma" << endl;
                }
            } while (czujka == 0);
            break;
        }

        case 7:
        {
            do
            {
                int search2;
                cout << "wprowadź wiek do wyszukania" << endl;
                cin >> search2;

                for (int i = 0; i < v.size(); i++)
                {
                    if (search2  == v[i].wiek)
                    {
                        czujka++;
                        cout << v[i].imie << " " << v[i].nazwisko << " " << v[i].pesel << " " << v[i].miasto << " " << v[i].zawod << " " << v[i].wiek << " " << v[i].plec << " " << "numer wersu: " << i + 1 << endl;
                    }
                }
                if (czujka == 0)
                {
                    cout << "takiej osoby nie ma" << endl;
                }
            } while (czujka == 0);
            break;
        }
        default:
        {
            cout << "wpisałeś coś źle, spróbuj jeszcze raz" << endl;
            a = true;
            break;
        }

        }
    } while (a == true);

    if (r == 0)
    {
        czy();
    }
}
void wypisywanie1()
{
    system("CLS");

    graphic1();

    int opcja;
    bool a = false;
    do
    {
        cin >> opcja;

        system("CLS");

        switch (opcja)
        {
        case 1:
        {
            ifstream baza("baza.txt");
            string x;
            while (baza >> x)
            {
                for (int i = 0; i < 4; i++)
                {
                    cout << x << setw(30);
                    baza >> x;
                }
                cout << x << endl;
            }
        }

        break;
        case 2:
        {
            system("CLS");
            for (int k = 0; k < v.size(); k++)
                cout << v[k].imie << setw(30 - v[k].imie.length()) << v[k].nazwisko << setw(20) << v[k].pesel << setw(20) << v[k].miasto << setw(20) << v[k].zawod << setw(15) << v[k].plec << setw(10) << v[k].wiek << endl;

            break;
        }

        default:
            system("CLS");
            graphic1();
            gotoxy(7, 17);
            cout << "Poprzednio wpisałeś coś" << endl;
            gotoxy(7, 18);
            cout << "źle, spróbuj jeszcze raz" << endl;
            gotoxy(7, 19);
            cout << "Twoja opcja: ";

            a = true;
            break;
        case 3:
        {
            system("CLS");
            for (int k = 0; k < v.size(); k++)
                cout << v[k].imie << setw(30 - v[k].imie.length()) << v[k].nazwisko << endl;
            break;
        }
        case 4:
        {
            system("CLS");
            for (int k = 0; k < v.size(); k++)
                cout << v[k].pesel << endl;
            break;
        }
        }
    } while (a == true);

    czy();
}//zrobić odstępy przy wypisywaniu
void dodawanie2()
{
    system("CLS");
    graphic2();
    int opcja;

    gotoxy(5, 8);
    cout << "Za pomocą tej zakładki możesz dodać osobę do naszej bazy danych. Pojawi się ona na końcu naszej listy." << endl;
    gotoxy(4, 9);
    cout << "-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-" << endl;
    gotoxy(4, 11);
    cout << "Podaj imię" << endl;
    gotoxy(4, 12);
    cin >> a.imie;
    gotoxy(4, 14);
    cout << "Podaj nazwisko" << endl;
    gotoxy(4, 15);
    cin >> a.nazwisko;
    do
    {
        gotoxy(4, 17);
        cout << "pesel" << endl;
        gotoxy(1, 18);
        cout << "                                               " << endl;
        gotoxy(4, 18);
        cin >> a.pesel;
    } while (czypesel() == false);

    gotoxy(1, 19);
    cout << "                                          " << endl;
    gotoxy(4, 20);
    cout << "miasto" << endl;
    gotoxy(4, 21);
    cin >> a.miasto;
    gotoxy(4, 23);
    cout << "zawód" << endl;
    gotoxy(4, 24);
    cin >> a.zawod;
    v.push_back(a);


    gotoxy(4, 26);
    cout << "Czy chcesz zapisać dane na stałe?" << endl;
    gotoxy(4, 27);
    cout << "1. tak (zapis w pliku )" << endl;
    gotoxy(4, 28);
    cout << "2. nie (zapis w wektorze)" << endl;
    gotoxy(4, 29);
    cout << "Twoja opcja: ";
    gotoxy(17, 29);
    cin >> opcja;
    bool a = false;

    do
    {
        switch (opcja)
        {
        case 1:
        {
            ofstream baza("baza.txt");
            for (int i = 0; i < v.size(); i++)
            {
                baza << v[i].imie << " " << v[i].nazwisko << " " << v[i].pesel << " " << v[i].miasto << " " << v[i].zawod << endl;

            }
            gotoxy(4, 29);
            cout << "Osoba tych danych została wpisana do bazy na stałe" << endl;
        }
        break;
        case 2:
        {
            gotoxy(4, 29);
            cout << "Osoba tych danych została wpisana do bazy tymczasowo" << endl;
        }
        break;
        default:
            gotoxy(4, 29);
            cout << "wpisałeś coś źle, spróbuj jeszcze raz" << endl;
            a = true;
            break;
        }
    } while (a == true);
    czy();
}
void usuwanie3()
{
    system("CLS");
    int opcja;
    int op;
    int wers;
    bool a = false;
    bool b = false;
    bool bul = false;


    cout << "Wyszukaj linię którą chcesz usunąć. Jeśli nie wiesz w którym wersie jest osoba której dane chcesz usunąć i najpierw chcesz to sprawdzić wybierz '1', jesli od razu chcesz przejść do usuwanie wybierz '2'" << endl;

    do
    {
        cin >> opcja;
        switch (opcja)
        {
        case 1:
        {
            r++;
            wyszukiwanie6(); 
        }
        case 2:
        {
            do
            {
                bul = false;
                cout << "podaj wers" << endl;
                cin >> wers;

                if (wers > v.size())
                {
                    cout << "wpisałeś zły wers" << endl;
                    bul = true;
                }
            } while (bul == true);

            v.erase(v.begin() + wers - 1);

            cout << "czy chcesz zapisać dane w pliku tekstowym?" << endl;
            cout << "1. tak" << endl;
            cout << "2. nie" << endl;

            do
            {
                cin >> op;
                switch (op)
                {
                case 1:
                {
                    fstream baza("baza.txt");
                    for (int i = 0; i < v.size(); i++)
                    {
                        baza << v[i].imie << " " << v[i].nazwisko << " " << v[i].pesel << " " << v[i].miasto << " " << v[i].zawod << endl;

                    }
                    cout << "zmiany zostały zapisane w pliku" << endl;
                    czy();
                    r = 0;
                    break;
                }
                case 2:
                {
                    cout << "dane zostały zapisane jedynie w wektorze" << endl;
                    czy();
                    r = 0;
                    break;
                }
                default:
                {
                    cout << "wpisałeś coś źle, spróbuj jeszcze raz" << endl;
                    b = true;
                    break;
                }

                }
            } while (b == true);

            break;
        }
        default:
        {
            cout << "wpisałeś coś źle, spróbuj jeszcze raz" << endl;
            a = true;
            break;
        }
        }
    } while (a == true);


    cout << "jeśli chcesz sprawdzić czy osoba została usunięta przejdź do wypisywanie bazy danych, lub wyszukiwanie w bazie danych" << endl;
    czy();
}
void edycja4()
{
    system("CLS");
    SYSTEMTIME st;
    GetSystemTime(&st);
    int opcja;
    int op;
    int wers;
    int e2;
    string e1;
    int taknie;
    int pom;
    bool a = false;
    bool b = false;
    bool c = false;
    bool bul = false;     //mój ból jest większy niż Twój bulbul

    cout << "Wyszukaj linię którą chcesz zedytować. Jeśli nie wiesz w którym wersie jest osoba której dane chcesz zedytować i najpierw chcesz to sprawdzić wybierz '1', jesli od razu chcesz przejść do edycji wybierz '2'" << endl;


    do
    {
        cin >> opcja;
        switch (opcja)
        {
        case 1:
        {
            r++;
            wyszukiwanie6();   
        }
        case 2:
        {
            do
            {
                bul = false;
                cout << "podaj wers" << endl;
                cin >> wers;

                if (wers > v.size())
                {
                    cout << "wpisałeś zły wers" << endl;
                    bul = true;
                }
            } while (bul == true);


            cout << "Czy chcesz edytować imie? 1-tak, 2-nie" << endl;

            do
            {
                cin >> taknie;
                switch (taknie)
                {
                case 1:
                {
                    cout << "wprowadź imie" << endl;
                    cin >> e1;
                    v[wers - 1].imie = e1;
                    break;
                }
                case 2:
                {
                    cout << "jeśli tak imie pozostaje niezmienione" << endl;
                    break;
                }
                default:
                {
                    cout << "0wpisałeś coś źle, spróbuj jeszcze raz" << endl;
                    c = true;
                }
                }
            } while (c == true);

            cout << "Czy chcesz edytować nazwisko? 1-tak, 2-nie" << endl;
            c = false;
            do
            {
                taknie = 0;
                cin >> taknie;
                switch (taknie)
                {
                case 1:
                {
                    cout << "wprowadź nazwisko" << endl;
                    cin >> e1;
                    v[wers - 1].nazwisko = e1;
                    break;
                }
                case 2:
                {
                    cout << "jeśli tak nazwisko pozostaje niezmienione" << endl;
                    break;
                }
                default:
                {
                    cout << "wpisałeś coś źle, spróbuj jeszcze raz" << endl;
                    c = true;
                }
                }
            } while (c == true);

            cout << "Czy chcesz edytować pesel? 1-tak, 2-nie" << endl;
            c = false;
            do
            {
                taknie = 0;
                cin >> taknie;
                switch (taknie)
                {
                case 1:
                {
                    do
                    {
                        cout << "wprowadź pesel" << endl;
                        cin >> e1;
                    } while (!czypesel());
                    v[wers - 1].nazwisko = e1;
                    int b;
                    int c = 0;

                    if ((v[wers - 1].pesel[9] - '0') % 2 == 0)
                        v[wers - 1].plec = "kobieta";
                    else
                        v[wers - 1].plec = "mezczyzna";

                    if ((v[wers - 1].pesel[2] - '0') > 1)
                    {
                        b = 2000 + (v[wers - 1].pesel[0] - '0') * 10 + (v[wers - 1].pesel[1] - '0');
                        c = st.wYear - b;
                        v[wers - 1].wiek = c;
                    }
                    else
                    {
                        b = 1900 + (v[wers - 1].pesel[0] - '0') * 10 + (v[wers - 1].pesel[1] - '0');
                        c = st.wYear - b;
                        v[wers - 1].wiek = c;
                    }
                    break;
                }
                case 2:
                {
                    cout << "jeśli tak pesel pozostaje niezmieniony" << endl;
                    break;
                }
                default:
                {
                    cout << "wpisałeś coś źle, spróbuj jeszcze raz" << endl;
                    c = true;
                }
                }


            } while (c == true);

            cout << "Czy chcesz edytować miasto? 1-tak, 2-nie" << endl;
            c = false;
            do
            {
                taknie = 0;
                cin >> taknie;
                switch (taknie)
                {
                case 1:
                {
                    cout << "wprowadź nmiasto" << endl;
                    cin >> e1;
                    v[wers - 1].miasto;
                    break;
                }
                case 2:
                {
                    cout << "jeśli tak miasto pozostaje niezmienione" << endl;
                    break;
                }
                default:
                {
                    cout << "wpisałeś coś źle, spróbuj jeszcze raz" << endl;
                    c = true;
                }
                }
            } while (c == true);

            cout << "Czy chcesz edytować zawód? 1-tak, 2-nie" << endl;
            c = false;
            do
            {
                taknie = 0;
                cin >> taknie;
                switch (taknie)
                {
                case 1:
                {
                    cout << "wprowadź zawód" << endl;
                    cin >> e1;
                    v[wers - 1].zawod = e1;
                    break;
                }
                case 2:
                {
                    cout << "jeśli tak zawód pozostaje niezmienione" << endl;
                    break;
                }
                default:
                {
                    cout << "wpisałeś coś źle, spróbuj jeszcze raz" << endl;
                    c = true;
                }
                }
            } while (c == true);
            cout << "czy chcesz zapisać dane w pliku(1), czy w wektorze?(2)" << endl;
            do
            {
                b = false;
                cin >> op;
                switch (op)
                {
                case 1:
                {
                    fstream baza("baza.txt");
                    for (int i = 0; i < v.size(); i++)
                    {
                        baza << v[i].imie << " " << v[i].nazwisko << " " << v[i].pesel << " " << v[i].miasto << " " << v[i].zawod << endl;

                    }
                    cout << "zmiany zostały zapisane w pliku" << endl;
                    czy();
                    r = 0;
                    break;
                }

                case 2:
                {
                    cout << "dane zostały zapisane jedynie w wektorze" << endl;
                    czy();
                    r = 0;
                    break;
                }
                default:
                {
                    cout << "2wpisałeś coś źle, spróbuj jeszcze raz" << endl;
                    b = true;
                }
                }
            } while (b == false);

        }
        default:
        {
            cout << "1wpisałeś coś źle, spróbuj jeszcze raz" << endl;
            a = true;
            break;
        }

        }
    } while (a == true);
}
void sortowanie5()
{
    system("CLS");
    cout << "1. sortowanie według imienia " << endl;
    cout << "2. sortowanie według nazwiska" << endl;
    cout << "3. sortowanie według miasta" << endl;
    cout << "4. sortowanie według zawodu" << endl;
    cout << "5. sortowanie według wieku" << endl;
    cout << "6. sortowanie według płci" << endl;
    cout << "7. sortowanie według peselu" << endl;

    int opcja;
    int tn;
    bool b = false;
    bool a = false;
    fstream baza("baza.txt");

    do
    {
        cin >> opcja;
        switch (opcja)
        {
        case 1:
        {
            sort(v.begin(), v.end(), sortingByName);
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i].imie << " " << v[i].nazwisko << " " << v[i].pesel << " " << v[i].miasto << " " << v[i].zawod << " " << v[i].wiek << " " << v[i].plec << endl;
            }
        }
        break;
        case 2:
        {
            sort(v.begin(), v.end(), sortingBynaz);
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i].imie << " " << v[i].nazwisko << " " << v[i].pesel << " " << v[i].miasto << " " << v[i].zawod << " " << v[i].wiek << " " << v[i].plec << endl;
            }
        }
        break;
        case 3:
        {
            sort(v.begin(), v.end(), sortingByMiasto);
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i].imie << " " << v[i].nazwisko << " " << v[i].pesel << " " << v[i].miasto << " " << v[i].zawod << " " << v[i].wiek << " " << v[i].plec << endl;
            }
        }
        break;
        case 4:
        {
            sort(v.begin(), v.end(), sortingByZaw);
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i].imie << " " << v[i].nazwisko << " " << v[i].pesel << " " << v[i].miasto << " " << v[i].zawod << " " << v[i].wiek << " " << v[i].plec << endl;
            }
        }
        break;
        case 5:
        {
            sort(v.begin(), v.end(), sortingByWiek);
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i].imie << " " << v[i].nazwisko << " " << v[i].pesel << " " << v[i].miasto << " " << v[i].zawod << " " << v[i].wiek << " " << v[i].plec << endl;
            }
        }
        break;
        case 6:
        {
            sort(v.begin(), v.end(), sortingByPlec);
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i].imie << " " << v[i].nazwisko << " " << v[i].pesel << " " << v[i].miasto << " " << v[i].zawod << " " << v[i].wiek << " " << v[i].plec << endl;
            }
        }
        break;
        case 7:
        {
            sort(v.begin(), v.end(), sortingByPesel);
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i].imie << " " << v[i].nazwisko << " " << v[i].pesel << " " << v[i].miasto << " " << v[i].zawod << " " << v[i].wiek << " " << v[i].plec << endl;
            }
        }
        break;
        default:
            cout << "wpisałeś coś źle, spróbuj jeszcze raz" << endl;
            a = true;
            break;

        }
    } while (a == true);


    do
    {
        b = false;
        cout << "Czy chcesz zapisać zmiany w pliku? 1. nie 2. tak" << endl;
        cin >> tn;
        switch (tn)
        {
        case 1:
        {
            cout << "zmiany są zpaisane jedynie tymczasowo" << endl;
            break;
        }
        case 2:
        {
            for (int i = 0; i < v.size(); i++)
            {
                baza << v[i].imie << " " << v[i].nazwisko << " " << v[i].pesel << " " << v[i].miasto << " " << v[i].zawod << endl;
            }
            cout << "zmiany zostały zapisane w pliku" << endl;
            break;
        }
        default:
        {
            cout << "wpisałeś coś źle, spróbuj jeszcze raz" << endl;
            b = true;
            break;
        }
        }
    } while (b == true);

    czy();
}
void statystyki7()
{
    system("CLS");
    float n = 0;
    int opcja = 0;

    osoba m;
    m.imie = "";
    m.nazwisko = "";
    m.pesel = "";
    m.miasto = "";
    m.zawod = "";
    m.plec = "";
    m.wiek = -1;

    cout << " czy chcesz dodać kryterium imienia? " << endl << "1. tak " << endl << "2. nie" << endl;
    cin >> opcja;
    if (opcja == 1)
    {
        cout << "podaj imie" << endl;
        cin >> m.imie;
    }
    opcja = 0;
    cout << " czy chcesz dodać kryterium nazwiska? " << endl << "1. tak " << endl << "2. nie" << endl;
    cin >> opcja;
    if (opcja == 1)
    {
        cout << "podaj nazwisko" << endl;
        cin >> m.nazwisko;
    }
    opcja = 0;
    cout << " czy chcesz dodać kryterium peselu? " << endl << "1. tak " << endl << "2. nie" << endl;
    cin >> opcja;
    if (opcja == 1)
    {
        cout << "podaj pesel" << endl;
        cin >> m.pesel;
    }
    opcja = 0;
    cout << " czy chcesz dodać kryterium miasta? " << endl << "1. tak " << endl << "2. nie" << endl;
    cin >> opcja;
    if (opcja == 1)
    {
        cout << "podaj miasto" << endl;
        cin >> m.miasto;
    }
    opcja = 0;
    cout << " czy chcesz dodać kryterium zawodu? " << endl << "1. tak " << endl << "2. nie" << endl;
    cin >> opcja;
    if (opcja == 1)
    {
        cout << "podaj zawod" << endl;
        cin >> m.zawod;
    }
    opcja = 0;
    cout << " czy chcesz dodać kryterium wieku? " << endl << "1. tak " << endl << "2. nie" << endl;
    cin >> opcja;
    if (opcja == 1)
    {
        cout << "podaj wiek" << endl;
        cin >> m.wiek;
    }
    opcja = 0;
    cout << " czy chcesz dodać kryterium plci? " << endl << "1. tak " << endl << "2. nie" << endl;
    cin >> opcja;
    if (opcja == 1)
    {
        cout << "podaj plec" << endl;
        cin >> m.plec;
    }
    opcja = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (m.imie == v[i].imie || m.imie == "")
        {
            if (m.nazwisko == v[i].nazwisko || m.nazwisko == "")
            {
                if (m.pesel == v[i].pesel || m.pesel == "")
                {
                    if (m.miasto == v[i].miasto || m.miasto == "")
                    {
                        if (m.zawod == v[i].zawod || m.zawod == "")
                        {
                            if (m.wiek == v[i].wiek || m.wiek == -1)
                            {
                                if (m.plec == v[i].plec || m.plec == "")
                                {
                                    n++;

                                    cout << v[i].imie << " " << v[i].nazwisko << " " << v[i].pesel << " " << v[i].miasto << " " << v[i].zawod << " " << v[i].plec << " " << v[i].wiek << endl;

                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "jest " << n << " osob o tych kryteriach " << endl;
    float x = v.size();
    cout << "jest to " << n / x * 100 << " % całości " << endl;

    czy();
}

void danezplikudov()
{
    int b;
    int c = 0;
    ifstream baza("baza.txt");

    //aktualny czas bo jestesmy na replicie i windowsowe rzeczy nie działają
    SYSTEMTIME st;
    GetSystemTime(&st);

    //koniec

    while (baza >> a.imie)
    {
        baza >> a.nazwisko;
        baza >> a.pesel;
        baza >> a.miasto;
        baza >> a.zawod;

        if ((a.pesel[9] - '0') % 2 == 0)
            a.plec = "kobieta";
        else
            a.plec = "mezczyzna";


        if ((a.pesel[2] - '0') > 1)
        {
            b = 2000 + (a.pesel[0] - '0') * 10 + (a.pesel[1] - '0');
            c = st.wYear - b;
            a.wiek = c;
        }
        else
        {
            b = 1900 + (a.pesel[0] - '0') * 10 + (a.pesel[1] - '0');
            c = st.wYear - b;
            a.wiek = c;
        }

        v.push_back(a);
    }


}
void menu_glowne()
{
    graphicmenu();

    r = 0;
    bool a = false;
    int opcja;
    do
    {
        cin >> opcja;

        switch (opcja)
        {
        case 1:
            wypisywanie1();
            break;
        case 2:
            dodawanie2();
            break;
        case 3:
            usuwanie3();
            break;
        case 4:
            edycja4();
            break;
        case 5:
            sortowanie5();
            break;
        case 6:
            wyszukiwanie6();
            break;
        case 7:
            statystyki7();
            break;
        case 8:
            cout << "88";
            break;
        case 9:
            cout << "99";
            break;
        case 10:
            cout << "1010";
            break;
        case 11:
            cout << "1010";
            break;
        default:

            graphicmenu();
            gotoxy(7, 22);
            cout << "poprzednio wpisałeś coś" << endl;
            gotoxy(7, 23);
            cout << "źle, spróbuj jeszcze raz";
            gotoxy(7, 24);
            cout << "Twoja opcja: ";
            a = true;
            break;
        }
    } while (a == true);

}

int main()
{

    setlocale(LC_ALL, "");
    ifstream baza("baza.txt");
    danezplikudov();

  
    menu_glowne();

    while (czyakcja == 0)
    {
        czyakcja = 1;
        menu_glowne();
    }
}