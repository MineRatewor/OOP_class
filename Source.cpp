#include<iostream>
#include<iomanip>
using namespace std;

class Text {
private:
	char* arr;
	int s; 
	int c;

public:
	Text();
	Text(int num);
	void new_allocation();
	void add(char);
	void pop(int index);
	void pop_back();
	void join(Text&, Text&);
	void intersection(Text&, Text&);
	int size();
	void difference(Text&);
	void clear();
	void print();
	char& operator[](int index) {
		if (index < 0 or index > s) {
			cout << "Index out of range!";
		}
		return arr[index];
	}
	friend istream& operator >>(istream& fin, Text& arr2) {
		for (int i = 0; i < arr2.s; i++) {
			fin >> arr2.arr[i];
		}
		return fin;
	}
	friend ostream& operator <<(ostream& fout, const Text& arr2) {
		for (int i = 0; i < arr2.s; i++) {
			fout << arr2.arr[i];
		}
		return fout;
	}
	Text(const Text& arr);
	Text& operator=(const Text&);
	Text( Text&& arr);
	Text& operator=( Text&&);
	~Text();
};

Text::Text()
{
	s = c = 0;
}
Text::Text(int num)
{
	s = c = num;
}
void Text::new_allocation()
{
	c = s + 5;
	char* temp = new char[c]();

	for (int i = 0; i < s; i++) {
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
	
}
void Text::add(char str)
{
	if (s == c) {
		new_allocation();
	}

	arr[s] = str;
	s++;
}

void Text::pop(int index)
{
	if (s == 0) {
		cout << "Can't pop, because vector is empty!" << endl;
		return;
	}
	s--;
	char* temp1 = new char[s];
	int k = 0;
	for (int i = 0; i < s; i++) {
		if (index == i) {
			k++;
		}
		temp1[i] = arr[k];
		k++;
	}
	delete[] arr;
	arr = temp1;

}

void Text::pop_back()
{
	if (s == 0) {
		cout << "Can't pop, because vector is empty!" << endl;
		return;
	}
	s--;
}

void Text::join(Text& arr1 ,Text& arr2)
{
	for (int i = 0; i < arr1.s; i++) {
		add(arr1[i]);
	}
	for (int i = 0; i < arr2.s; i++) {
		add(arr2[i]);
	}
}

void Text::intersection(Text& arr1, Text& arr2)
{
	for (int i = 0; i < arr1.s; i++) {
		for (int j = 0; j < arr2.s; j++) {
			if (arr1[i] == arr2[j]) {
				add(arr1[i]);
			}
		}
	}
}

int Text::size()
{
	return s;
}

void Text::difference(Text&arr2)
{
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < arr2.s; j++) {
			if (arr[i] == arr2[j]) {
				pop(i);
				i--;
			}
		}
	}
}

void Text::clear()
{
	s = c = 0;
	delete[] arr;
	arr = nullptr;
}

void Text::print()
{
	for (int i = 0; i < s; i++) {
		cout << setw(3) << arr[i];
	}
	cout << endl;
}

Text::Text(const Text& arr2)
{
	if (this != &arr2) {
		s = arr2.s;
		c = arr2.c;
		char* tmp = new char[s];
		for (int i = 0; i < s; i++) {
			tmp[i] = arr2.arr[i];
		}
		delete[] arr;
		arr = tmp;

		
	}
	
}

Text& Text::operator=(const Text& arr2)
{
	if (this != &arr2) {
		s = arr2.s;
		c = arr2.c;
		char* tmp = new char[s];
		for (int i = 0; i < s; i++) {
			tmp[i] = arr2.arr[i];
		}
		delete[] arr;
		arr = tmp;


	}
	return *this;
}

Text::Text(Text&& arr2)
{
	
		s = arr2.s;
		c = arr2.c;
		char* tmp = new char[s];
		for (int i = 0; i < s; i++) {
			tmp[i] = arr2.arr[i];
		}
		delete[] arr;
		arr = tmp;

		arr2.s = 0;
		arr2.c = 0;
	
}

Text& Text::operator=( Text&& arr2)
{
	if (this != &arr2) {
		s = arr2.s;
		c = arr2.c;
		char* tmp = new char[s];
		for (int i = 0; i < s; i++) {
			tmp[i] = arr2.arr[i];
		}
		delete[] arr;
		arr = tmp;
		arr2.s = 0;
		arr2.c = 0;

	}
	return *this;
}
Text::~Text()
{
	delete[]arr;
}
int main() {
	setlocale(LC_CTYPE, ".1251");
	Text s1;
	s1.add('à');
	s1.add('û');
	s1.add('ÿ');
	Text s2;
	s2.add('ô');
	s2.add('à');
	s2.add('ë');
	s1.difference(s2);
	s1.print();
	
}


