#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

class Customer {
    string fname;
    string lname;
    int enroll;
    string car;
    float amount;

public:
    Customer();
    void setFirstName(string fnm);
    void setLastName(string lnm);
    void setEnroll(int e);
    void setCarName(string cnm);
    void setAmount(float amt);

    string getFirstName();
    string getLastName();
    int getEnroll();
    string getCarName();
    float getAmount();

    void printData();
};

Customer::Customer() {
    fname = lname = car = "";
    enroll = 0;
    amount = 0;
}

void Customer::setFirstName(string fnm) {
    fname = fnm;
}

void Customer::setLastName(string lnm) {
    lname = lnm;
}
void Customer::setEnroll(int e) {
    enroll = e;
}
void Customer::setCarName(string cnm) {
    car = cnm;
}
void Customer::setAmount(float amt) {
    amount = amt;
}

string Customer::getFirstName() {
    return(fname);
}
string Customer::getLastName() {
    return(lname);
}
int Customer::getEnroll() {
    return(enroll);
}
string Customer::getCarName() {
    return(car);
}
float Customer::getAmount() {
    return(amount);
}

void Customer:: printData() {
    cout<<left<<setw(25)<<getFirstName()+" "+getLastName()<<left<<setw(15)<<getEnroll()<<left<<setw(15)<<getCarName()<<left<<setw(15)<<fixed<<setprecision(2)<<getAmount()<<endl;
}


class Staff {
    string fname;
    string lname;
    string car;
    float salary;

public:
    Staff();
    void setFirstName(string fnm);
    void setLastName(string lnm);
    void setCarName(string cnm);
    void setSalary(float sal);

    string getFirstName();
    string getLastName();
    string getCarName();
    float getSalary();

    void printData();
};

Staff::Staff() {
    fname = lname = car = "";
    salary = 0;
}

void Staff::setFirstName(string fnm) {
    fname = fnm;
}

void Staff:: setLastName(string lnm) {
    lname = lnm;
}

void Staff::setCarName(string cnm) {
    car = cnm;
}

void Staff::setSalary(float sal) {
    salary = sal;
}

string Staff::getFirstName() {
    return(fname);
}
string Staff::getLastName() {
    return(lname);
}

string Staff::getCarName() {
    return(car);
}
float Staff::getSalary() {
    return(salary);
}

void Staff:: printData() {
    cout<<left<<setw(25)<<getFirstName()+" "+getLastName()<<left<<setw(15)<<getCarName()<<left<<setw(15)<<fixed<<setprecision(2)<<getSalary()<<endl;
}

int main() {
    string fnm, lnm, carnm;
    float amt, sal;
    int e, i=0, recno;

    ifstream fstaff("staff.txt");
    if(!fstaff) {
        cout<<"File can not be opened"<<endl;
        exit(1);
    }

    fstaff>>recno;
    Staff s[recno];
    cout<<left<<setw(25)<<"Name"<<left<<setw(15)<<"Car"<<left<<setw(15)<<"Salary"<<endl;
    cout<<"____________________________________________________________________________"<<endl;
    for(i=0; i<recno; i++) {
        fstaff>>fnm>>lnm>>carnm>>sal;
        s[i].setFirstName(fnm);
        s[i].setLastName(lnm);
        s[i].setCarName(carnm);
        s[i].setSalary(sal);
        s[i].printData();
    }
    fstaff.close();


    ifstream fcust("customers.txt");
    if(!fcust) {
        cout<<"File can not be opened"<<endl;
        exit(1);
    }

    fcust>>recno;
    Customer c[recno];
    cout<<endl<<endl;
    cout<<left<<setw(25)<<"Name"<<left<<setw(15)<<"Preferred"<<left<<setw(15)<<"Car"<<left<<setw(15)<<"Bill"<<endl;
    cout<<"____________________________________________________________________________"<<endl;
    for(i=0; i<recno; i++) {
        fcust>>fnm>>lnm>>e>>carnm>>amt;
        c[i].setFirstName(fnm);
        c[i].setLastName(lnm);
        c[i].setEnroll(e);
        c[i].setCarName(carnm);
        c[i].setAmount(amt);
        c[i].printData();
    }
    fcust.close();

    return 1;
}
