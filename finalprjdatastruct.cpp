#include <iostream>
#include<ctime>
#include<cstdlib>
#include<string>
#include<iomanip>
using namespace std;

struct lab {
	int nmac;
	int nmed;
	string machine;
	string medicalsupp;
	lab* next;
	lab* next2;
};
lab* headlab = nullptr;
lab* headlab2 = nullptr;

struct employee {
	int nemp;
	string fname;
	string lname;
	int age;
	employee* next;
};
employee* head = nullptr;

struct Schedule {
	int hours;
	int hours2;
};
struct Doctors {
	int n;
	string id[100];
	char fname[100][30];
	char lname[100][30];
	int age[100];
	char address[100][50];
	char speciality[100];
	Schedule schedule[100][7];
};
struct Nurses {
	int n;
	string id[100];
	char fname[100][30];
	char lname[100][30];
	int age[100];
	char address[100][50];
};
struct Patient {
	int n = 0;
	char fname[100][30];
	char lname[100][30];
	int age[100];
	string disease[100];
};
void introduceDoctors(Doctors*);
void addDoctor(Doctors*);
bool deleteDoctor(Doctors*, string);
void modifyDoctor(Doctors*,string);
void introduceNurses(Nurses*);
void addNurse(Nurses*);
bool deleteNurses(Nurses*, string);
void modifyNurses(Nurses*, string);
void doctorfeedback(Doctors*,char[30], char[30]);
void sortdoctors(Doctors*);
void readDoctorSchedule(Doctors* doc);
void printDoctorSchedule( Doctors* doc);
void introducepatient(Patient*);
bool searchNurse(Nurses* nurse, string id, int);
void appointment(Patient*, Doctors*);
void Bill(Patient, Doctors);
void displaydoctors(Doctors*);
void displaynurses(Nurses*);
void displaypatients(Patient*);

//lab functions------------------------------------------------------
void introducelabemp(employee*);
void displaylabemp();
void addlabemp(employee*);
void deletelabemp(string, string);
void introducelabmachines(lab*);
void introducelabsupplies(lab*);
bool IsEmpty(lab*);
bool searchMachine(string);
bool searchsupp(string);
//main-------------------------------------------------------------------------------------
int main() {
	cout << "Welcome to UA Hospital Mangment System" << endl;
	cout << "----------------------------------------" << endl;
		Doctors d;
		cout << "Introducing Doctors in the Hospital: " << endl;
		introduceDoctors(&d);
		string id;
		int choice1 = 0;
		char fname[30];
		char lname[30];
		while (choice1 != 8) {
			cout << "Choose what you want to do" << endl
				<< "1-display Doctors (according to increaing age) " << endl
				<< "2-Add Doctor " << endl
				<< "3-delete Doctor " << endl
				<< "4-modify the Doctor " << endl
				<< "5-Add Doctors schedule" << endl
				<< "6-Display Doctors schedule" << endl
				<< "7-enter feedback for a doctor" << endl
				<< "8-exit" << endl;
			do {
				cin >> choice1;
			}while(choice1>8 && choice1<0);

			switch (choice1) {
			case 1:
				sortdoctors(&d);
				displaydoctors(&d);
				break;
			case 2:
				addDoctor(&d);
				break;
			case 3:
				cout << "enter the id of the doctor you want to delete: ";
				cin >> id;
				cout << endl;
				if (deleteDoctor(&d, id)) {
					cout << "doctor has been deleted";
				}
				else {
					cout << "doctor not found";
				}
				break;
			case 4:
				cout << "enter the id of the doctor you want to delete: ";
				cin >> id;
				cout << endl;
				modifyDoctor(&d, id);
				break;
			case 5:
				readDoctorSchedule(&d);
				break;
			case 6:
				printDoctorSchedule(&d);
				break;
			case 7:
				cout << "enter fname of the doctor: ";
				cin >> fname;
				cout << "enter lname of the doctor: ";
				cin >> lname;
				doctorfeedback(&d, fname, lname);
			case 8:
				cout << "you Exited!!";
			}
		}

		Nurses n;
		int choice2 = 0;
		string id2;
		cout << "introducing nurses in the hospital: " << endl;
		introduceNurses(&n);
		while (choice2 != 6) {
			cout << "Choose what you want to do" << endl
				<< "1-display nurses " << endl
				<< "2-Add nurse " << endl
				<< "3-delete nurse " << endl
				<< "4-modify the nurse " << endl
				<< "5-search nurse " << endl
				<< "6-exit" << endl;
			do {
				cin >> choice2;
			} while (choice2 > 6 && choice2<0);

			switch (choice2) {
			case 1:
				displaynurses(&n);
				break;
			case 2:
				addNurse(&n);
				break;
			case 3:
				cout << "enter the id of the  : " << endl;
				cin >> id2;
				if (deleteNurses(&n, id2)) {
					cout << "nurse has been deleted";
				}
				else {
					cout << "nurse not found";
				}
				break;
			case 4:
				cout << "enter the id of the doctor: " << endl;
				cin >> id2;
				modifyNurses(&n, id2);
				break;
			case 5:
				cout << "enter the id of the nurse: ";
				cin >> id2;
				if (searchNurse(&n, id2, 0)) {
					cout << "nurse is found";
				}
				else {
					cout << "nurse is not found";
				}
				break;
			case 6:
				cout << "you Exited!!";
			}
		}
		int choice3 = 0;
		Patient p;
		cout << "introducing patients: ";
		introducepatient(&p);
		while (choice3 != 4) {
			cout << "choose what do you want to do" << endl
				<< "1-Display all patients"<<endl
				<< "2-Take an appointment for the patient"<<endl
				<< "3-Print the bill for the patient"<<endl
				<< "4-Exit"<<endl;
			do {
				cin >> choice3;
			} while (choice3 > 4);

			switch (choice3) {
			case 1:
				displaypatients(&p);
				break;
			case 2:
				appointment(&p, &d);
				break;
			case 3:
				Bill(p, d);
				break;
			case 4:
				cout << "you Exited!";
			}
		}

		int choice4=0;
		do {
			cout << "do you want to continue to lab" << endl
				<< "press 1 to continue to the lab" << endl
				<< "press 2 to Exit" << endl;
			cin >> choice4;
		}while(choice4!=1 && choice4!=2);

		if (choice4 == 1) {
			int choice5 = 0;
			lab l;
			employee emp;
			cout << "introducing the laboratory in the hospital: " << endl;
			cout << "introducing the employees in the lab: " << endl;
			introducelabemp(&emp);
			string empfname;
			string emplname;
			while (choice5 != 4) {
				cout << "choose what do you want to do" << endl
					<< "1-display lab employees" << endl
					<< "2-add employee to the lab" << endl
					<< "3-delete employee from the lab" << endl
					<< "4-Exit" << endl;
				do {
					cin >> choice5;
				} while (choice5 > 4 && choice5<0);
				switch (choice5) {
				case 1:
					displaylabemp();
					break;
				case 2:
					addlabemp(&emp);
					break;
				case 3:
					cout << "enter the fname of the employee: ";
					cin >> empfname;
					cout << "enter the lname of the employee: ";
					cin >> emplname;
					deletelabemp(empfname, emplname);
					break;
				case 4:
					cout << "you exited!";
				}
			}

			cout << "introduce lab machines";
			introducelabmachines(&l);
			cout << "introduce lab medical supplies";
			introducelabsupplies(&l);
			int choice6 = 0;
			while (choice6 != 3) {
				cout << "choose what do you want to do" << endl
					<< "1-search lab machines" << endl
					<< "2-search lab medical supplies" << endl
					<< "3-Exit" << endl;
				do {
					cin >> choice6;
				} while (choice6 > 3 && choice6<0);
				string machinename;
				string suppname;
				switch (choice6) {
				case 1:
					cout << "enter machine name:";
					cin >> machinename;
					if (searchMachine(machinename)) {
						cout << "Machine is found";
					}
					else {
						cout << "machine is not found";
					}
					break;
				case 2:
					cout << "enter medical supply name: ";
					cin >> suppname;
					if (searchsupp(suppname)) {
						cout << "Medical supply is found";
					}
					else {
						cout << "medical supply is not found";
					}
					break;
				case 3:
					cout << "you exited";
				}
			}
		}
		else {
			cout << "Exiting..................";
		}
	
	return 0;
}
//--------------------------------------------------------------------------------------------
//doctor functions
void introduceDoctors(Doctors* doc) {
	do{
		cout << "enter the number of doctors you want to add to your hospital:";
		cin >> doc->n;
	} while (doc->n < 0 || doc->n >100);

	for (int i = 0; i < doc->n; i++) {
		cout << "enter the fname of the doctor " << i + 1 <<": " << endl;
		cin >> doc->fname[i];
		cout << "enter the lname of the doctor " << i + 1 << ": " << endl;
		cin >> doc->lname[i];
		do {
			cout << "enter the age of the doctor " << i + 1 << ": " << endl;
			cin >> doc->age[i];
		} while (doc->age[i] < 25 || doc->age[i]>65);

		srand(time(0));
		int Random = rand() % 9000 + 1000;
		string numm = to_string(Random);
		doc->id[i] = doc->fname[i][0] + numm + string(1, doc->lname[i][1]);
		cout << "enter the address of the doctor " << i + 1 << ": "<<endl;
		cin >> doc->address[i];
		
		do {
		cout << "enter the speciality of the doctor ('b' for bone/ 'h' for heart/'n' for nerves/'g' for general/'s' for skin)" << i + 1 << ": " << endl;
			cin >> doc->speciality[i];
		} while (doc->speciality[i] != 'b' &&doc->speciality[i] !='h'&&doc->speciality[i]!='n'&& doc->speciality[i] != 'g'&& doc->speciality[i] != 's');
		cout << endl << "___________________________________________________________" << endl;
	}
}
void displaydoctors(Doctors* doc) {
	for (int i = 0; i < doc->n; i++) {
		cout << "Doctor " << i + 1 << ": " << endl;
		cout << "id: " << doc->id[i] << endl;
		cout << "fname: " << doc->fname[i] << endl;
		cout << "lname: " << doc->lname[i] << endl;
		cout << "age: " << doc->age[i] << endl;
		cout << "address: " << doc->address << endl;
		cout << "speciality: " << doc->speciality[i] << endl << endl;
		cout << "-----------------------------------------------------" << endl;
	}
}
void addDoctor(Doctors* doc) {
	if (doc->n == 100) {
		cout << "you cant add a doctor the array is full";
	}
	else {
		cout << "enter the fname of the doctor : " << endl;
		cin >> doc->fname[doc->n];
		cout << "enter the lname of the doctor : " << endl;
		cin >> doc->lname[doc->n];
		do {
			cout << "enter the age of the doctor : " << endl;
			cin >> doc->age[doc->n];
		} while (doc->age[doc->n] < 25 || doc->age[doc->n]>65);

		srand(time(0));
		int Random = rand() % 9000 + 1000;
		string numm = to_string(Random);
		doc->id[doc->n] = doc->fname[doc->n][0] + numm + string(1, doc->lname[doc->n][1]);
		cout << "enter the address of the doctor : " << endl;
		cin >> doc->address[doc->n];
		do {
			cout << "enter the speciality of the doctor ('b' for bone/ 'h' for heart/'n' for nerves/'g' for general/'s' for skin) : " << endl;
			cin >> doc->speciality[doc->n];
		} while (doc->speciality[doc->n] != 'b' && doc->speciality[doc->n] != 'h' && doc->speciality[doc->n] != 'n' && doc->speciality[doc->n] != 'g' && doc->speciality[doc->n] != 's');
		cout << "a new doctor has been added";
		doc->n++;
	}
}

bool deleteDoctor(Doctors* doc, string id) {
	int foundIndex = 0;
	bool found = false;
	for (int i = 0; i < doc->n; i++) {
		if (id==doc->id[i]) {
			foundIndex = i;
			found = true;
			break;
		}
	}
	if (found == true) {
		for (int i = foundIndex; i < (doc->n - 1); i++) {
			doc->id[i] = doc->id[i + 1];
			for (int j = 0; j < 30; ++j) {
				doc->fname[i][j] = doc->fname[i + 1][j];
				doc->lname[i][j] = doc->lname[i + 1][j];
			}
			doc->age[i] = doc->age[i + 1];
			for (int j = 0; j < 50; ++j) {
				doc->address[i][j] = doc->address[i + 1][j];
			}
			doc->speciality[i] = doc->speciality[i + 1];
		}
		doc->n--;
		return true;
	}
	else {
		return false;
	}
}

void modifyDoctor(Doctors* doc,string id) {
	int foundIndex = 0;
	bool found = false;
	for (int i = 0; i < doc->n; i++) {
		if (id == doc->id[i]) {
			foundIndex = i;
			found = true;
			break;
		}
	}
	if (found == true) {
			cout << "fname: " << doc->fname[foundIndex] << endl;
			cout << "lname: " << doc->lname[foundIndex] << endl;
			cout << "age: " << doc->age[foundIndex] << endl;
			cout << "address: " << doc->address[foundIndex] << endl;
			cout<<"speciality: "<<doc->speciality[foundIndex] << endl;

			int choice = 0;
			while (choice != 6) {
				cout << "choose what you want to modify: "<<endl;
				cout << "1- for fname" << endl;
				cout << "2- for lname" << endl;
				cout << "3- for age" << endl;
				cout << "4- for address" << endl;
				cout << "5- for speciality" << endl;
				cout << "6- Exit" << endl;
				cin >> choice;
				switch (choice) {
				case 1:cout << "enter the fname: " << endl;
					cin >> doc->fname[foundIndex];
					break;
				case 2:cout << "enter the lname: "<<endl;
					cin >> doc->lname[foundIndex];
					break;
				case 3:cout << "enter the age: "<<endl;
					cin >> doc->age[foundIndex];
					break;
				case 4:cout << "enter the address: "<<endl;
					cin >> doc->address[foundIndex];
					break;
				case 5:cout << "enter the speciality: "<<endl;
					cin >> doc->speciality[foundIndex];
				case 6:cout << "Exiting...";
					break;
				}
			}
			cout << "doctor info has been modified";
			cout << "fname: " << doc->fname[foundIndex] << endl;
			cout << "lname: " << doc->lname[foundIndex] << endl;
			cout << "age: " << doc->age[foundIndex] << endl;
			cout << "id: " << doc->id[foundIndex] << endl;
			cout << "address: " << doc->address[foundIndex] << endl;
			cout << "speciality: " << doc->speciality[foundIndex] << endl;
	}
}

void doctorfeedback(Doctors* doc, char fname[30], char lname[30]) {
	string feedback;
	bool found = false;
	int foundindex = 0;
	for (int i = 0; i < doc->n; i++) {
		if (strcmp(fname, doc->fname[i]) == 0 && strcmp(lname, doc->lname[i]) == 0) {
			foundindex = i;
			found = true;
			break;
		}
	}
	if (found) {
		cout << "enter you feedback: ";
		cin >> feedback;
		cout << "your feedback has been claimed";
	}
	else {
		cout << "doctor not found";
	}
}
void sortdoctors(Doctors* doc) {
	int temp = 0;
	for (int i = 0; i < doc->n; i++) {
		for (int j = 0; j < doc->n - 1 - i; j++) {
			if (doc->age[j] > doc->age[j + 1]) {
				temp = doc->age[j];
				doc->age[j] = doc->age[j + 1];
				doc->age[j + 1] = temp;
			}
		}
	}
}

void readDoctorSchedule(Doctors* doc) {
	for (int i = 0; i < doc->n; i++) {
		cout << "Enter the schedule for doctor " << doc->fname[i] << " " << doc->lname[i] << " (ID: " << doc->id[i] << "):\n";
		for (int j = 0; j < 7; j++) {
			cout << "Enter the schedule for day " << j + 1 << " (From:To): " << endl;
			do {
				cout << "from: ";
				cin >> doc->schedule[i][j].hours;
			} while (doc->schedule[i][j].hours > 12);
			do {
				cout << "To: ";
				cin >> doc->schedule[i][j].hours2;
			} while (doc->schedule[i][j].hours2 > 12 || doc->schedule[i][j].hours2< doc->schedule[i][j].hours);
		}
	}
}

void printDoctorSchedule(Doctors* doc) {
	cout << "Doctor Schedule:\n";
	cout << setw(10) << "Doctor ID" << setw(15) << "Doctor Name";
	for (int i = 1; i <= 7; i++) {
		cout << setw(10) << "Day " << i;
	}
	cout << "\n";

	for (int i = 0; i < doc->n; i++) {
		cout << setw(6) << doc->id[i] << setw(12) << doc->fname[i] << " " << doc->lname[i];
		for (int j = 0; j < 7; j++) {
			cout << setw(6) << doc->schedule[i][j].hours << ":" << setw(2) << doc->schedule[i][j].hours2;
		}
		cout << "\n";
	}
}

//Nurse functions-------------------------------------------------------------------------
void introduceNurses(Nurses* nurse) {

	do {
		cout << "enter the number of nurses you want to add to your hospital:";
		cin >> nurse->n;
	} while (nurse->n < 0 || nurse->n >100);

	for (int i = 0; i < nurse->n; i++) {
		cout << "enter the fname of the nurse " << i + 1 << ": " << endl;
		cin >> nurse->fname[i];
		cout << "enter the lname of the nurse " << i + 1 << ": " << endl;
		cin >> nurse->lname[i];
		do {
			cout << "enter the age of the nurse " << i + 1 << ": " << endl;
			cin >> nurse->age[i];
		} while (nurse->age[i] < 25 || nurse->age[i]>65);

		srand(time(0));
		int Random = rand() % 9000 + 1000;
		string numm = to_string(Random);
		nurse->id[i] = nurse->fname[i][0] + numm + string(1, nurse->lname[i][1]);
		cout << "enter the address of the nurse " << i + 1 << ": " << endl;
		cin >> nurse->address[i];
		cout << endl << "___________________________________________________________" << endl;
	}
	
}

void displaynurses(Nurses* nurse) {
	for (int i = 0; i < nurse->n; i++) {
		cout << "Doctor " << i + 1 << ": " << endl;
		cout << "id: " << nurse->id[i] << endl;
		cout << "fname: " << nurse->fname[i] << endl;
		cout << "lname: " << nurse->lname[i] << endl;
		cout << "age: " << nurse->age[i] << endl;
		cout << "address: " << nurse->address[i] << endl;
	}
}

void addNurse(Nurses* nurse) {
	if (nurse->n == 100) {
		cout << "you cant add a nurse the array is full";
	}
	else {
		cout << "enter the fname of the nurse : " << endl;
		cin >> nurse->fname[nurse->n];
		cout << "enter the lname of the nurse : " << endl;
		cin >> nurse->lname[nurse->n];
		do {
			cout << "enter the age of the nurse : " << endl;
			cin >> nurse->age[nurse->n];
		} while (nurse->age[nurse->n] < 25 || nurse->age[nurse->n]>65);

		srand(time(0));
		int Random = rand() % 9000 + 1000;
		string numm = to_string(Random);
		nurse->id[nurse->n] = nurse->fname[nurse->n][0] + numm + string(1, nurse->lname[nurse->n][1]);
		cout << "enter the address of the nurse : " << endl;
		cin >> nurse->address[nurse->n];

		cout << "a new nurses has been added";
		nurse->n++;
	}
}

bool deleteNurses(Nurses* nurse, string id) {
	int foundIndex = 0;
	bool found = false;
	for (int i = 0; i < nurse->n; i++) {
		if (id == nurse->id[i]) {
			foundIndex = i;
			found = true;
			break;
		}
	}
	if (found == true) {
		for (int i = foundIndex; i < (nurse->n - 1); i++) {
			nurse->id[i] = nurse->id[i + 1];
			for (int j = 0; j < 30; ++j) {
				nurse->fname[i][j] = nurse->fname[i + 1][j];
				nurse->lname[i][j] = nurse->lname[i + 1][j];
			}
			nurse->age[i] = nurse->age[i + 1];
			for (int j = 0; j < 50; ++j) {
				nurse->address[i][j] = nurse->address[i + 1][j];
			}
		}
		nurse->n--;
		return true;
	}
	else {
		return false;
	}
}

void modifyNurses(Nurses* nurse, string id) {
	int foundIndex = 0;
	bool found = false;
	for (int i = 0; i < nurse->n; i++) {
		if (id == nurse->id[i]) {
			foundIndex = i;
			found = true;
			break;
		}
	}
	if (found == true) {
		cout << "fname: " << nurse->fname[foundIndex] << endl;
		cout << "lname: " << nurse->lname[foundIndex] << endl;
		cout << "age: " << nurse->age[foundIndex] << endl;
		cout << "address: " << nurse->address[foundIndex] << endl;

		int choice = 0;
		while (choice != 5) {
			cout << "choose what you want to modify: " << endl;
			cout << "1- for fname" << endl;
			cout << "2- for lname" << endl;
			cout << "3- for age" << endl;
			cout << "4- for address" << endl;
			cout << "5- Exit" << endl;
			cin >> choice;
			switch (choice) {
			case 1:cout << "enter the fname: " << endl;
				cin >> nurse->fname[foundIndex];
				break;
			case 2:cout << "enter the lname: " << endl;
				cin >> nurse->lname[foundIndex];
				break;
			case 3:cout << "enter the age: " << endl;
				cin >> nurse->age[foundIndex];
				break;
			case 4:cout << "enter the address: " << endl;
				cin >> nurse->address[foundIndex];
				break;
			case 5:cout << "Exiting...";
				break;
			}
		}
		cout << "nurse info has been modified";
		cout << "fname: " << nurse->fname[foundIndex] << endl;
		cout << "lname: " << nurse->lname[foundIndex] << endl;
		cout << "age: " << nurse->age[foundIndex] << endl;
		cout << "id: " << nurse->id[foundIndex] << endl;
		cout << "address: " << nurse->address[foundIndex] << endl;
	}
}

bool searchNurse( Nurses* nurse, string id, int currentIndex) {
	if (currentIndex == nurse->n) {
		return false;
	}
	if (id == nurse->id[currentIndex]) {
		return true;
	}
	return searchNurse(nurse, id, currentIndex + 1);
}

//Patient functions-------------------------------------------------------------------------
void introducepatient(Patient* p) {
	string gfname, glname, gdisease;
	int gage;
	char choice;
	do {
		cout << "do you want to create a file or continue as a geust:('y' for yes 'n' for no) ";
		cin >> choice;
	} while (choice != 'y' && choice != 'n');
	if (choice == 'n') {
		cout << "enter the fname of the patient: ";
		cin >> gfname;
		cout << "enter the lname of the patient: ";
		cin >> glname;
		do {
			cout << "enter the age of the patient: ";
			cin >> gage;
		} while (gage < 0 || gage>150);
		do {
			cout << "enter the disease of the patient (choose bone , skin , heart , nerves , others: ";
			cin >> gdisease;
		} while (gdisease != "bone" && gdisease != "skin" && gdisease != "heart" && gdisease != "nerves" && gdisease != "others");
	}
	char choice2;
	if (choice == 'y') {
		do {
			cout << "enter the fname of the patient " << (p->n)+1 << ": " << endl;
			cin >> p->fname[p->n];
			cout << "enter the lname of the patient " << (p->n)+1 << ": " << endl;
			cin >> p->lname[p->n];
			do {
				cout << "enter the age of the patient " << (p->n)+1 << ": " << endl;
				cin >> p->age[p->n];
			} while (p->age[p->n] < 0 || p->age[p->n]>150);
			do {
				cout << "enter the disease of the patient (choose bone , skin , heart , nerves , others: " << (p->n)+1 << ": " << endl;
				cin >> p->disease[p->n];
			} while (p->disease[p->n] != "bone" && p->disease[p->n] != "skin" && p->disease[p->n] != "heart" && p->disease[p->n] != "nerves" && p->disease[p->n] != "others");
			p->n++;
			do {
				cout << "do you want to add more patients('y' for yes 'n' for no): ";
				cin >> choice2;
			} while (choice2 != 'n' && choice2!='y');

		} while (choice2 == 'y');
	}
}

void displaypatients(Patient* p) {
	for (int i = 0; i < p->n; i++) {
		cout << "patient " << i + 1 << ": " << endl;
		cout << "fname: " << p->fname[i] << endl;
		cout << "lname: " << p->lname[i] << endl;
		cout << "age: " << p->age[i] << endl;
		cout << "disease: " << p->disease[i] << endl;
	}
}

void appointment(Patient* p, Doctors* d) {
	string fname, lname;
	int hour1, hour2;
	cout << "Here is the schedule: " << endl;
	printDoctorSchedule(d);
	cout << "Choose which doctor you want to appoint: " << endl;
	cin >> fname >> lname;

	int index = -1;
	for (int i = 0; i < d->n; i++) {
		if (fname == d->fname[i] && lname == d->lname[i]) {
			index = i;
			break;
		}
	}
	if (index != -1) {
		cout << "Available appointments for Dr. " << fname << " " << lname << ":" << endl;
		for (int j = 0; j < 7; j++) {
			if (d->schedule[index][j + 1].hours == 0 && d->schedule[index][j + 1].hours2 == 0) {
				cout << "Day " << j + 1 << ": Available" << endl;
			}
		}
		int Day;
		cout << "Choose the day for your appointment (1-7): ";
		cin >> Day;
		if (Day >= 1 && Day <= 7) {
			cout << "Available hours for Dr. " << fname << " " << lname << " on Day " << Day << ":" << endl;

			if (d->schedule[index][Day - 1].hours == 0 && d->schedule[index][Day - 1].hours2 == 0) {

				cout << "No appointments available on this day." << endl;
			}
			else {

				cout << "Available hours: " << d->schedule[index][Day - 1].hours << " to " << d->schedule[index][Day - 1].hours2 << endl;
				cout << "Choose the hour for your appointment: ";
				cin >> hour1;

				if (hour1 == d->schedule[index][Day - 1].hours) {
					d->schedule[index][Day - 1].hours = 0;

					cout << "appointment booked!!";
				}
				else if (hour1 != d->schedule[index][Day - 1].hours) {

					cout << "theres no appointment available on this day!! " << endl;
				}
				else {
					cout << "Invalid day. Please choose a day between 1 and 7." << endl;
				}
			}

		}
		else
			cout << "Doctor not found." << endl;

	}
}

void Bill(Patient p,Doctors d) {
	bool found = false;
	int foundindex = -1;
	string fname;
	string lname;
	string disease;
	cout << "enter the fname of the patient: ";
	cin >> fname;
	cout << "enter the lname of the patient: ";
	cin >> lname;
	cout << "enter what was the patient suffering from: ";
	cin >> disease;
	for (int i = 0; i < p.n; i++) {
		if (fname == p.fname[i] && lname == p.lname[i]) {
			found = true;
			foundindex = i;
		}
	}
	double price;
	if (found) {
		do {
			cout << "enter how much the patient should pay: ";
			cin >> price;
		} while (price < 0 || price>30000);
	}
	cout << "-----------------------------------------------------------------" << endl;
	cout << "UA Hospital" << endl;
	cout << "Bill: ";
	cout << "First name of the patient: " << fname << endl;
	cout << "Last name of the patient: " << lname << endl;
	cout << "The Patient Disease: " << disease << endl;
	cout << " Total Cost: " << price << " $ " << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "UA Hospital Administration" << endl;
}

//laboratory functions-----------------------------------------------------------------
void introducelabemp(employee* empnb) {
	cout << "enter the number of employees in the laboratory: ";
	cin >> empnb->nemp;
	for (int i = 0; i < empnb->nemp; i++) {
		employee* emp = new employee;
		cout << "enter the fname of the employee "<<i+1<<": ";
		cin >> emp->fname;
		cout << "enter the lname of the employee "<<i+1<<": ";
		cin >> emp->lname;
		do {
			cout << "enter the age of the employee "<<i+1<<": ";
			cin >> emp->age;
		} while (emp->age < 20 || emp->age>65);

		emp->next = nullptr;

		if (head == nullptr) {
			head = emp;
		}
		else {
			employee* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = emp;
		}
	}
}
 void displaylabemp() {
		cout << "\nEmployee Information:\n";
		employee* current = head;
		while (current != nullptr) {
			cout << "fname: "<<current->fname << " ,lname: " << current->lname << " ,Age: " << current->age << endl;
			current = current->next;
		}
}

 void addlabemp(employee* emp) {

	 cout << "Enter the fname of the employee: ";
	 cin >> emp->fname;

	 cout << "Enter the lname of the employee: ";
	 cin >> emp->lname;

	 do {
		 cout << "Enter the age of the employee: ";
		 cin >> emp->age;
	 } while (emp->age < 20 || emp->age > 65);

	 emp->next = nullptr;

	 if (head == nullptr) {
		 head = emp;
	 }
	 else {
		 employee* temp = head;
		 while (temp->next != nullptr) {
			 temp = temp->next;
		 }
		 temp->next = emp;
	 }

	 cout << "Employee added successfully." << endl;
 }

 void deletelabemp(string fname, string lname) {
	 if (head == nullptr) {
		 cout << "List is empty. No employee to delete.\n";
		 return;
	 }

	 if (head->fname == fname && head->lname == lname) {
		 employee* temp = head;
		 head = head->next;
		 delete temp;
		 cout << "Employee deleted successfully.\n";
		 return;
	 }

	 employee* current = head;
	 employee* previous = nullptr;

	 while (current != nullptr && (current->fname != fname || current->lname != lname)) {
		 previous = current;
		 current = current->next;
	 }

	 if (current == nullptr) {
		 cout << "Employee not found.\n";
		 return;
	 }

	 previous->next = current->next;
	 delete current;

	 cout << "Employee deleted successfully.\n";
 }

 void introducelabmachines(lab* labnb) {
	 cout << "enter the number of machines in the laboratory: ";
	 cin >> labnb->nmac;
	 for (int i = 0; i < labnb->nmac; i++) {
		 lab* l = new lab;
		 cout << "enter the name of machine " << i + 1 << ": ";
		 cin >> l->machine;

		 l->next = nullptr;

		 if (headlab == nullptr) {
			 headlab = l;
		 }
		 else {
			 lab* temp = headlab;
			 while (temp->next != nullptr) {
				 temp = temp->next;
			 }
			 temp->next = l;
		 }
	 }
 }

 void introducelabsupplies(lab* labnb) {
	 cout << "enter the number of medical supplies in the laboratory: ";
	 cin >> labnb->nmed;
	 for (int i = 0; i < labnb->nmed; i++) {
		 lab* l = new lab;
		 cout << "enter the name of medical supply " << i + 1 << ": ";
		 cin >> l->medicalsupp;

		 l->next2 = nullptr;

		 if (headlab2 == nullptr) {
			 headlab2 = l;
		 }
		 else {
			 lab* temp = headlab2;
			 while (temp->next2 != nullptr) {
				 temp = temp->next2;
			 }
			 temp->next2 = l;
		 }
	 }
 }

 bool IsEmpty(lab* head) {
	 return head == nullptr;
 }

 bool searchMachine(string name) {
	 lab* cur = headlab;
	 if (IsEmpty(headlab)) {
		 return false;
	 }
	 while (cur != nullptr) {
		 if (cur->machine == name) {
			 return true;
		 }
		 cur = cur->next;
	 }
	 return false;
 }
 bool searchsupp(string name) {
	 lab* cur = headlab2;
	 if (IsEmpty(headlab2)) {
		 return false;
	 }
	 while (cur != nullptr) {
		 if (cur->medicalsupp == name) {
			 return true;
		 }
		 cur = cur->next2;
	 }
	 return false;
 }



