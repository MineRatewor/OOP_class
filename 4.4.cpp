#include"Header.h"

int main() {
	setlocale(LC_CTYPE, ".1251");
	Text s1;
	s1 += '�';
	s1 += '�';
	s1 += '�';
	
	s1.print();
	
}


