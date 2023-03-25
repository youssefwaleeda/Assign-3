#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
	string name = "N/A"; // person's name, initialized to "N/A" by default
	int ID = 0, age = 0; // person's ID and age, both initialized to 0 by default

public:
	Person() { name = ""; ID = NULL; age = NULL; } // default constructor with empty name, null ID and age

	Person(string n, int id, int a) { name = n; ID = id; age = a; } // constructor with specified name, ID and age

	void setName(string s) { name = s; } // setter for person's name
	void setID(int id) { ID = id; } // setter for person's ID
	void setAge(int a) { age = a; } // setter for person's age

	string getName() { return name; } // getter for person's name
	int getID() { return ID; } // getter for person's ID
	int getAge() { return age; } // getter for person's age

	virtual void printInfo() = 0; // abstract method to print person's information

	struct Appointment {
		int hours = 0; // appointment's hours, initialized to 0 by default
		int mins = 0; // appointment's minutes, initialized to 0 by default
	};
};

class Customer : public Person {
protected:
	int MechanicID = 0; // ID of the mechanic assigned to the customer, initialized to 0 by default
	Appointment appointment; // customer's appointment
	int hrs = 0; // hours of the appointment, initialized to 0 by default
	int mins = 0; // minutes of the appointment, initialized to 0 by default

public:
	Customer() : Person() {} // default constructor

	Customer(int id, string N, int A, int MID) : Person(name, id, age) { // constructor with specified ID, name, age and mechanic ID
		MechanicID = MID;
		// hrs = h; // this line is commented out, seems like a mistake
		// mins = m; // this line is commented out, seems like a mistake
	}

	void setMechanicID(int MID) { MechanicID = MID; } // setter for mechanic ID
	void setApmnt(int h, int m) { appointment.hours = h; appointment.mins = m; } // setter for appointment time

	int getMechanicID() { return MechanicID; } // getter for mechanic ID
	Appointment getApmnt() { return appointment; } // getter for appointment

	// overloaded operators
	bool operator< (const Customer& Cust2) {
		if (appointment.hours != Cust2.appointment.hours) {
			return appointment.hours < Cust2.appointment.hours;
		}
		else
			return appointment.mins < Cust2.appointment.mins;
	}

	bool operator>(const Customer& Cust2) {
		if (appointment.hours != Cust2.appointment.hours) {
			return appointment.hours > Cust2.appointment.hours;
		}
		else
			return appointment.mins > Cust2.appointment.mins;
	}

	bool operator=(const Customer& Cust2) {
		if (appointment.hours != Cust2.appointment.hours) {
			return appointment.hours == Cust2.appointment.hours;
		}
		else
			return appointment.mins == Cust2.appointment.mins;
	}

	// member function
	void printInfo() {
		cout << name << " Has an appointment at: " << appointment.hours << ":" << appointment.mins << " with ";
	}
};

// Derived class Mechanic
class Mechanic : public Person {
protected:
	// attributes
	int count = 0;
	Appointment* _appointments = new Appointment[50]; // assumed that the max num of appointments is 50
	bool availability[24][60];

public:
	// constructors
	Mechanic() {}
	Mechanic(std::string name, int ID, int age) : Person(name, ID, age) {
		for (int i = 0; i < 24; i++) {
			for (int j = 0; j < 60; j++) {
				availability[i][j] = true;
			}
		}
	}

	// function to check if the mechanic is available at the given time
	bool isAvailable(int hrs, int mins) const {
		return availability[hrs][mins];
	}

	//function to set an appointment for the mechanic
	void setAppointment(int hours, int mins) {
		availability[hours][mins] = false;
		count++;
	}

	//function to get the number of appointments for the mechanic
	int numOfAppointments() {
		return count;
	}

	//fmction to print mechanic availability
	void printInfo() {
		cout << "Availability for " << Person::name << ":" << std::endl;

		// iterate over all time slots and print availability status
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
	}
};