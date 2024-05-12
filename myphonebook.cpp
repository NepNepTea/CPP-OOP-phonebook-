#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

class contact {
    private:
    public:
        string lname;
        string fname;
        string phone;
        void show(){
            cout<<". "<<lname<<" "<<fname<<": "<<phone<<endl;
        }
        void add_lname(){
            string x;
            cout<<"enter last name"<<endl;
            cin>>x;
            lname=x;
        }
        void add_fname(){
            string x;
            cout<<"enter name"<<endl;
            cin>>x;
            fname=x;
        }
        void add_phone(){
            string x;
            cout<<"enter phone number"<<endl;
            cin>>x;
            phone=x;
        }
        void erase(){
            phone="";
            lname="";
            fname="";
        }
};

int main()
{
    cout<<"My cool UwU phonebook   ver 1.0";
    int temp_id, choise;
    string arc, sus, for_last;
    ifstream neco("book.txt");
    getline(neco, arc);
	neco.close();
		
	vector <string> words;
	stringstream s(arc);	
	string intermediate;
	while(getline(s, intermediate, ' '))
	{
		words.push_back(intermediate);
	}

    const int n = 100; //max number of contacts
    ifstream amogus("numb.txt");
    getline(amogus, sus);
    amogus.close();
    int n_phones = stoi(sus);
    contact person[n];
    string myText;
    int work=1;
    int for_change;

    for(int i=0, y=0; i<n_phones; i++){
        person[i].lname=words[y];
        person[i].fname=words[y+1];
        person[i].phone=words[y+2];
        y=y+3;
    }

    while (work!=0){
        cout<<endl;
        cout<<"Select an action:"<<endl;
        cout<<"1: change contact"<<endl;
        cout<<"2: close program"<<endl;
        cout<<"3: show all contacts"<<endl;
        cout<<"4: delete contact"<<endl;
        cout<<"5: add contact"<<endl;
        cout<<"6: search by last name"<<endl;
        while(!(cin>>choise)) {
            cin.clear();
            cin.ignore(1000, '\n');
        }
        if (choise==2){
            work=0;
        }
        else if (choise==3){
            for (int i = 0; i<n_phones; i++){
                cout<<i;
                person[i].show();
            }
        }
        else if (choise==1){
            cout<<"Enter ID"<<endl;
            while(!(cin>>temp_id)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout<<"Enter valid ID"<<endl;
            }
            cout<<"select what you want to change"<<endl;
            cout<<"1: last name"<<endl;
            cout<<"2: name"<<endl;
            cout<<"3: phone number"<<endl;
            cout<<"another: cancel operation"<<endl;
            while(!(cin>>for_change)) {
                cin.clear();
                cin.ignore(1000, '\n');
            }
            switch (for_change){
                case 1:
                    person[temp_id].add_lname();
                    break;
                case 2:
                    person[temp_id].add_fname();
                    break;
                case 3:
                    person[temp_id].add_phone();
                    break;
                default:
                    break;
            }
            ofstream neco("book.txt");
            for (int i = 0; i<n_phones; i++){
                neco<<person[i].lname<<" "<<person[i].fname<<" "<<person[i].phone<<" ";
            }
            neco.close();
        }
        else if (choise==4){
            if (n_phones>0) {
                cout<<"enter ID"<<endl;
                while(!(cin>>temp_id)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout<<"Enter valid ID"<<endl;
                }
                person[temp_id].erase();
                for (int i=0; i<(n-temp_id); i++){
                    swap(person[temp_id], person[temp_id+1]);}
                n_phones=n_phones-1;
                ofstream amogus("numb.txt");
                amogus<<n_phones;
                amogus.close();
                ofstream neco("book.txt");
                for (int i = 0; i<n_phones; i++){
                    neco<<person[i].lname<<" "<<person[i].fname<<" "<<person[i].phone<<" ";
                }
                neco.close();
            }
            else {
                cout<<"Phonebook is empty"<<endl;
            }
        }
        else if (choise==5){
            person[n_phones].add_lname();
            person[n_phones].add_fname();
            person[n_phones].add_phone();
            
            n_phones=n_phones+1;
            ofstream amogus("numb.txt");
            amogus<<n_phones;
            amogus.close();
            ofstream neco("book.txt");
            for (int i = 0; i<n_phones; i++){
                neco<<person[i].lname<<" "<<person[i].fname<<" "<<person[i].phone<<" ";
            }
            neco.close();
        }
        else if (choise==6){
            cout<<"enter last name"<<endl;
            cin>>for_last;
            for (int i = 0; i<n_phones; i++){
                if (person[i].lname==for_last){
                    cout<<i;
                    person[i].show();
                }
            }
        }
        else {
            cout<<"This action does not exist";
        }
    }
    return 0;
}