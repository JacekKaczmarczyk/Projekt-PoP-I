//POP_2019_12_09_projekt_1_Kaczmarczyk_Jacek_EIT_1_179922
//Microsoft Visual Studio 2019 Microsoft (R) Kompilator optymalizujący C/C++, wersja 19.24.28314 dla architektury x86
#include<cstdlib>
#include<ctime>
#include<iostream>
const int MAX_N = 5;
const int MAX_L = 6;
const int MAX_L_2 = 5;
using namespace std;

void losujGracza(char labirynt[14][25],char pr,char gracz,int &X,int &Y)
{
	int n,i;
	bool k = true;
	while(k)
	{
		n = 2 + rand() % 10;
		i = 2 + rand() % 20;
		if(labirynt[n][i]==pr)
		{
			labirynt[n][i] = gracz;
			k = false;
		}
		
	}
	X = i;
	Y = n;
}
void losujSkarby(char labirynt[14][25],char pr,char skarb,int c)
{
	int n, i, l;
	bool k = true;
	for (l = 0; l < c; l++) 
	{
		while (k)
		{
			n = 2 + rand() % 10;
			i = 2 + rand() % 20;
			if (labirynt[n][i] == pr)
			{
				labirynt[n][i] = skarb;
				k = false;
			}
		}
		k = true;
	}
}
void losujfragment(char seg1 [MAX_N][MAX_L], char segA[MAX_N][MAX_L], char segB[MAX_N][MAX_L], char segC[MAX_N][MAX_L], char segD[MAX_N][MAX_L], char segE[MAX_N][MAX_L], char segF[MAX_N][MAX_L],int rozmiarTablicy )
{
	int liczba = rand() % 6;
	switch (liczba)
	{
	case 0: memcpy(seg1, segA, rozmiarTablicy);
		break;
	case 1: memcpy(seg1, segB, rozmiarTablicy);
		break;
	case 2: memcpy(seg1, segC, rozmiarTablicy);
		break;
	case 3: memcpy(seg1, segD, rozmiarTablicy);
		break;
	case 4: memcpy(seg1, segE, rozmiarTablicy);
		break;
	case 5: memcpy(seg1, segF, rozmiarTablicy);
		break;
	}
}
void piszLabirynt (char labirynt[14][25])
{
	int i, n;
	for (n = 0; n < 14; n++)
	{
		for (i = 0; i < 24; i++)
		{
			cout << labirynt[n][i];
		}
		cout << endl;
	}
}
void generujLabirynt (char seg1[MAX_N][MAX_L], char seg2[MAX_N][MAX_L], char seg3[MAX_N][MAX_L], char seg4[MAX_N][MAX_L], char seg5[MAX_N][MAX_L], char seg6[MAX_N][MAX_L], char seg7[MAX_N][MAX_L], char seg8[MAX_N][MAX_L], char labirynt[14][25], char gr)

{
	int i, n;
	for(n=0;n<2;n++)
	{
		for (i = 0; i < 24; i++) 
		{
			labirynt[n][i] = gr;
		}
		
	}
	for (n = 2; n < 12; n++)
	{
		for (i = 0; i < 2; i++)
		{
			labirynt[n][i] = gr;
		}

	}
	for (n = 2; n < 12; n++)
	{
		for (i = 22; i < 24; i++)
		{
			labirynt[n][i] = gr;
		}

	}
	for (n = 12; n < 14; n++)
	{
		for (i = 0; i < 24; i++)
		{
			labirynt[n][i] = gr;
		}

	}
	for (n = 2; n < 7; n++)
	{
		for (i = 2; i < 7; i++)
		{
			labirynt[n][i] = seg1[n-2][i-2];
		}
	}
	for (n = 2; n < 7; n++)
	{
		for (i = 7; i < 12; i++)
		{
			labirynt[n][i] = seg2[n-2][i-7];
		}
	}
	for (n = 2; n < 7; n++)
	{
		for (i = 12; i < 17; i++)
		{
			labirynt[n][i] = seg3[n-2][i - 12];
		}
	}
	for (n = 2; n < 7; n++)
	{
		for (i = 17; i < 22; i++)
		{
			labirynt[n][i] = seg4[n-2][i - 17];
		}
	}
	for (n = 7; n < 12; n++)
	{
		for (i = 2; i < 7; i++)
		{
			labirynt[n][i] = seg5[n-7][i-2];
		}
	}
	for (n = 7; n < 12; n++)
	{
		for (i = 7; i < 12; i++)
		{
			labirynt[n][i] = seg6[n - 7][i-7];
		}
	}
	for (n = 7; n < 12; n++)
	{
		for (i = 12; i < 17; i++)
		{
			labirynt[n][i] = seg7[n - 7][i - 12];
		}
	}
	for (n = 7; n < 12; n++)
	{
		for (i = 17; i < 22; i++)
		{
			labirynt[n][i] = seg7[n - 7][i - 17];
		}
	}
}
void ruchwGore (char labirynt[14][25],int& X,int& Y,char pr,char gracz,char skarb)
{
	if (labirynt[Y + 1][X] == pr or labirynt[Y + 1][X] == skarb)
	{
		labirynt[Y][X] = pr;
		labirynt[Y + 1][X] = gracz;
		Y = Y + 1;
	}
	else
	{
		cout << "Niedozwolony ruch!" << endl;
		system("pause");
	}
}
void ruchwDol (char labirynt[14][25], int& X, int& Y, char pr, char gracz,char skarb)
{
	if (labirynt[Y -1][X] == pr or labirynt[Y-1][X] == skarb)
	{
		labirynt[Y][X] = pr;
		labirynt[Y - 1][X] = gracz;
		Y = Y - 1;
	}
	else
	{
		cout << "Niedozwolony ruch!" << endl;
		system("pause");
	}
}
void ruchwLewo (char labirynt[14][25], int& X, int& Y, char pr, char gracz, char skarb)
{
	if (labirynt[Y][X-1] == pr or labirynt[Y][X - 1] == skarb)
	{
		labirynt[Y][X] = pr;
		labirynt[Y][X-1] = gracz;
		X = X - 1;
	}
	else
	{
		cout << "Niedozwolony ruch!" << endl;
		system("pause");
	}
}
void ruchwPrawo (char labirynt[14][25], int& X, int& Y, char pr, char gracz, char skarb)
{
	if (labirynt[Y][X+1] == pr or labirynt[Y][X + 1] == skarb)
	{
		labirynt[Y][X] = pr;
		labirynt[Y][X+1] = gracz;
		X = X + 1;
	}
	else
	{
		cout << "Niedozwolony ruch!" << endl;
		system("pause");
	}
}
void piszOgrLabirynt(char labirynt[14][25], int X, int Y, char pr)
{
	int i, n;
	for (n = 0; n < 14; n++)
	{
		for (i = 0; i < 24; i++)
		{
			if (n >= Y - 2 and n <= Y + 2 and i >= X - 2 and i <= X + 2)
				cout << labirynt[n][i];
			else
				cout << pr;
		}
		cout << endl;
	}
}
int main()
{
	
	srand(time(NULL));
	bool rysCalyLab = false;		
	bool zakonczGre = false;
	int rozmiarTablicySeg;
	int pozX = 0;
	int pozY = 0;
	int i, n;
	int liczbaSkarbow = 5;
	int BUF;
	char sc = char(219);
	char pr = char(32);			
	char gr = char(178);
	char gracz = char(248);
	unsigned char wej;
	char skarb = '$';
	char segA[MAX_N][MAX_L] =
	{
			{sc,sc,pr,sc,sc},
			{sc,pr,pr,sc,sc},
			{pr,pr,sc,pr,pr},
			{sc,pr,pr,pr,sc},
			{sc,sc,pr,sc,sc}
	};
	char segB[MAX_N][MAX_L] =
	{
			{sc,sc,pr,pr,sc},
			{pr,sc,sc,pr,sc},
			{pr,pr,pr,pr,pr},
			{sc,pr,sc,pr,sc},
			{sc,sc,pr,pr,sc}
	};
	char segC[MAX_N][MAX_L] =
	{
			{pr,pr,pr,pr,pr},
			{pr,pr,sc,pr,pr},
			{pr,pr,sc,sc,pr},
			{sc,pr,sc,sc,sc},
			{sc,pr,pr,pr,pr}
	};
	char segD[MAX_N][MAX_L] =
	{
			{sc,sc,pr,pr,pr},
			{sc,pr,pr,sc,pr},
			{pr,pr,sc,pr,pr},
			{pr,sc,pr,pr,sc},
			{sc,pr,pr,sc,sc}
	};
	char segE[MAX_N][MAX_L] =
	{
			{pr,pr,pr,sc,sc},
			{sc,pr,pr,pr,sc},
			{pr,pr,sc,pr,pr},
			{pr,pr,sc,pr,pr},
			{pr,pr,pr,pr,sc}
	};
	char segF[MAX_N][MAX_L] =
	{
			{sc,sc,pr,sc,sc},
			{sc,sc,pr,sc,sc},
			{pr,pr,pr,pr,pr},
			{sc,sc,pr,sc,sc},
			{sc,sc,pr,sc,sc}
	};
	rozmiarTablicySeg=sizeof(segA);
	char seg1[MAX_N][MAX_L];
	char seg2[MAX_N][MAX_L];
	char seg3[MAX_N][MAX_L];
	char seg4[MAX_N][MAX_L];
	char seg5[MAX_N][MAX_L];
	char seg6[MAX_N][MAX_L];
	char seg7[MAX_N][MAX_L];
	char seg8[MAX_N][MAX_L];
	char labirynt[14][25];

	losujfragment	(seg1, segA, segB, segC, segD, segE, segF, rozmiarTablicySeg);
	losujfragment	(seg2, segA, segB, segC, segD, segE, segF, rozmiarTablicySeg);
	losujfragment	(seg3, segA, segB, segC, segD, segE, segF, rozmiarTablicySeg);
	losujfragment	(seg4, segA, segB, segC, segD, segE, segF, rozmiarTablicySeg);
	losujfragment	(seg5, segA, segB, segC, segD, segE, segF, rozmiarTablicySeg);
	losujfragment	(seg6, segA, segB, segC, segD, segE, segF, rozmiarTablicySeg);
	losujfragment	(seg7, segA, segB, segC, segD, segE, segF, rozmiarTablicySeg);
	losujfragment	(seg8, segA, segB, segC, segD, segE, segF, rozmiarTablicySeg);
	
	generujLabirynt(seg1, seg2, seg3, seg4, seg5, seg6, seg7, seg8, labirynt, gr);
	losujGracza(labirynt, pr, gracz, pozX, pozY);
	losujSkarby(labirynt, pr, skarb, liczbaSkarbow);
	
	do
	{	
		system("cls");
		cout << endl << "Sterowanie za pomoca W,S,A,D" << endl << "Wprowadz L, aby wyjsc. Aby oszukac wprowadz P" << endl << "Wprowadz F aby dodac skarb" << endl;
		if(rysCalyLab==false)
		{
			piszOgrLabirynt(labirynt, pozX, pozY, pr);
		}
		else
		{
			piszLabirynt(labirynt);
		}
		cout << endl;
		cin>>wej;
		BUF = wej;
		switch(BUF)
		{
		case 102:;
		case 70:	losujSkarby	(labirynt, pr, skarb, 1);
			break;
		case 83:;
		case 115:	ruchwGore	(labirynt, pozX, pozY, pr, gracz, skarb);
			break;
		case 87:;
		case 119:	ruchwDol	(labirynt, pozX, pozY, pr, gracz, skarb);
			break;
		case 65:;
		case 97:	ruchwLewo	(labirynt, pozX, pozY, pr, gracz, skarb);
			break;
		case 68:;
		case 100:	ruchwPrawo	(labirynt, pozX, pozY, pr, gracz, skarb);
			break;
		case 80:;
		case 112:	rysCalyLab=!rysCalyLab;
			break;
		case 76:;
		case 108:	return(0);
			break;
		default:cout<<"Nieprawidlowy przycisk!";
				system("pause");
			break;	
		}
		zakonczGre = true;
		for (n = 0; n < 14; n++)
		{
			for (i = 0; i < 24; i++)
			{
				if(labirynt[n][i]==skarb)
					zakonczGre = false;
			}
		}
	} while (!zakonczGre);
	system("cls");
	piszLabirynt(labirynt);
	return(0);
}

