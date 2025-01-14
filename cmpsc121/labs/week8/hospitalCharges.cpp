// Academic Integrity Affidavit:
// I certify that this program code is my work.  Others may have
// assisted me with planning and concepts, but the code was written,
// solely, by me.
// I understand that submitting code that is totally or partially
// the product of other individuals is a violation of the Academic
// Integrity Policy and accepted ethical precepts. Falsified
// execution results are also results of improper activities. Such
// violations may result in zero credit for the assignment, reduced
// credit for the assignment, or course failure.
// Name: <Jack Sangl>
// Section: <003L>
// Assignment: Hosptial Charges


#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;
//function headers
char getPatientType();
double patientCharges(int days, double roomchrg, double med, double serv); //in-patient
double patientCharges(double med, double serv); // outpatient
int getDaysInHospital(); 
double getChargesRate(string chargesItem);

int main()
{
    //define variables used for patients
    char patient;
    int days;
    double roomchrg, med, serv, charges;
    charges = 0;
    cout << "This program will compute patient hospital charges.\n";
    //get patient type
    patient = getPatientType();

    //if in-patient find rates
    switch(patient)
    {
        case 'O':   med = getChargesRate("Medication charges");
                    serv = getChargesRate("Lab fees and other service");
                    charges = patientCharges(med, serv);
                    break;

        case 'I':   days = getDaysInHospital();
                    roomchrg = getChargesRate("Daily room rate");
                    med = getChargesRate("Medication charges");
                    serv = getChargesRate("Lab fees and other service");
                    charges = patientCharges(days, roomchrg, med, serv);
                    break;
    }
    cout << endl << "The total charges are $" << setprecision(2) << fixed << charges << endl;
    return 0;
}

//gets patient type
char getPatientType()
{
    char patient;
    cout << "What was the patient type?\n";
    cout << "Inpatient or Outpatient? (I or O): ";
    cin >> patient;
    while (patient != 'I' && patient != 'O')
    {
        cout << "Invalid input!\n";
        cout << "Inpatient or Outpatient? (I or O): ";
        cin >> patient;  
    }
    return patient;
}

//figures out days in hospital
int getDaysInHospital()
{
    int days = 0;
    cout << "Number of days in the hospital: ";
    cin >> days;
    while (days < 0)
    {
        cout << "Number of days in the hospital must be zero or more!\n";
        cout << "Please enter again: ";
        cin >> days;
    }   
    return days;
}

double getChargesRate(string chargesItem)
{
    double charge = 0; 
    cout << chargesItem << " $: ";
    cin >> charge;
    while (charge < 0)
    {
        cout << chargesItem << " must be zero or more.\n";
        cout << "Please enter again: ";
        cin >> charge;
    }
    return charge;
}

//in-patient
double patientCharges(int days, double roomchrg, double med, double serv)
{
    double charges = 0;
    charges = ((days*roomchrg) + med + serv);
    return charges;
} 

// outpatient
double patientCharges(double med, double serv)
{
    double charges = 0;
    charges = med + serv;
    return charges;
}

/*
Output 1:
This program will compute patient hospital charges.
What was the patient type?
Inpatient or Outpatient? (I or O): I
Number of days in the hospital: -1
Number of days in the hospital must be zero or more!
Please enter again: 5
Daily room rate $: -10
Daily room rate must be zero or more.
Please enter again: 125
Medication charges $: 325.80
Lab fees and other service $: 150.50

The total charges are $1101.30
*/

/*
Output 2:
This program will compute patient hospital charges.
What was the patient type?
Inpatient or Outpatient? (I or O): O
Medication charges $: -25.50
Medication charges must be zero or more.
Please enter again: 85.80
Lab fees and other service $: -100
Lab fees and other service must be zero or more.
Please enter again: 250.90

The total charges are $336.70
*/
