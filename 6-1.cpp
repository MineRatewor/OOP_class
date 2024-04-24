#include<iomanip>
#include<iostream>
using namespace std;

class Exhibit {
protected:
	char* name;
public:
	 Exhibit(const char arr[]) {
		 char* tmp = new char[60] {};
		 for (int i = 0; i < strlen(arr); i++) {
			 tmp[i] = arr[i];
		 }
		 name = tmp;
	}
	
	virtual void print() const {
		cout << "Name:" << setw(3);
		for (int i = 0; i < strlen(name); i++) {
			cout << name[i];
		}
	}
	virtual ~Exhibit() {
		delete[] name;
	}

};



class Coin : public Exhibit {
private:
	double domination;
	int startYear;
	int endYear;
public:
	Coin(const char arr[], double dom, int st, int en):Exhibit(arr) {
		domination = dom;
		startYear = st;
		endYear = en;
	}

	void print() const override {
		cout << "Name:" << setw(5) << name << endl;
		cout << "Domination:" << setw(3) << domination << endl;
		cout << "StartYear:" << setw(5) << startYear << endl;
		cout << "EndYear:" << setw(5) << endYear << endl;
	}

};

class ColdWeapon : public Exhibit {
private:
	int startYear;
	int endYear;
public:
	ColdWeapon(const char arr[], int st, int en) :Exhibit(arr) {
		startYear = st;
		endYear = en;
	}
	void print() const override {
		cout << "Name:" << setw(3) << name << endl;
		cout << "StartYear:" << setw(5) << startYear << endl;
		cout << "EndYear:" << setw(5) << endYear << endl;
	}
};

class Picture : public Exhibit {
private:
	char* subject;
	char* author;
	int year;
public:
	Picture(const char arr[], const char arr1[], const char arr2[], int Year):Exhibit(arr) {
		char* tmp1 = new char[60] {};
		for (int i = 0; i < strlen(arr1); i++) {
			tmp1[i] = arr1[i];
		}
		subject = tmp1;

		char* tmp2 = new char[60] {};
		for (int i = 0; i < strlen(arr2); i++) {
			tmp2[i] = arr2[i];
		}
		author = tmp2;

		year = Year;
	}

	void print() const override  {
		cout << "Name:" << setw(3) << name << endl;
		cout << "Subject:" << setw(3) << subject << endl;
		cout << "Author:" << setw(3) << author << endl;
		cout << "Year:" << setw(3) << year << endl;
	}
};

class Figurines : public Exhibit {
private:
	char* subject;
	char* author;
	int year;
public:
	Figurines(const char arr[], const char arr1[], const char arr2[], int Year) :Exhibit(arr) {
		char* tmp1 = new char[60] {};
		for (int i = 0; i < strlen(arr1); i++) {
			tmp1[i] = arr1[i];
		}
		subject = tmp1;

		char* tmp2 = new char[60] {};
		for (int i = 0; i < strlen(arr2); i++) {
			tmp2[i] = arr2[i];
		}
		author = tmp2;

		year = Year;
	}
	void print() const override {
		cout << "Name:" << setw(3) << name << endl;
		cout << "Subject:" << setw(3) << subject << endl;
		cout << "Author:" << setw(3) << author << endl;
		cout << "Year:" << setw(3) << year << endl;
	}

};
class Photo :public Exhibit {
private:
	char* subject;
	int year;
public:
	Photo(const char arr[], const char arr1[], int Year) :Exhibit(arr) {
		char* tmp1 = new char[60] {};
		for (int i = 0; i < strlen(arr1); i++) {
			tmp1[i] = arr1[i];
		}
		subject = tmp1;
		year = Year;
	}
	void print() const override {
		cout << "Name:" << setw(3) << name << endl;
		cout << "Subject:" << setw(3) << subject << endl;
		cout << "Year:" << setw(3) << year << endl;
	}
};


int main() {
	Coin s("Gold coin", 10, 1231, 1979);
	s.print();
	cout << endl;
	ColdWeapon c("Sword Artur's", 1456, 1789);
	c.print();
	cout << endl;
	Picture d("Monoliza", "women", "human", 1899);
	d.print();
	cout << endl;
	Figurines f("Asd", "Boy", "human", 1754);
	f.print();
	cout << endl;
	Photo g("Friend", "Boy and girl", 1999);
	g.print();
}