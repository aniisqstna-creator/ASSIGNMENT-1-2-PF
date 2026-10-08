#include <iostream>
#include <string>
using namespace std;

//function mintak maklumat pesakit
void patientInformation(string &patientName, string &arrivalTime, string &patientCategory, int &age, string &patientCategoryL);
//function petingkan siapa
void getpriority(string &patientCategory, int &priorityLevel, int &waitingTime, string &queueNumber, int &emergencyCount, int &normalCount, int &seniorCount, string &patientCategoryL, string &arrivalTime);
//function untuk display maklumat pesakit
void displayPatientInformation(string &patientName, string &arrivalTime, string &patientCategory, int &age, int &priorityLevel, int &waitingTime, string &queueNumber);
//function untuk panggilan sape yang penting
void emergencyCalls(int &priorityLevel);

int main() {
    string patientName;
    string arrivalTime;
    int age;
    string patientCategory;
    string patientCategoryL;

    int priorityLevel;
    int waitingTime;

    int emergencyCount = 1;
    int seniorCount = 1;
    int normalCount = 1;

    string queueNumber;
    char choice;

    //looping
    do {
        //function mintak maklumat pesakit
        patientInformation(patientName, arrivalTime, patientCategory, age, patientCategoryL);
        //function petingkan siapa
       getpriority(patientCategory, priorityLevel, waitingTime, queueNumber, emergencyCount, normalCount, seniorCount, patientCategoryL, arrivalTime);
        //function untuk display maklumat pesakit
        displayPatientInformation(patientName, arrivalTime, patientCategory, age, priorityLevel, waitingTime, queueNumber);
        
        //function untuk panggilan sape yang penting
        emergencyCalls(priorityLevel);

        cout << "\nRegister another patient?(Y/N): ";
        cin >> choice;
        cin.ignore();

    } while (choice == 'y' || choice == 'Y');

    cout << "\n========================================" << endl;
    cout << "        REGISTRATION SYSTEM CLOSED       " << endl;
    cout << "========================================" << endl;

    return 0;
}
//function mintak maklumat pesakit
void patientInformation(string &patientName, string &arrivalTime, string &patientCategory, int &age, string &patientCategoryL) {
//function petingkan siapa kat bawah ni
    cout << "\n========================================" << endl;
    cout << "      HOSPITAL PATIENT REGISTRATION     " << endl;
    cout << "========================================" << endl;
    cout << "Enter patient name: ";
    getline(cin, patientName);
    cout << "Enter patient age: ";
    cin >> age;
    cin.ignore();
    cout << "**PATIENT CATEGORY**" << endl;
    cout << " - Emergency (E)" << endl;
    cout << " - Senior Citizen (age 60+) (S)" << endl;
    cout << " - Normal (N)" << endl;
    cout << "\nEnter patient category below: ";
    cin >> patientCategoryL;
    cin.ignore(); // Bersihkan buffer selepas cin >> patientCategoryL
}
//function petingkan siapa kat bawah ni
void getpriority(string &patientCategory, int &priorityLevel, int &waitingTime, string &queueNumber, int &emergencyCount, int &normalCount,
                 int &seniorCount, string &patientCategoryL, string &arrivalTime) {

    // Loop selagi input BUKAN E, S, atau N
    while (patientCategoryL != "E" && patientCategoryL != "e" && 
           patientCategoryL != "S" && patientCategoryL != "s" && 
           patientCategoryL != "N" && patientCategoryL != "n") {
        
        priorityLevel = 0;
        cout << "\nPatient Category Not Found. Enter again : ";
        cin >> patientCategoryL;
        cin.ignore(); // Bersihkan buffer
    }

    // Tetapkan nilai SETELAH input dipastikan betul
    if (patientCategoryL == "E" || patientCategoryL == "e") {
        patientCategory = "Emergency";
        priorityLevel = 1;
        waitingTime = 0;
        queueNumber = "E00" + to_string(emergencyCount);
        emergencyCount++;
    }
    else if (patientCategoryL == "S" || patientCategoryL == "s") {
        patientCategory = "Senior Citizen";
        priorityLevel = 2;
        waitingTime = 10;
        queueNumber = "S00" + to_string(seniorCount);
        seniorCount++;
    }
    else if (patientCategoryL == "N" || patientCategoryL == "n") {
        patientCategory = "Normal";
        priorityLevel = 3;
        waitingTime = 20;
        queueNumber = "N00" + to_string(normalCount);
        normalCount++;
    }

    cout << "Arrival time: ";
    getline(cin, arrivalTime);
}
//function untuk display maklumat pesakit

void displayPatientInformation(string &patientName, string &arrivalTime, string &patientCategory, int &age, int &priorityLevel, int &waitingTime, string &queueNumber) {
    cout << "\n======================================" << endl;
    cout << "        REGISTRATION SUCCESSFUL     " << endl;
    cout << "======================================" << endl;

    cout << "Patient Name : " << patientName << endl;
    cout << "Patient Age : " << age << endl;
    cout << "Arrival Time : " << arrivalTime << endl;
    cout << "Patient Category : " << patientCategory << endl;
    cout << "Priority Level : " << priorityLevel << endl;
    cout << "Waiting Time : " << waitingTime << " minutes" << endl;
    cout << "Queue Number : " << queueNumber << endl;
}
//function untuk panggilan sape yang penting
void emergencyCalls(int &priorityLevel) {
    if (priorityLevel == 1) {
        cout << "\n!!! EMERGENCY PATIENT !!!" << endl;
        cout << "Please proceed to the emergency department." << endl;
        cout << "Your case will be attended immediately." << endl;
    }
    else if (priorityLevel == 2) {
        cout << "\nPRIORITY PATIENT" << endl;
        cout << "You will be served before normal patients." << endl;
    }
    else if (priorityLevel == 3) {
        cout << "\nSTANDARD PATIENT" << endl;
        cout << "Please wait until your queue number is called." << endl;
    }
}
