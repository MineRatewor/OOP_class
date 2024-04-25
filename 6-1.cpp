#include<iomanip>
#include<iostream>
using namespace std;

class Exhibit {
protected:
	char* name;
public:
	Exhibit() {
		name = nullptr;
	}
	 Exhibit(const char arr[]) {
		 char* tmp = new char[strlen(arr) + 1] {};
		 for (int i = 0; i < strlen(arr); i++) {
			 tmp[i] = arr[i];
		 }
		 name = tmp;
	 }
	 Exhibit(Exhibit& s) {
		char* temp = new char[strlen(s.name) + 1] {};
		 for (int i = 0; i < strlen(s.name); i++) {
			 temp[i] = s.name[i];
		 }
		 delete[] name;
		 name = temp;
		
	 }
     
	virtual Exhibit& operator=(Exhibit& s)  {
		 char* temp = new char[strlen(s.name) + 1] {};
		 for (int i = 0; i < strlen(s.name); i++) {
			 temp[i] = s.name[i];
		 }
		 delete[] name;
		 name = temp;
		
		 return *this;
	 }

     Exhibit(Exhibit&& s) {
	   name = s.name;
	   s.name = nullptr;
      }

    virtual Exhibit& operator=(Exhibit&& s) {
	char* temp = new char[strlen(s.name) + 1] {};
	for (int i = 0; i < strlen(s.name); i++) {
		temp[i] = s.name[i];
	}
	delete[] name;
	name = temp;
	
	s.name = nullptr;
	return *this;
    }
	 
	virtual void print() const {
		if (name == nullptr) {
			cout << "Empty!" << endl;
			return;
		}
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
	Coin() :Exhibit() {}
	Coin(const char arr[], double dom , int st, int en):Exhibit(arr) {
		domination = dom;
		startYear = st;
		endYear = en;
	}
	Coin(Coin& s) :Exhibit(s) {
		domination = s.domination;
		startYear = s.startYear;
		endYear = s.endYear;
	}
	Coin& operator=(Coin& s) {
		Exhibit::operator=(s);
		domination = s.domination;
		startYear = s.startYear;
		endYear = s.endYear;
		return *this;
	}

	Coin(Coin&& s) :Exhibit(move(s)) {
		domination = s.domination;
		startYear = s.startYear;
		endYear = s.endYear;

	
		s.domination = 0;
		s.startYear = 0;
		s.endYear = 0;
	}
	Coin& operator=(Coin&& s) {
		Exhibit::operator=(move(s));
		domination = s.domination;
		startYear = s.startYear;
		endYear = s.endYear;

		
		s.domination = 0;
		s.startYear = 0;
		s.endYear = 0;
		return *this;
	}

	void print() const override  {
		if (name == nullptr) {
			cout << "Empty!" << endl;
			return;
		}
		cout << "Name:" << setw(5) << name << endl;
		cout << "Domination:" << setw(3) << domination << endl;
		cout << "StartYear:" << setw(5) << startYear << endl;
		cout << "EndYear:" << setw(5) << endYear << endl;
	}
	friend ostream& operator <<(ostream& fout, const Coin& s) {
		s.print();
		return fout;
	}

};

class ColdWeapon : public Exhibit {
private:
	int startYear;
	int endYear;
public:
	ColdWeapon() : Exhibit() {}
	ColdWeapon(const char arr[], int st, int en) :Exhibit(arr) {
		startYear = st;
		endYear = en;
	}
	ColdWeapon(ColdWeapon& s) :Exhibit(s) {
		startYear = s.startYear;
		endYear = s.endYear;
	}
	ColdWeapon& operator=(ColdWeapon& s) {
		Exhibit::operator=(s);
		startYear = s.startYear;
		endYear = s.endYear;
		return *this;
	}
	ColdWeapon(ColdWeapon&& s) : Exhibit(move(s)) {
		startYear = s.startYear;
		endYear = s.endYear;

		s.name = nullptr;
		s.startYear = 0;
		s.endYear = 0;
	
		
	}
	ColdWeapon& operator=(ColdWeapon&& s1) {
		Exhibit::operator=(move(s1));

		startYear = s1.startYear;
		endYear = s1.endYear;

		s1.startYear = 0;
		s1.endYear = 0;
		
		return *this;
	}
	void print() const override {
		if (name == nullptr) {
			cout << "Empty!" << endl;
			return;
		}
		cout << "Name:" << setw(3) << name << endl;
		cout << "StartYear:" << setw(5) << startYear << endl;
		cout << "EndYear:" << setw(5) << endYear << endl;
	}
	friend ostream& operator <<(ostream& fout, const ColdWeapon& s) {
		s.print();
		return fout;
	}
};

class Picture : public Exhibit {
private:
	char* subject;
	char* author;
	int year;
public:
	Picture() :Exhibit() {}
	Picture(const char arr[], const char arr1[], const char arr2[], int Year):Exhibit(arr) {
		char* tmp1 = new char[strlen(arr1) + 1] {};
		for (int i = 0; i < strlen(arr1); i++) {
			tmp1[i] = arr1[i];
		}
		subject = tmp1;

		char* tmp2 = new char[strlen(arr2) + 1] {};
		for (int i = 0; i < strlen(arr2); i++) {
			tmp2[i] = arr2[i];
		}
		author = tmp2;

		year = Year;
	}

	Picture(Picture& s) :Exhibit(s) {
		subject = s.subject;
		author = s.author;
		year = s.year;
	}
	Picture& operator=(Picture& s) {
		Exhibit::operator=(s);
		subject = s.subject;
		author = s.author;
		year = s.year;

		return*this;
	}

	Picture(Picture&& s) :Exhibit(move(s)) {
		subject = s.subject;
		author = s.author;
		year = s.year;
		
		
		s.author = nullptr;
		s.subject = nullptr;
		s.year = 0;
	}

	Picture& operator=(Picture&& s) {
		Exhibit::operator=(move(s));
		subject = s.subject;
		author = s.author;
		year = s.year;

		
		s.author = nullptr;
		s.subject = nullptr;
		return *this;
	}
	void print() const override  {
		if (name == nullptr) {
			cout << "Empty!" << endl;
			return;
		}
		cout << "Name:" << setw(3) << name << endl;
		cout << "Subject:" << setw(3) << subject << endl;
		cout << "Author:" << setw(3) << author << endl;
		cout << "Year:" << setw(3) << year << endl;
	}
	friend ostream& operator <<(ostream& fout, const Picture& s) {
		s.print();
		return fout;
	}
	~Picture() {
		subject = nullptr; author = nullptr;
		delete[] subject;
		delete[] author;
	}


};

class Figurines : public Exhibit {
private:
	char* subject;
	char* author;
	int year;
public:
	Figurines():Exhibit(){}
	Figurines(const char arr[], const char arr1[], const char arr2[], int Year) :Exhibit(arr) {
		char* tmp1 = new char[strlen(arr1) + 1] {};
		for (int i = 0; i < strlen(arr1); i++) {
			tmp1[i] = arr1[i];
		}
		subject = tmp1;

		char* tmp2 = new char[strlen(arr2) + 1] {};
		for (int i = 0; i < strlen(arr2); i++) {
			tmp2[i] = arr2[i];
		}
		author = tmp2;

		year = Year;
	}
	Figurines(Figurines& s) :Exhibit(s) {
		subject = s.subject;
		author = s.author;
		year = s.year;
	}
	Figurines& operator=(Figurines& s) {
		Exhibit::operator=(s);
		subject = s.subject;
		author = s.author;
		year = s.year;

		return *this;
	}

	Figurines(Figurines&& s) :Exhibit(move(s)) {
		subject = s.subject;
		author = s.author;
		year = s.year;

		s.subject = nullptr;
		s.author = nullptr;
		
	}
	Figurines& operator=(Figurines&& s) {
		Exhibit::operator=(move(s));

		subject = s.subject;
		author = s.author;
		year = s.year;

		s.subject = nullptr;
		s.author = nullptr;

		return *this;
	}
	void print() const override {
		if (name == nullptr) {
			cout << "Empty!" << endl;
			return;
		}
		cout << "Name:" << setw(3) << name << endl;
		cout << "Subject:" << setw(3) << subject << endl;
		cout << "Author:" << setw(3) << author << endl;
		cout << "Year:" << setw(3) << year << endl;
	}
	
	friend ostream& operator <<(ostream& fout, const Figurines& s) {
		s.print();
		return fout;
	}
	~Figurines(){
		subject = nullptr; author = nullptr;
		delete[] subject;
		delete[] author;
	}

};
class Photo :public Exhibit {
private:
	char* subject;
	int year;
public:
	Photo():Exhibit(){}
	Photo(const char arr[], const char arr1[], int Year) :Exhibit(arr) {
		char* tmp1 = new char[60] {};
		for (int i = 0; i < strlen(arr1); i++) {
			tmp1[i] = arr1[i];
		}
		subject = tmp1;
		year = Year;
	}

	Photo(Photo& s) :Exhibit(s) {
		subject = s.subject;
		year = s.year;
	}

	Photo& operator=(Photo& s) {
		Exhibit::operator=(s);
		subject = s.subject;
		year = s.year;
		return*this;
	}

	Photo(Photo&& s) :Exhibit(move(s)) {
		subject = s.subject;
		year = s.year;

		s.subject = nullptr;
		s.year = 0;
	}

	Photo& operator=(Photo&& s) {
		Exhibit::operator=(move(s));

		subject = s.subject;
		year = s.year;

		s.subject = nullptr;
		s.year = 0;
		return*this;
	}
	void print() const override {
		if (name == nullptr) {
			cout << "Empty!" << endl;
			return;
		}
		cout << "Name:" << setw(3) << name << endl;
		cout << "Subject:" << setw(3) << subject << endl;
		cout << "Year:" << setw(3) << year << endl;
	}
	friend ostream& operator <<(ostream& fout, const Photo& s) {
		s.print();
		return fout;
	}
	~Photo() {
		subject = nullptr;
		delete[] subject;
	}
};


int main() {
	Coin s("Gold coin", 10, 1231, 1979);
	cout << s;
	cout << endl;
	
	ColdWeapon c("Sword Artur's", 1456, 1789);
	cout << c;
	cout << endl;
	

	Picture d("Monoliza", "women", "human", 1899);
	cout << d;
	cout << endl;

	
	Figurines f("Asd", "Boy", "human", 1754);
	cout << f;
	cout << endl;
	

	Photo g("Friend", "Boy and girl", 1999);
	cout << g;
	cout << endl;
	
}