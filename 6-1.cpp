#include"Coin.h"
#include"ColdWeapon.h"
#include"Exhibit.h"
#include"Figurines.h"
#include"Photo.h"
#include"Picture.h"
#include"Array.h"

int main() {
	Coin s("Gold coin", 10, 1231, 1979);

	cout << s << endl;
	ColdWeapon c("Sword Artur's", 1456, 1789);
	
	cout << c << endl;
	Picture d("Monoliza", "women", "human", 1899);
	 
	cout << d << endl;
	Figurines f("Asd", "Boy", "human", 1754);

	cout << f << endl;
	Photo g("Friend", "Boy and girl", 1999);

	cout << g << endl;

	cout << endl << "//////////" << endl;
	Array mass;
	mass.push_back(s);
	mass.push_back(c);
	mass.push_back(d);
	mass.push_back(f);
	mass.push_back(g);
	
	mass.print();
	
}