#include <iostream>
#include <string>
using namespace std;

#pragma once

class Person {

    protected:

        //commun
        string code;
        string name;
        string adress;
        string phone;
        string startDate;
        string officePost;
        float salary;

        string area; // Gerente + Diretor
        string formation; // Diretor + Presidente
        string academy; // Presidente


    public:

        virtual ~Person(){}

        virtual void setCode(string value){ this->code = value; }
        virtual string getCode(){ return this->code; }

        virtual void setName(string value){ this->name = value; }
        virtual string getName(){ return this->name; }

        virtual void setAdress(string value){ this->adress = value; }
        virtual string getAdress(){ return this->adress; }

        virtual void setPhone(string value){ this->phone = value; }
        virtual string getPhone(){ return this->phone; }

        virtual void setStartDate(string value){ this->startDate = value; }
        virtual string getStartDate(){ return this->startDate; }

        virtual void setOfficePost(string value){ this->officePost = value; }
        virtual string getOfficePost(){ return this->officePost; }

        virtual void setSalary(float value){ this->salary = value; }
        virtual float getSalary(){ return this->salary; }

        virtual void setArea(string value){ this->area = value; }
        virtual string getArea(){ return this->area; }

        virtual void setFormation(string value){ this->formation = value; }
        virtual string getFormation(){ return this->formation; }
        
        virtual void setAcademy(string value){ this->academy = value; }
        virtual string getAcademy(){ return this->academy; }
        

        
        virtual void CreatePersonMenu(int step) = 0;

};