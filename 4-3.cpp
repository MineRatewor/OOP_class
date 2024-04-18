#include"Header.h"

int main() {
	/*int n;
	cout << "Enter n:" << endl; cin >> n;
	List<int> l;
	for (int i = 0; i < 2*n; i++) {
		int num;
		cout << "Enter element for list:" << endl; cin >> num;
		l.push_back(num);
	}
	int result = 0; int tmp = 2 * n - 1;
	for (int i = 0; i <  n; i++) {
		result += l[i] * l[tmp];
		tmp -= 1;
	}
	cout << "result:" << endl;
	cout << result;*/
	
	List<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	List<int> l(move(l1));
	l.print();
}