#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

//domeniul ales -> pomicultura PM(Petre Marius)

class Livada
{
	static int nrLivezi;
public:
	const int anPlantatie;
	float suprafata;
	int nrPomi;
	float* productiePomi;

	Livada()
		:anPlantatie(2000)
	{
		this->suprafata = 1000;
		this->nrPomi = 0;
		this->productiePomi = nullptr;
		nrLivezi++;
	}

	Livada(const int anPlantatie, float suprafata)
		:anPlantatie(anPlantatie)
	{
		this->suprafata = suprafata;
		this->nrPomi = 0;
		this->productiePomi = nullptr;
		nrLivezi++;
	}

	Livada(const int anPlantatie,
		float suprafata,
		int nrPomi,
		float* productiePomi)
		:anPlantatie(anPlantatie), suprafata(suprafata), nrPomi(0), productiePomi(nullptr)
	{
		this->suprafata = suprafata;
		this->nrPomi = nrPomi;
		this->productiePomi = new float[nrPomi];
		for (int i = 0; i < nrPomi; i++)
		{
			this->productiePomi[i] = productiePomi[i];
		}
		nrLivezi++;
	}
	
	void afisareLivada()
	{
		cout << "Anul plantatiei:" << anPlantatie << endl << "Suprafata cultivata:" << suprafata << endl << "Numarul de pomi:" << nrPomi << endl << "Productia pomilor{";
		for (int i = 0; i < nrPomi; i++)
		{
			cout << productiePomi[i] << " ";
		}
		cout << "}";
	}
};
 int Livada::nrLivezi = 0;

class Pomicultor
{
	static int nrPomicultori;
public:
	const int nrInregistrare;
	char* denumirePomicultor;
	int varsta;
	bool areUtilaje;

	Pomicultor()
		:nrInregistrare(500)
	{
		this->denumirePomicultor = new char[strlen("Anonim") + 1];
		strcpy(this->denumirePomicultor, "Anonim");
		this->varsta = 0;
		this->areUtilaje = true;
		nrPomicultori++;
    }

	Pomicultor(const int nrInregistrare, const char* denumirePomicultor)
		:nrInregistrare(nrInregistrare)
	{
		this->denumirePomicultor = new char[strlen(denumirePomicultor) + 1];
		strcpy(this->denumirePomicultor, denumirePomicultor);
		this->varsta = 0;
		this->areUtilaje = false;
		nrPomicultori++;
	}

	Pomicultor(const int nrInregistrare,
		const char* denumirePomicultor,
		int varsta,
		bool areUtilaje)
		:nrInregistrare(nrInregistrare)
	{
		this->denumirePomicultor = new char[strlen(denumirePomicultor) + 1];
		strcpy(this->denumirePomicultor, denumirePomicultor);
		this->varsta = varsta;
		this->areUtilaje = areUtilaje;
		nrPomicultori++;
	}

	void afisarePomicultor()
	{
		cout << "Numarul de inregistrare al pomicultorului: " << nrInregistrare << endl << "Numele pomicultorului: " << denumirePomicultor << endl << "Varsta: ";
		cout << varsta << endl << "Foloseste utilaje in livada?(0-nu,1-da): " << areUtilaje << endl;
	}
};
int Pomicultor::nrPomicultori = 0;
class Daunatori
{
	static int nrDaunatori;
public:
	const int anInfestare;
	string denumireDaunator;
	int pomiAfectati;
	double* pagubaProdusa;

	Daunatori()
		:anInfestare(2020)
	{
		this->denumireDaunator = "";
		this->pomiAfectati = 0;
		this->pagubaProdusa = nullptr;
		nrDaunatori++;
	}

	Daunatori(const int anInfestare,
		string denumireDaunator)
		:anInfestare(anInfestare)
	{
		this->denumireDaunator = denumireDaunator;
		this->pomiAfectati = 0;
		this->pagubaProdusa = nullptr;
		nrDaunatori++;
	}

	Daunatori(const int anInfestare,
		string denumireDaunator,
		int pomiAfectati,
		double* pagubaProdusa)
		:anInfestare(anInfestare)
	{
		this->denumireDaunator = denumireDaunator;
		this->pomiAfectati = pomiAfectati;
		this->pagubaProdusa = new double[pomiAfectati];
		for (int i = 0; i < pomiAfectati;i++)
		{
			this->pagubaProdusa[i] = pagubaProdusa[i];
		}
		nrDaunatori++;
	}
	void afisareDaunatori()
	{
		cout << endl;
		cout << "Anul infestarii livezii: " << anInfestare << endl << "Denumirea daunatorului: " << denumireDaunator << endl;
		cout << "Numarul de pomi afectati: " << pomiAfectati << endl << "Paguba pentru fiecare pom: { ";
		for (int i = 0; i < pomiAfectati;i++)
		{
			cout << pagubaProdusa[i] << " ";
		}
		cout << "}";
	}
};
int Daunatori::nrDaunatori = 0;

int main()
{
	Livada livada;
	Livada livada2(2005, 5000);
	Livada livada3(2001, 4500, 4, new float[4] {50, 60, 100, 80});

	livada.afisareLivada();
	livada2.afisareLivada();
	livada3.afisareLivada();

	Pomicultor pomicultor;
	Pomicultor pomicultor2(100, "Ionel");
	Pomicultor pomicultor3(123, "Vasile", 50, false);

	pomicultor.afisarePomicultor();
	pomicultor2.afisarePomicultor();
	pomicultor3.afisarePomicultor();

	Daunatori daunator;
	Daunatori daunator2(2015, "Plosnita");
	Daunatori daunator3(2018, "Vierme", 10, new double[10] {3, 5, 3, 8, 4, 5, 2, 9, 10, 5});

	daunator.afisareDaunatori();
	daunator2.afisareDaunatori();
	daunator3.afisareDaunatori();
};