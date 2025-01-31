#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// Define structures for data
struct Doctor {
    string name;
    string specialization;
};
struct Patient {
    string name;
    string vitalSigns;
    string medicalHistory;
    string medicationDetails;
    string labResults;
    string billingInfo;
};
struct Staff {
    string name;
    int age;
    double salary;
    string contactNumber;
    string designation;
};
struct Appointment {
    string doctorName;
    string patientName;
    string time;
    int age; // Age of patient
    string contactNumber; // Contact number of patient
    string symptoms;
};
// Function to add a new record to a file
template<typename T>
void addRecordToFile(const T& record, const string& filename) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << record << endl;
        file.close();
        cout << "Record added successfully." << endl;
        } 
    else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}
// Function to display all records from a file
void displayRecordsFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
        }
    else {
        cerr << "Error: Unable to open file for reading." << endl;
    }
}
// Overloaded insertion operator to write structs to file
ostream& operator<<(ostream& os, const Doctor& doctor) {
    os << doctor.name << " " << doctor.specialization;
    return os;
}
ostream& operator<<(ostream& os, const Patient& patient) {
    os << patient.name << " " << patient.vitalSigns << " " << patient.medicalHistory<< " " << patient.medicationDetails << " " << patient.labResults << " " <<
    patient.billingInfo;
    return os;
}
ostream& operator<<(ostream& os, const Staff& staff) {
    os << staff.name << " " << staff.age << " " << staff.salary << " " <<staff.contactNumber << " " << staff.designation;
    return os;
}
ostream& operator<<(ostream& os, const Appointment& appointment) {
    os << appointment.doctorName << " " << appointment.patientName << " " <<
    appointment.time << " " << appointment.age << " " << appointment.contactNumber<< " " << appointment.symptoms;
    return os;
}
    // Function to prompt user and add a doctor record
void addDoctorRecord() {
    Doctor doctor;
    cout << "Enter doctor name: ";
    getline(cin, doctor.name);
    cout << "Enter doctor specialization: ";
    getline(cin, doctor.specialization);
    addRecordToFile(doctor, "doctors.txt");
}
    // Function to prompt user and add a patient record
void addPatientRecord() {
    Patient patient;
    cout << "Enter patient name: ";
    getline(cin, patient.name);
    cout << "Enter patient vital signs: ";
    getline(cin, patient.vitalSigns);
    cout << "Enter patient medical history: ";
    getline(cin, patient.medicalHistory);
    cout << "Enter patient medication details: ";
    getline(cin, patient.medicationDetails);
    cout << "Enter patient lab results: ";
    getline(cin, patient.labResults);
    cout << "Enter patient billing information: ";
    getline(cin, patient.billingInfo);
    addRecordToFile(patient, "patients.txt");
}
    // Function to prompt user and add a staff record
void addStaffRecord() {
    Staff staff;
    cout << "Enter staff name: ";
    getline(cin, staff.name);
    cout << "Enter staff age: ";
    cin >> staff.age;
    cout << "Enter staff salary: ";
    cin >> staff.salary;
    cin.ignore(); // Ignore newline character
    cout << "Enter staff contact number: ";
    getline(cin, staff.contactNumber);
    cout << "Enter staff designation: ";
    getline(cin, staff.designation);
    addRecordToFile(staff, "staff.txt");
}
    // Function to prompt user and add an appointment record
void addAppointmentRecord() {
    Appointment appointment;
    cout << "Enter doctor name: ";
    getline(cin, appointment.doctorName);
    cout << "Enter patient name: ";
    getline(cin, appointment.patientName);
    cout << "Enter appointment time: ";
    getline(cin, appointment.time);
    cout << "Enter patient age: ";
    cin >> appointment.age;
    cin.ignore(); // Ignore newline character
    cout << "Enter patient contact number: ";
    getline(cin, appointment.contactNumber);
    cout << "Enter patient symptoms: ";
    getline(cin, appointment.symptoms);
    addRecordToFile(appointment, "appointments.txt");
}
int main() {
    int choice;
    do {
        cout << "Hospital Management System" << endl;
        cout << "1. Add Doctor Record" << endl;
        cout << "2. Add Patient Record" << endl;
        cout << "3. Add Staff Record" << endl;
        cout << "4. Add Appointment Record" << endl;
        cout << "5. Display Records" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore any trailing newline characters

        switch (choice) {
            case 1:
            addDoctorRecord();
            break;
            case 2:
            addPatientRecord();
            break;
            case 3:
            addStaffRecord();
            break;
            case 4:
            addAppointmentRecord();
            break;
            case 5:
            // Display records
            displayRecordsFromFile("doctors.txt");
            displayRecordsFromFile("patients.txt");
            displayRecordsFromFile("staff.txt");
            displayRecordsFromFile("appointments.txt");
            break;
            case 6:
            cout << "Exiting program." << endl;
            break;
            default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } 
    while (choice != 6);
        return 0;
}