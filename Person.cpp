#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
	string name = "N/A";
	int ID = 0, age = 0;

public:
	Person() { name = ""; ID = NULL; age = NULL; }

	Person(string n, int id, int a) { name = n; ID = id; age = a; }

	void setName(string s) { name = s; }
	void setID(int id) { ID = id; }
	void setAge(int a) { age = a; }

	string getName() { return name; }
	int getID() { return ID; }
	int getAge() { return age; }

	virtual void printInfo() = 0;

	struct Appointment {
		int hours = 0;
		int mins = 0;
	};

};


class Customer : public Person {
protected:
	int MechanicID = 0;
	Appointment appointment;
	int hrs = 0;
	int mins = 0;

public:
	Customer() : Person() {}

	Customer(int id, string N, int A, int MID) : Person(name, id, age) {
		MechanicID = MID;
		/*hrs = h;
		mins = m;*/
	}

	void setMechanicID(int MID) { MechanicID = MID; }
	void setApmnt(int h, int m) { appointment.hours = h; appointment.mins = m; }

	int getMechanicID() { return MechanicID; }
	Appointment getApmnt() { return appointment; }

	//overloaded functions
	bool operator< (const Customer& Cust2) { // i found an example online that can let me do this not sure if this is considered overlaoding or not
		if (appointment.hours != Cust2.appointment.hours) {
			return appointment.hours < Cust2.appointment.hours;
		}
		else
			return appointment.mins < Cust2.appointment.mins;

	}

	bool operator>(const Customer& Cust2) { // not sure if overloading or not 
		if (appointment.hours != Cust2.appointment.hours) {
			return appointment.hours > Cust2.appointment.hours;
		}
		else
			return appointment.mins > Cust2.appointment.mins;

	}

	bool operator=(const Customer& Cust2) { // same here
		if (appointment.hours != Cust2.appointment.hours) {
			return appointment.hours == Cust2.appointment.hours;
		}
		else
			return appointment.mins == Cust2.appointment.mins;
	}

	void printInfo() {
		cout << name << " Has an appointment at: " << appointment.hours << ":" << appointment.mins << " with ";
	}
};


class Mechanic : public Person {
protected:
	int count = 0; // counter to count tht number of appointments
	Appointment* _appointments = new Appointment[50]; // assumed that the max num of appointments is 50
	bool availability[24][60];

public:
	Mechanic() {}
	Mechanic(std::string name, int ID, int age) : Person(name, ID, age) {
		for (int i = 0; i < 24; i++) {
			for (int j = 0; j < 60; j++) {
				availability[i][j] = true;
			}
		}
	}

	bool isAvailable(int hrs, int mins) const {
		return availability[hrs][mins];
	}

	void setAppointment(int hours, int mins) {
		availability[hours][mins] = false;
		count++;
	}

	int numOfAppointments() { return count; }

	void printInfo() {
		cout << "Availability for " << Person::name << ":" << std::endl;
		
		for (int i = 0; i < 24; i++) {
			for (int j = 0; j < 60; j++) {
				if (availability[i][j]) {
					cout << i << ":" << j << " - Available" << endl;
				}
				else {
					cout << i << ":" << j << " - Booked" << endl;
				}
			}
		}
	} //only way i could do it
	  // i couldnt find a way to link the customer and the mechanic unless i could pass it to the function

};