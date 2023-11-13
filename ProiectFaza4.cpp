#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>

using namespace std;

//domeniul ales -> pomicultura PM(Petre Marius)

class Livada
{
private:
	static int nrLivezi;
	const int anPlantatie;
	float suprafata;
	int nrPomi;
	float* productiePomi;
public:
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
	Livada(int suprafata, int nrPomi, float* productiePomi) :anPlantatie(2000), suprafata(suprafata), nrPomi(nrPomi) {
		this->productiePomi = new float[nrPomi];
		for (int i = 0; i < nrPomi; ++i) {
			this->productiePomi[i] = productiePomi[i];
		}
	}

	Livada(const Livada& l)
		:anPlantatie(l.anPlantatie)
	{
		this->suprafata = l.suprafata;
		this->nrPomi = l.nrPomi;
		this->productiePomi = new float[l.nrPomi];
		for (int i = 0; i < l.nrPomi; i++)
		{
			this->productiePomi[i] = l.productiePomi[i];
		}
		nrLivezi++;
	}

	~Livada()
	{
		if (this->productiePomi != nullptr)
		{
			delete[]this->productiePomi;
		}
		nrLivezi--;
	}

	Livada& operator=(const Livada& l)
	{
		if (this != &l)
		{
			this->suprafata = l.suprafata;
			this->nrPomi = l.nrPomi;
			if (this->productiePomi != nullptr)
			{
				delete[]this->productiePomi;
			}
			this->productiePomi = new float[l.nrPomi];
			for (int i = 0; i < l.nrPomi; i++)
			{
				this->productiePomi[i] = l.productiePomi[i];
			}
		}
		return *this;
	}

	void afisareLivada()
	{
		cout << "Anul plantatiei:" << anPlantatie << endl << "Suprafata cultivata:" << suprafata << endl << "Numarul de pomi:" << nrPomi << endl << "Productia pomilor{";
		for (int i = 0; i < nrPomi; i++)
		{
			cout << productiePomi[i] << " ";
		}
		cout << "}" << endl;
	}

	int getAnPlantatie() const
	{
		return anPlantatie;
	}
	float getSuprafata() const
	{
		return suprafata;
	}
	float* getProductiePomi() const
	{
		return productiePomi;
	}
	float getProductiePom(int index)
	{
		if (index >= 0 && index < this->nrPomi)
		{
			return this->productiePomi[index];
		}
	}
	int getNrLivezi() const
	{
		return Livada::nrLivezi;
	}

	void setSuprafata(float suprafata)
	{
		if (suprafata > 0)
		{
			this->suprafata = suprafata;
		}
	}
	void setNrPomi(int nrPomi)
	{
		if (nrPomi > 0)
		{
			this->nrPomi = nrPomi;
		}
	}
	void setProductiePomi(int nrPomi, float* productiePomi)
	{
		if (nrPomi > 0)
		{
			this->nrPomi = nrPomi;
		}
		if (this->productiePomi != nullptr)
		{
			delete[]this->productiePomi;
		}
		this->productiePomi = new float[nrPomi];
		for (int i = 0; i < nrPomi; i++)
		{
			this->productiePomi[i] = productiePomi[i];
		}
	}

	static void accesareLivezi()
	{
		cout << "Numarul de livezi: " << nrLivezi;
	}

	Livada& operator--()
	{
		float* a = new float[nrPomi - 1];
		for (int i = 0; i < nrPomi - 1; i++)
		{
			a[i] = this->productiePomi[i];
		}
		delete[]this->productiePomi;
		this->productiePomi = a;
		this->nrPomi--;
		return *this;
	}

	bool operator<(const Livada& l) const
	{
		return this->nrPomi < l.nrPomi && this->suprafata < l.suprafata;
	}

	operator float() const
	{
		return this->suprafata;
	}

	friend ostream& operator<<(ostream& out, const Livada& l)
	{
		out << "Anul plantatiei:" << l.anPlantatie << endl << "Suprafata cultivata:" << l.suprafata << endl << "Numarul de pomi:" << l.nrPomi << endl << "Productia pomilor{";
		for (int i = 0; i < l.nrPomi; i++)
		{
			out << l.productiePomi[i] << " ";
		}
		out << "}" << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Livada& l)
	{
		cout << "Introduceti suprafata cultivata: "; in >> l.suprafata;
		cout << "Introduceti numarul de pomi: "; in >> l.nrPomi;
		delete[]l.productiePomi;
		l.productiePomi = new float[l.nrPomi];
		cout << "Introduceti productia pomilor, una cate una: {";
		for (int i = 0; i < l.nrPomi; i++)
		{
			in >> l.productiePomi[i];
			cout << " ";
		}
		cout << "}" << endl;
		return in;
	}
};
int Livada::nrLivezi = 0;

class Pomicultor
{
	static int nrPomicultori;
private:
	const int nrInregistrare;
	char* denumirePomicultor;
	int varsta;
	bool areUtilaje;
public:
	Pomicultor()
		:nrInregistrare(500)
	{
		this->denumirePomicultor = new char[strlen("Anonim") + 1];
		strcpy(this->denumirePomicultor, "Anonim");
		this->varsta = 0;
		this->areUtilaje = true;
		nrPomicultori++;
	}

	Pomicultor( int nrInregistrare, const char* denumirePomicultor)
		:nrInregistrare(nrInregistrare)
	{
		this->denumirePomicultor = new char[strlen(denumirePomicultor) + 1];
		strcpy(this->denumirePomicultor, denumirePomicultor);
		this->varsta = 0;
		this->areUtilaje = false;
		nrPomicultori++;
	}

	Pomicultor( int nrInregistrare,
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

	Pomicultor(const Pomicultor& p)
		:nrInregistrare(p.nrInregistrare)
	{
		this->denumirePomicultor = new char[strlen(p.denumirePomicultor) + 1];
		strcpy(this->denumirePomicultor, p.denumirePomicultor);
		this->varsta = p.varsta;
		this->areUtilaje = p.areUtilaje;
		nrPomicultori++;
	}

	~Pomicultor()
	{
		if (this->denumirePomicultor != nullptr)
		{
			delete[]this->denumirePomicultor;
		}
		nrPomicultori--;
	}

	Pomicultor& operator=(const Pomicultor& p)
	{
		if (this != &p)
		{
			if (this->denumirePomicultor != nullptr)
			{
				delete[]this->denumirePomicultor;
			}
			this->denumirePomicultor = new char[strlen(p.denumirePomicultor) + 1];
			strcpy(this->denumirePomicultor, p.denumirePomicultor);
			this->varsta = p.varsta;
			this->areUtilaje = p.areUtilaje;
		}
		return *this;
	}

	void afisarePomicultor()
	{
		cout << "Numarul de inregistrare al pomicultorului: " << nrInregistrare << endl << "Numele pomicultorului: " << denumirePomicultor << endl << "Varsta: ";
		cout << varsta << endl << "Foloseste utilaje in livada?(0-nu,1-da): " << areUtilaje << endl;
	}

	int getNrInregistrare()const
	{
		return nrInregistrare;
	}
	char* getDenumirePomicultor()const
	{
		return denumirePomicultor;
	}
	int getVarsta() const
	{
		return varsta;
	}
	bool getAreUtilaje() const
	{
		return areUtilaje;
	}

	void setVarsta(int varsta)
	{
		if (varsta > 0)
		{
			this->varsta = varsta;
		}
	}
	void setAreUtilaje(bool areUtilaje)
	{
		this->areUtilaje = areUtilaje;
	}
	//void setDenumirePomicultor(char* denumirePomicultor)
	//{
	//	if (this->denumirePomicultor != nullptr)
	//	{
	//		delete[]this->denumirePomicultor;
	//	}
	//	this->denumirePomicultor = new char[strlen(denumirePomicultor) + 1];
	//	strcpy(this->denumirePomicultor, denumirePomicultor);
	//}

	static void accesarePomicultori()
	{
		cout << "Numarul de pomicultori: " << nrPomicultori;
	}

	Pomicultor operator+(const Pomicultor& p)
	{
		Pomicultor nou(*this);
		delete[]nou.denumirePomicultor;
		nou.denumirePomicultor = new char[strlen(this->denumirePomicultor) + strlen(" + ") + strlen(p.denumirePomicultor) + 1];
		strcpy(nou.denumirePomicultor, this->denumirePomicultor);
		strcat(nou.denumirePomicultor, " + ");
		strcat(nou.denumirePomicultor, p.denumirePomicultor);
		return nou;
	}

	Pomicultor& operator~()
	{
		this->areUtilaje = !this->areUtilaje;
		return *this;
	}
	bool operator==(const Pomicultor& p) const
	{
		return !strcmp(this->denumirePomicultor, p.denumirePomicultor) && this->varsta == p.varsta && this->areUtilaje == p.areUtilaje;
	}

	friend ostream& operator<<(ostream& out, const Pomicultor& p)
	{
		out << "Numarul de inregistrare al pomicultorului: " << p.nrInregistrare << endl << "Numele pomicultorului: " << p.denumirePomicultor << endl << "Varsta: ";
		out << p.varsta << endl << "Foloseste utilaje in livada?(0-nu,1-da): " << p.areUtilaje << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Pomicultor& p)
	{
		char aux[64];
		in.ignore();
		cout << "Introduceti numele pomicultorului: "; in.getline(aux,64);
		delete[]p.denumirePomicultor;
		p.denumirePomicultor = new char[strlen(aux) + 1];
		strcpy(p.denumirePomicultor, aux);
		cout << "Introduceti varsta pomicultorului: "; in >> p.varsta;
		cout << "Precizati daca foloseste utilaje in activitatea sa(0-nu, 1-da): "; in >> p.areUtilaje;
		return in;
	}
};
int Pomicultor::nrPomicultori = 0;

class Daunatori
{
	static int nrDaunatori;
private:
	const int anInfestare;
	string denumireDaunator;
	int pomiAfectati;
	double* pagubaProdusa;
public:
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
		for (int i = 0; i < pomiAfectati; i++)
		{
			this->pagubaProdusa[i] = pagubaProdusa[i];
		}
		nrDaunatori++;
	}

	Daunatori(const Daunatori& d)
		:anInfestare(d.anInfestare)
	{
		this->denumireDaunator = d.denumireDaunator;
		this->pomiAfectati = d.pomiAfectati;
		this->pagubaProdusa = new double[d.pomiAfectati];
		for (int i = 0; i < d.pomiAfectati; i++)
		{
			this->pagubaProdusa[i] = d.pagubaProdusa[i];
		}
		nrDaunatori++;
	}

	~Daunatori()
	{
		if (this->pagubaProdusa != nullptr)
		{
			delete[]this->pagubaProdusa;
		}
	}

	Daunatori& operator=(const Daunatori& d)
	{
		if (this != &d)
		{
			this->denumireDaunator = d.denumireDaunator;
			this->pomiAfectati = d.pomiAfectati;
			if (this->pagubaProdusa != nullptr)
			{
				delete[]this->pagubaProdusa;
			}
			this->pagubaProdusa = new double[d.pomiAfectati];
			for (int i = 0; i < d.pomiAfectati; i++)
			{
				this->pagubaProdusa[i] = d.pagubaProdusa[i];
			}
		}
		return *this;
	}
	void afisareDaunatori()
	{
		cout << endl;
		cout << "Anul infestarii livezii: " << anInfestare << endl << "Denumirea daunatorului: " << denumireDaunator << endl;
		cout << "Numarul de pomi afectati: " << pomiAfectati << endl << "Paguba pentru fiecare pom: { ";
		for (int i = 0; i < pomiAfectati; i++)
		{
			cout << pagubaProdusa[i] << " ";
		}
		cout << "}";
	}

	int getAnInfestare() const
	{
		return anInfestare;
	}
	string getDenumireDaunator() const
	{
		return denumireDaunator;
	}
	int getPomiAfectati() const
	{
		return pomiAfectati;
	}
	double* getPagubaProdusa() const
	{
		return pagubaProdusa;
	}
	double getPagubaPom(int index)
	{
		if (index >= 0 && index < this->pomiAfectati)
		{
			return this->pagubaProdusa[index];
		}
	}

	void setDenumireDaunator(string denumireDaunator)
	{
		if (this->denumireDaunator != "")
		{
			this->denumireDaunator = denumireDaunator;
		}
	}
	void setPomiAfectati(int pomiAfectati)
	{
		if (this->pomiAfectati > 0)
		{
			this->pomiAfectati = pomiAfectati;
		}
	}
	void setPagubaProdusa(int pomiAfectati, double* pagubaProdusa)
	{
		if (pomiAfectati > 0)
		{
			this->pomiAfectati = pomiAfectati;
		}
		if (this->pagubaProdusa != nullptr)
		{
			delete[]this->pagubaProdusa;
		}
		this->pagubaProdusa = new double[pomiAfectati];
		for (int i = 0; i < pomiAfectati; i++)
		{
			this->pagubaProdusa[i] = pagubaProdusa[i];
		}
	}

	static void accesareDaunatori()
	{
		cout << "Numarul daunatorilor: " << nrDaunatori;
	}

	friend ostream& operator<<(ostream& out, const Daunatori& d)
	{
		cout << endl;
		cout << "Anul infestarii livezii: " << d.anInfestare << endl << "Denumirea daunatorului: " << d.denumireDaunator << endl;
		cout << "Numarul de pomi afectati: " << d.pomiAfectati << endl << "Paguba pentru fiecare pom: { ";
		for (int i = 0; i < d.pomiAfectati; i++)
		{
			cout << d.pagubaProdusa[i] << " ";
		}
		cout << "}";
		return out;
	}

	void operator()(double val)
	{
		if (val > 0.0)
		{
			for (int i = 0; i < pomiAfectati; i++)
			{
				this->pagubaProdusa[i] *= val;
			}
		}
		else
		{
			throw new exception("Valoare negativa");
		}
	}

	bool operator!=(const Daunatori& d) const
	{
		if (this->pomiAfectati != d.pomiAfectati)
		{
			return true;
		}
		for (int i = 0; i < this->pomiAfectati; i++)
		{
			if (this->pagubaProdusa[i] != d.pagubaProdusa[i])
			{
				return true;
			}
		}
		return this->denumireDaunator != d.denumireDaunator;
	}

	Daunatori& operator+=(const Daunatori& d)
	{
		double* v = new double[this->pomiAfectati];
		for (int i = 0; i < this->pomiAfectati; i++)
		{
			v[i] = this->pagubaProdusa[i];
		}
		delete[]this->pagubaProdusa;
		this->pagubaProdusa = new double[this->pomiAfectati + d.pomiAfectati];
		for (int i = 0; i < this->pomiAfectati; i++)
		{
			this->pagubaProdusa[i] = v[i];
		}
		for (int i = 0; i < d.pomiAfectati; i++)
		{
			this->pagubaProdusa[i + this->pomiAfectati] = d.pagubaProdusa[i];
		}
		this->pomiAfectati += d.pomiAfectati;
		return *this;
	}

	friend istream& operator>>(istream& in, Daunatori& d)
	{
		cout <<endl<< "Introduceti denumirea daunatorului: "; in >> d.denumireDaunator;
		cout << "Introduceti numarul de pomi afectati: "; in >> d.pomiAfectati;
		delete[]d.pagubaProdusa;
		d.pagubaProdusa = new double[d.pomiAfectati];
		cout << "Introduceti paguba pentru fiecare pom:";
		for (int i = 0; i < d.pomiAfectati; i++)
		{
			in >> d.pagubaProdusa[i];
			cout << " ";
		}
		return in;
	}
};
int Daunatori::nrDaunatori = 0;

void afisareInformatiiLivadaSiPomicultori(Livada& l, Pomicultor& p)
{
	cout << "Informatii despre livada:" << endl;
	l.afisareLivada();

	cout << endl << "Informatii despre pomicultor:" << endl;
	p.afisarePomicultor();
}

double calculeazaSumaPagubei(const Daunatori& d)
{
	double suma = 0.0;
	double* pagubaProdusa = d.getPagubaProdusa();
	int pomiAfectati = d.getPomiAfectati();

	for (int i = 0; i < pomiAfectati; i++) {
		suma += pagubaProdusa[i];
	}
	cout << "Suma pagubei produse se ridica la: ";
	return suma;
}

int main()
{
	Livada livada;
	Livada livada2(2005, 5000);
	Livada livada3(2001, 5500, 4, new float[4] {50, 60, 100, 80});
	Livada livada5(2002, 5000, 3, new float[3] {40, 45, 80});
	Livada livada4(livada3);
	livada5 = livada4;

	livada.afisareLivada();
	livada2.afisareLivada();
	livada3.afisareLivada();
	livada4.afisareLivada();

	cout << endl << endl << livada3.getAnPlantatie() << endl;
	cout << livada3.getProductiePom(3) << endl;
	livada3.setProductiePomi(4, new float[4] {30, 40, 50, 60});
	livada3.afisareLivada();
	cout << endl << endl;
	Livada::accesareLivezi();
	cout << endl << endl;

	(--livada5).afisareLivada();
	if (livada5 < livada3)
	{
		cout << "Livada 5 este mai mica" << endl << endl;
	}
	else
	{
		cout << "Livada 5 este mai mare" << endl << endl;
	}
	cout << (float)livada3 << endl;

	//cin >> livada3;
	//cout << livada3;

	int livezi;
	cout << "Introduceti numarul de livezi: ";
	cin >> livezi;

	vector<Livada>vectorLivezi;
	for (int i = 0; i < livezi; ++i) {
		Livada livada6;
		cout << "Introduceti detaliile pentru livada " << i + 1 << ":\n";
		cin >> livada6;
		vectorLivezi.push_back(livada6);
	}
	cout <<endl<< "Afisare livezi:\n";
	for ( Livada& livada6 : vectorLivezi) {
		livada6.afisareLivada();
		cout << "-----------------\n";
	}
	
	const int liniiLivada=2;
	const int coloaneLivada=2;

	vector<vector<Livada>>matriceLivada(liniiLivada, vector<Livada>(coloaneLivada));
	for (int i = 0; i < liniiLivada; ++i) {
		for (int j = 0; j < coloaneLivada; ++j) {
			int suprafata, nrPomi;
			cout << "Introduceti suprafata pentru livada " << i + 1 << ", pomul " << j + 1 << ": ";
			cin >> suprafata;
			cout << "Introduceti numarul de pomi pentru livada " << i + 1 << ", pomul " << j + 1 << ": ";
			cin >> nrPomi;
			float* productiePomi = new float[nrPomi];
			for (int k = 0; k < nrPomi; ++k) {
				cout << "Introduceti productia pentru pomul " << k + 1 << ": ";
				cin >> productiePomi[k];
			}
			matriceLivada[i][j] = Livada(suprafata, nrPomi, productiePomi);
		}
	}
	for (int i = 0; i < liniiLivada; ++i) {
		for (int j = 0; j < coloaneLivada; ++j) {
			Livada&livada = matriceLivada[i][j];
			cout << "Informații despre livada " << i + 1 << ", pomul " << j + 1 << ":\n";
			livada.afisareLivada();
		}
	}

	Pomicultor pomicultor;
	Pomicultor pomicultor2(100, "Ionel");
	Pomicultor pomicultor3(123, "Vasile", 50, false);
	Pomicultor pomicultor5(999, "Marian", 50, false);
	Pomicultor pomicultor4(pomicultor3);
	pomicultor = pomicultor2;

	pomicultor.afisarePomicultor();
	pomicultor2.afisarePomicultor();
	pomicultor3.afisarePomicultor();
	pomicultor4.afisarePomicultor();

	cout << endl << pomicultor3.getDenumirePomicultor() << endl;
	cout << pomicultor3.getVarsta() << endl;
	cout << pomicultor3.getAreUtilaje() << endl;
	pomicultor3.setVarsta(52);
	pomicultor3.setAreUtilaje(true);
	pomicultor3.afisarePomicultor();
	cout << endl << endl;
	Pomicultor::accesarePomicultori();
	cout << endl << endl;

	(pomicultor2 + pomicultor3).afisarePomicultor();
	cout << pomicultor4 << endl;
	~pomicultor3;
	cout << pomicultor3 << endl;
	if (pomicultor3 == pomicultor5)
	{
		cout << "Pomicultori identici" << endl;
	}
	else
	{
		cout << "Pomicultori diferiti" << endl;
	}

	//cin >> pomicultor4;
	//cout << pomicultor4;
	Pomicultor pomicultor6(1, "Ion", 25, true);
	int pomicultori;
	cout <<endl<< "Introduceti numarul de pomicultori: ";
	cin >> pomicultori;

	vector<Pomicultor>vectorPomicultori;
	for (int i = 0; i < pomicultori; ++i) {
		Pomicultor pomicultor6;
		cout << "Introduceti detaliile pentru pomicultorul " << i + 1 << ":\n";
		cin >> pomicultor6;
		vectorPomicultori.push_back(pomicultor6);
	}
	cout <<endl<< "Afisare pomicultori:\n";
	for (Pomicultor& pomicultor6 : vectorPomicultori) {
		pomicultor6.afisarePomicultor();
		cout << "-----------------\n";
	}

	Daunatori daunator;
	Daunatori daunator2(2015, "Plosnita");
	Daunatori daunator3(2018, "Vierme", 10, new double[10] {3, 5, 3, 8, 4, 5, 2, 9, 10, 5});
	Daunatori daunator4(daunator3);
	daunator3 = daunator3;

	daunator.afisareDaunatori();
	daunator2.afisareDaunatori();
	daunator3.afisareDaunatori();
	daunator4.afisareDaunatori();

	cout << endl << daunator3.getAnInfestare() << endl << daunator3.getDenumireDaunator() << endl << daunator3.getPagubaPom(2) << endl << daunator3.getPomiAfectati() << endl;
	daunator3.setDenumireDaunator("Furnica");
	daunator3.setPagubaProdusa(3, new double[3] {5, 6, 7});
	daunator3.afisareDaunatori();
	cout << endl << endl;
	Daunatori::accesareDaunatori();
	cout << endl << endl;

	afisareInformatiiLivadaSiPomicultori(livada2, pomicultor2);
	cout << calculeazaSumaPagubei(daunator3) << endl;
	daunator3.setPagubaProdusa(10, new double[10] {3, 5, 3, 8, 4, 5, 2, 9, 10, 5});
	cout << calculeazaSumaPagubei(daunator3);

	daunator3(2.0);
	cout << daunator3 << endl;
	if (daunator3 != daunator4)
	{
		cout << "Daunatori diferiti" << endl;
	}
	else
	{
		cout << "Acelasi daunator" << endl;
	}
	daunator3 += daunator4;
	cout << daunator3;
	//cin >> daunator3;
	//cout << daunator3;

	int daunatori;
	cout <<endl<< "Introduceti numarul de daunatori: ";
	cin >> daunatori;

	vector<Daunatori>vectorDaunatori;
	for (int i = 0; i < daunatori; ++i) {
		Daunatori daunator5;
		cout << "Introduceti detaliile pentru daunator " << i + 1 << ":\n";
		cin >> daunator5;
		vectorDaunatori.push_back(daunator5);
	}
	cout << endl << "Afisare daunatori:\n";
	for (Daunatori& daunator5 : vectorDaunatori) {
		daunator5.afisareDaunatori();
		cout <<endl<< "-----------------\n";
	}
};