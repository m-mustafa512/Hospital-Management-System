#include <iostream>
#include <string>

using namespace std;

class Patient {
    private:
        string name;
        int age;
        int id;
        char gender;
        string disease;
    public:
        Patient() {
            name = "";
            age = 0;
            id = 0;
            gender = ' ';
            disease = "";
        }
        Patient(string n, int a, int i, char g, string d) {
            name = n;
            age = a;
            id = i;
            gender = g;
            disease = d;
        }
        void printPatient() {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "ID: " << id << endl;
            cout << "Gender: " << gender << endl;
            cout << "Disease: " << disease << endl;
        }
        int getID() {
            return id;
        }
};

class Hospital {
    private:
        Patient patients[100];
        int numPatients;
    public:
        Hospital() {
            numPatients = 0;
        }
        void addPatient() {
            if (numPatients >= 100) {
                cout << "Hospital is full." << endl;
                return;
            }
            string name, disease;
            int age, id;
            char gender;
            cout << "Enter patient name: ";
            cin >> name;
            cout << "Enter patient age: ";
            cin >> age;
            cout << "Enter patient ID: ";
            cin >> id;
            cout << "Enter patient gender (M/F): ";
            cin >> gender;
            cout << "Enter patient disease: ";
            cin >> disease;
            Patient p(name, age, id, gender, disease);
            patients[numPatients] = p;
            numPatients++;
            cout << "Patient added successfully.\n" << endl;
        }
        void showPatients() {
            if (numPatients == 0) {
                cout << "No patients in hospital." << endl;
                return;
            }
            for (int i = 0; i < numPatients; i++) {
                patients[i].printPatient();
                cout << endl;
            }
        }
        void searchPatient() {
            if (numPatients == 0) {
                cout << "No patients in hospital." << endl;
                return;
            }
            int id;
            cout << "Enter patient ID to search: ";
            cin >> id;
            for (int i = 0; i < numPatients; i++) {
                if (patients[i].getID() == id) {
                	cout<<"Patient found!\nPrinting patient data: \n";
                    patients[i].printPatient();
                    return;
                }
            }
            cout << "Patient with ID " << id << " not found." << endl;
        }
};

int main() {
		cout<<"\t\tWelcome to Hospital Management System\n";
		cout<<"\t\tMade by Muhammad Mustafa\n";

	cout<<"---------------------------------------------------------------------\n";
    Hospital h;
    int choice;
    do {
        cout << "\n1. Add patient" << endl;
        cout << "2. Show all patients" << endl;
        cout << "3. Search for a patient" << endl;
        cout << "4. Exit\n" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                h.addPatient();
                break;
            case 2:
            	cout<<"\nPrinting data of patients:\n";
                h.showPatients();
                break;
        case 3:
            h.searchPatient();
            break;
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
		}
	} while (choice != 4);
	return 0;
}
