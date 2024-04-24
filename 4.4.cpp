#include"Header.h"

int main() {
	setlocale(LC_CTYPE, ".1251");
	Text s1;
	s1 += 'ÿ';
	s1 += 'á';
	s1 += 'ê';
	
	s1.print();
	
}


