#include <iostream>
#include "Person.cpp"
#include "Mechanic.cpp"
using namespace std;


int main() {
    int M;
    static int hrs; // declaring starting hour as a static variable
    static int mins; // declaring starting minute as a static variable

    // initializing an instance of the Mechanic class with the name "Ayman", age 63, and experience 21.
    Mechanic Ayman("Ayman", 63, 21);

    // asking the user to input the starting hour and minute of the appointment for the mechanic named "Ayman"
    cout << "What hour does " << Ayman.getName() << "'s appointment start ? ";
    cin >> hrs;
    cout << "What hour does " << Ayman.getName() << "'s the appointment start? ";
    cin >> mins;

    const int duration = 30; // I assumed that each appointment takes 30mins

    if (Ayman.isAvailable(hrs, mins) == 0) { // checking if the mechanic is available
        // printing a message indicating the appointment is booked
        cout << Ayman.getName() << " is Booked from " << hrs << ":" << mins << " till " << (30 + hrs) << ":" << (30 + mins) << endl;
    }
    else {
        // setting the appointment for "Ayman" starting from the specified starting hour and minute and continuing for a duration of 30 minutes.
        for (int i = 0; i <= 30; i++) {
            Ayman.setAppointment((hrs), (mins + i));
        }
    }

    Customer Ahmed; // creating an instance of the "Customer" class named "Ahmed"
    Ahmed.printInfo(); // printing out information for "Ahmed"
    Ayman.getName(); // getting the name of "Ayman"

    Ayman.printInfo(); // printing out information for "Ayman"

    system("pause>0"); 
}
