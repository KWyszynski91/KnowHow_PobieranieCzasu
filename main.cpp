#include <iostream>
#include <ctime>
#include <map>
#include <vector>

using namespace std;

struct BiezacyCzas
{
    int rok, miesiac=0, dzien=0, godzina=0, minuta=0, sekunda=0;
};

bool czyPrzestepny(int rok)
{
    if((rok % 4 == 0 && rok % 100 != 0 || rok % 400 == 0))
        return true;
    else
        return false;
}

void rozpoznajMiesiac(int numerMiesiaca)
{
    map<int, string> months;
    months[1]="stycze\344";
    months[2]="luty";
    months[3]="marzec";
    months[4]="kwiecie\344";
    months[5]="maj";
    months[6]="czerwiec";
    months[7]="lipiec";
    months[8]="sierpie\344";
    months[9]="wrzesie\344";
    months[10]="pa\253dziernik";
    months[11]="listopad";
    months[12]="grudzie\344";
    string nazwaMiesiaca=months[numerMiesiaca];
    cout<<nazwaMiesiaca;
}

void ktoryToDzienRoku(BiezacyCzas biezacyCzas)
{
    int biezacyMiesiac=biezacyCzas.miesiac;
    int biezacyDzien=biezacyCzas.dzien;
    int biezacyRok=biezacyCzas.rok;
    int dzienRoku=0;
    for(int m=1; m<biezacyMiesiac; m++)
    {
        if((m==4)||(m==6)||(m==9)||(m==11))
        {
            dzienRoku=dzienRoku+30;
        }
        else if((m==2)&&(czyPrzestepny(biezacyRok)==true))
        {
            dzienRoku=dzienRoku+29;
        }
        else if((m==2)&&(czyPrzestepny(biezacyRok)==false))
        {
            dzienRoku=dzienRoku+28;
        }
        else
        {
            dzienRoku=dzienRoku+31;
        }
    }
    dzienRoku=dzienRoku+biezacyDzien;
    cout<<dzienRoku;
}

int ileTenMiesiacMaDni(int miesiac, int rok)
{
    if((miesiac==4)||(miesiac==6)||(miesiac==9)||(miesiac==11))
    {
        return 30;
    }
    else if((miesiac==2)&&(czyPrzestepny(rok)==true))
    {
        return 29;
    }
    else if((miesiac==2)&&(czyPrzestepny(rok)==false))
    {
        return 28;
    }
    else
    {
        return 31;
    }
}

BiezacyCzas wczytajCzasAktualny(vector<BiezacyCzas> &czasAktualny)
{
    BiezacyCzas biezacyCzas;
    time_t now = time(0);
    cout <<"+-------------------------------------------+"<< endl;
    cout << "|Ilo\230\206 sekund od stycznia 1970:: " << now <<" |"<< endl;
    cout <<"+-------------------------------------------+"<<endl<<endl;


    tm *ltm = localtime(&now);

    int rok=(1900 + ltm->tm_year);
    int miesiac=(1 + ltm->tm_mon);
    int dzien=(ltm->tm_mday);
    int godzina=(ltm->tm_hour);
    int minuta=(ltm->tm_min);
    int sekunda=(ltm->tm_sec);
    biezacyCzas.rok=rok;
    biezacyCzas.miesiac=miesiac;
    biezacyCzas.dzien=dzien;
    biezacyCzas.godzina=godzina;
    biezacyCzas.minuta=minuta;
    biezacyCzas.sekunda=sekunda;

    return biezacyCzas;
}

void wyswietlJakiMamyCzas(BiezacyCzas biezacyCzas)
{
    int rok=biezacyCzas.rok;
    int miesiac=biezacyCzas.miesiac;
    int liczbaDni=ileTenMiesiacMaDni(miesiac, rok);
    cout <<"----------------DZI\227-JEST-----------------"<< endl;
    cout << "Dzie\344:      "<< biezacyCzas.dzien << endl;
    cout << "Miesi\245c:    "; rozpoznajMiesiac(miesiac);cout << endl;
    cout << "Rok:        " << rok<<endl;
    cout << "Godzina:    "<< biezacyCzas.godzina << ":";
    cout << biezacyCzas.minuta << ":";
    cout << biezacyCzas.sekunda << endl<<endl;

    cout<<"Jest to: ";
    ktoryToDzienRoku(biezacyCzas);
    cout<<" dzie\344 roku."<<endl;

    if(czyPrzestepny(rok)==true)
        cout<<"Ten rok jest /przest\251pny/"<<endl;
        else
            cout<<"Ten rok jest nieprzest\251pny"<<endl;
        cout<<"Bie\276\245cy miesi\245c ma: "<<liczbaDni<<" dni."<<endl;
    cout <<"------------------------------------------"<< endl;
}

void wyswietlJakiMiesiacBylWczesniej(BiezacyCzas biezacyCzas)
{
    int biezacyMiesiac=biezacyCzas.miesiac;
    int biezacyRok=biezacyCzas.rok;
    int wczesniejszyMiesiac=biezacyMiesiac-1;
    int wczesniejszyRok=biezacyRok;
    int liczbaDniPoprzedniegoMiesiaca=0;
    if(biezacyMiesiac==1)
    {
        wczesniejszyMiesiac=12;
        wczesniejszyRok=biezacyRok-1;
    }
    liczbaDniPoprzedniegoMiesiaca=ileTenMiesiacMaDni(wczesniejszyMiesiac, wczesniejszyRok);

    cout <<"Poprzedni miesi\245c: ";
    rozpoznajMiesiac(wczesniejszyMiesiac);
    cout<<endl;
    if(wczesniejszyMiesiac==12)
        cout<<"Roku: "<<wczesniejszyRok<<endl;
    cout <<"Mia\210 "<<liczbaDniPoprzedniegoMiesiaca<<" dni."<<endl;
    cout <<"------------------------------------------"<< endl;
}

int main()
{
    vector<BiezacyCzas> czasAktualny;
    BiezacyCzas biezacyCzas=wczytajCzasAktualny(czasAktualny);
    czasAktualny.push_back(biezacyCzas);
    wyswietlJakiMamyCzas(biezacyCzas);
    wyswietlJakiMiesiacBylWczesniej(biezacyCzas);
}
