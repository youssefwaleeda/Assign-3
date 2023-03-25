#include <iostream>
#include "Person.cpp"
#include "Mechanic.cpp"
using namespace std;


int main() {
	int M;
	static int hrs;
	static int mins;

	Mechanic Ayman("Ayman", 63, 21);

	cout << "What hour does " << Ayman.getName() << "'s appointment start ? ";
	cin >> hrs;
	cout << "What hour does " << Ayman.getName() << "'s the appointment start? ";
	cin >> mins;

	const int duration = 30; // I assumed that each appointment takes 30mins
	
	cout << endl;

	if (Ayman.isAvailable(hrs, mins) == 0)
		cout << Ayman.getName() << " is Booked from " << hrs << ":" << mins << " till " << (30 + hrs) << ":" << (30 + mins) << endl;
	else
		for (int i = 0; i <= 30; i++) {
			Ayman.setAppointment((hrs), (mins + i));
		}
	cout << endl;

	Customer Ahmed;
	Ahmed.printInfo();
	Ayman.getName();

	cout << endl;

	Ayman.printInfo();

	system("pause>0");
}