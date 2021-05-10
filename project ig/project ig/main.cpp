//
//  main.cpp
//  project ig
//
//  Created by Harsh  on 07/05/21.
//

#define MAX_NAME_LEN 60  // Maximum len of your name can't be more than 60
#define MAX_ADDRESS_LEN 120  // Maximum len of your address can't be more than 120
#define MAX_ABOUT_LEN 250 // Maximum len of your profession can't be more than 250
#define MAx_DES_LEN 50
#define array_len 10

#include <string.h>
#include <iostream>

//using namespace std;
//creating a struct defining "employe"
struct employe{
    int emp_id;
    std::string name;
    //char name[MAX_NAME_LEN];
    //char gender;
    std::string address;
    //char address[MAX_ADDRESS_LEN];
    //    std::string address;
    int ph_number;
    std::string designation;
    //char designation[MAx_DES_LEN];
    float salary;
    employe* next;
};


employe *head = NULL;
employe *current = NULL;
employe *prevv = NULL;

//function to view all the details for ADMIN only
void adminViewAll(){
    int count = 0;
    employe *ptr = head;
    std::cout << "ALl data of all employees: "<<std::endl;    //start from the beginning
    while(ptr != NULL) {
        count++;
        //        std::cout<<"\t\t"<<"S.No"<<"\t\t"<<"Employee id"<<"\t\t"<<"Name"<<"\t\t"<<"address"<<"\t\t"<<"Phone number"<<"\t\t"<<"designation"<<"\t\t"<<"salary"<<std::endl;
        //
        //        std::cout<<"\t\t"<<count<<"\t\t"<<ptr->emp_id<<"\t\t"<<ptr->name<<"\t\t"<<ptr->address<<"\t\t"<<ptr->ph_number<<"\t\t"<<ptr->designation<<"\t\t"<<ptr->salary<<std::endl;
        
        std::cout << count << "). " << "Employee id: " << ptr->emp_id << ", "<< "Name: "<<ptr->name<<", " << "address: " << ptr->address <<", "<<"phone number: " << ptr->ph_number << ", " << "designation: " << ptr->designation << ", " << "salary: " <<ptr->salary<<std::endl;
        ptr = ptr->next;
    }
    printf(" End of entries");
    std::cout<<"\n";
    std::cout<<"\n";
}

//viewing details for a normal user,
///details show in this case are limited
void normalViewAll(){
    int count = 0;
    employe *ptr = head;
    std::cout << "Following entries were found: "<<std::endl;    //start from the beginning
    while(ptr != NULL) {
        count++;
        std::cout << count << "). " << "Employee id: " << ptr->emp_id << ", " <<"name: "<<ptr->name<<", "<<"phone number: " << ptr->ph_number << ", " << "designation: " << ptr->designation << std::endl;
        ptr = ptr->next;
    }
    printf(" End of entries");
    std::cout<<std::endl;
}

//function to add the details of a new employe
void adminInsert(employe x){
    employe *link = new employe();
    link->emp_id = x.emp_id;
    link->name = x.name;
    //strcpy(link->name, name);
    link->address = x.address;
    //strcpy(link->address, address);
    link->ph_number = x.ph_number;
    link->designation = x.designation;
    //strcpy(link->designation, designation);
    link->salary = x.salary;
    
    if(head==NULL) {
        head = link;
        return;
    }
    current = head;
    
    // move to the end of the list
    while(current->next!=NULL)
        current = current->next;
    
    // Insert link at the end of the list
    current->next = link;
    //printf("working");
}

//function to remove details of an employe, can be accessed by admin only
void adminRemoveData(int emp_id) {
    if(head==NULL) {
        printf("Linked List not initialized");
        return;
    }
    if(head->emp_id == emp_id) {
        if(head->next != NULL) {
            head = head->next;
            return;
        }
        else {
            head = NULL;
            printf("List is empty now");
            return;
        }
    } else if(head->emp_id != emp_id && head->next == NULL) {
        std::cout<<emp_id<<" not found"<<std::endl;
        return;
    }
    //prev = head;
    current = head;
    while(current->next != NULL && current->emp_id != emp_id) {
        prevv = current;
        current = current->next;
    }
    if(current->emp_id == emp_id) {
        prevv->next = prevv->next->next;
        free(current);
    }
    else{
        std::cout<<emp_id<<" not found"<<std::endl;
    }
}

//searching function using emp_id of an employe, for admin only
void adminSearch(int emp_id)
{
    struct employe *ptr;
    int i=1;//,flag;
    int count = 0;
    ptr = head;
    if(ptr == NULL){
        printf("Empty List\n");
    }
    else{
        while (ptr!=NULL){
            if(ptr->emp_id == emp_id){
                count++;
                std::cout <<"RESULT\n"<<count<<") "<< "Employee id: " << ptr->emp_id << ", "<< "Name: "<<ptr->name<<", " << "address: " << ptr->address <<", "<<"phone number: " << ptr->ph_number << ", " << "designation: " << ptr->designation << ", " << "salary: " <<ptr->salary<<std::endl;
                
                std::cout<<"\n";
                //ptr = ptr->next;
//                flag=0;
            }
            else{
                std::cout<<"No such record found. "<<std::endl;
            }
            i++;
            ptr = ptr -> next;
        }
    }
}

//overloaded searching function using name, for admin only
void adminSearch(std::string name)
{
    struct employe *ptr;
    int i=1;//,flag;
    int count = 0;
    ptr = head;
    if(ptr == NULL){
        printf("Empty List\n");
    }
    else{
        while (ptr!=NULL){
            if(ptr->name == name)
            {
                count++;
                std::cout <<"RESULT\n"<<count<<") "<< "Employee id: " << ptr->emp_id << ", "<< "Name: "<<ptr->name<<", " << "address: " << ptr->address <<", "<<"phone number: " << ptr->ph_number << ", " << "designation: " << ptr->designation << ", " << "salary: " <<ptr->salary<<std::endl;
                std::cout<<"\n";
                //ptr = ptr->next;
                //flag=0;
            }
            else{
                std::cout<<"No such record found. "<<std::endl;
            }
            i++;
            ptr = ptr -> next;
        }
    }
}

//function to edit the contact number/phone number of an employe, by an admin only
void adminEditContact(int empid,int num) {
    //int emp_id;
    std::cout<<"following details were found: "<<std::endl;
    adminSearch(empid);
    
    employe *ptr;
    ptr = head;
    if(ptr == NULL){
        printf("Empty List\n");
    }
    else{
        while (ptr!=NULL){
            if(ptr->emp_id == empid){
                ptr->ph_number = num;
                std::cout<<"\n";
            }
            else{
                std::cout<<"sorry no such employee found :( "<<std::endl;
            }
            ptr = ptr -> next;
        }
    }
    std::cout<<"Contact of employee with employee id "<<empid<<" changed to "<<num<<std::endl;
    adminSearch(empid);
}

//function to edit the designation of an employe, by an admin only
void adminEditDesignation(int empid, std::string des) {
    //int emp_id;
    std::cout<<"following details were found: "<<std::endl;
    adminSearch(empid);
    
    employe *ptr;
    ptr = head;
    if(ptr == NULL){
        printf("Empty List\n");
    }
    else{
        while (ptr!=NULL){
            if(ptr->emp_id == empid){
                ptr->designation = des;
                std::cout<<"\n";
            }
            else{
                std::cout<<"sorry no such employee found :( "<<std::endl;
            }
            ptr = ptr -> next;
        }
    }
    std::cout<<"Contact of employee with employee id "<<empid<<" changed to "<<des<<std::endl;
    adminSearch(empid);
}

//function to edit the address of an employe, by an admin only
void adminEditAddress(int empid, std::string add){
    //int emp_id;
    std::cout<<"following details were found: "<<std::endl;
    adminSearch(empid);
    
    employe *ptr;
    ptr = head;
    if(ptr == NULL){
        printf("Empty List\n");
    }
    else{
        while (ptr!=NULL){
            if(ptr->emp_id == empid){
                ptr->address = add;
                std::cout<<"\n";
            }
            else{
                std::cout<<"sorry no such employee found :( "<<std::endl;
            }
            ptr = ptr -> next;
        }
    }
    std::cout<<"Contact of employee with employee id "<<empid<<" changed to "<<add<<std::endl;
    adminSearch(empid);
}

//function to edit the salary of an employe, by an admin only
void adminEditSalary(int empid, int sal){
    //int emp_id;
    std::cout<<"following details were found: "<<std::endl;
    adminSearch(empid);
    
    employe *ptr;
    ptr = head;
    if(ptr == NULL){
        printf("Empty List\n");
    }
    else{
        while (ptr!=NULL){
            if(ptr->emp_id == empid){
                ptr->salary = sal;
                std::cout<<"\n";
            }
            else{
                std::cout<<"sorry no such employee found :( "<<std::endl;
            }
            ptr = ptr -> next;
        }
    }
    std::cout<<"Contact of employee with employee id "<<empid<<" changed to "<<sal<<std::endl;
    adminSearch(empid);
}

//function to edit the name of an employe, by an admin only
void adminEditName(int empId, std::string name){
    //int emp_id;
    std::cout<<"following details were found: "<<std::endl;
    adminSearch(empId);
    
    employe *ptr;
    ptr = head;
    if(ptr == NULL){
        printf("Empty List\n");
    }
    else{
        while (ptr!=NULL){
            if(ptr->emp_id == empId){
                ptr->name = name;
                std::cout<<"\n";
            }
            else{
                std::cout<<"sorry no such employee found :( "<<std::endl;
            }
            ptr = ptr -> next;
        }
    }
    std::cout<<"Contact of employee with employee id "<<empId<<" changed to "<<name<<std::endl;
    adminSearch(empId);
}


int main() {
    //declaring 10 variables of type employe and assigning them to an array of type employe
    employe a, b, c, d, e, f, g, h, i, j;
    employe array[array_len] = { a, b, c, d, e, f, g, h, i, j };
//    int high = 1;
//    int pivot = array[high].emp_id;
    char userType;
    char normalViewYorN;
    std::string password;
    
    do{
        //user type is either admin or viewer stored in variable userType
        std::cout<<"Enter as admin or viewer? Enter a for admin and v for viewer: ";
        std::cin>>userType;
        
        switch (userType) {
            //the user is of type viewer
            case 'v':
                std::cout<<"View details available? y|n: ";
                std::cin>>normalViewYorN;
                switch (normalViewYorN) {
                    case 'y':
                        normalViewAll();
                        break;
                    case 'n':
                        std::cout<<"ok";
                    default: std::cout<<"please enter a valid choice "<<std::endl;
                        break;
                }
                break;
            //the user is of type admin
            case 'a':
                
                if(password == "admin"){std::cin>>password;}
                    std::cout<<"Following functions are available: "<<std::endl;
                std::cout<<"1). Add data of new employee. "<<std::endl;
                std::cout<<"2). View all details. "<<std::endl;
                std::cout<<"3). View details, search using name. "<<std::endl;
                std::cout<<"4). View details, search using employee id. "<<std::endl;
                std::cout<<"5). Delete the data of an employee. "<<std::endl;
                std::cout<<"6). Edit name of an employee. "<<std::endl;
                std::cout<<"7). Edit contact number of an employee. "<<std::endl;
                std::cout<<"8). Edit designation of an employee. "<<std::endl;
                std::cout<<"9). Edit salary of an employee. "<<std::endl;
                std::cout<<"\n";
                std::cout<<"Enter option number only: ";
                //std::cout<<"\n";
                int choice;
                std::cin>>choice;
                switch (choice) {
                    case 1:{
                        char choice;
                        int counter = 1;
                        std::cout<<"\n";
                        std::cout<<"Pls enter the following values: " <<std::endl;
                        std::cout<<"enter employee id: "; std::cin>>a.emp_id;
                        std::cout<<"enter name: "; std::cin>>a.name;
                        std::cout<<"enter address: "; std::cin>>a.address;
                        std::cout<<"enter phone number: "; std::cin>>a.ph_number;
                        std::cout<<"enter designation: "; std::cin>>a.designation;
                        std::cout<<"enter salary: "; std::cin>>a.salary;
                        adminInsert(a);
                        
            
                        for (counter = 1; counter<array_len; counter++) {
                            std::cout<<"More values? y|n ";std::cin>>choice;
                            std::cout<<std::endl;
                            if (choice == 'y') {
                                std::cout<<"Pls enter the following values: " <<std::endl;
                                std::cout<<"enter employee id: "; std::cin>>array[counter].emp_id;
                                std::cout<<"enter name: "; std::cin>>array[counter].name;
                                std::cout<<"enter address: "; std::cin>>array[counter].address;
                                std::cout<<"enter phone number: "; std::cin>>array[counter].ph_number;
                                std::cout<<"enter designation: "; std::cin>>array[counter].designation;
                                std::cout<<"enter salary: "; std::cin>>array[counter].salary;
                                adminInsert(array[counter]);
                                std::cout<<"More values? y|n ";std::cin>>choice;
                                counter++;
                            }
                            else if (choice == 'n'){
                                adminViewAll();
                                break;
                            }
                        }
                        break;
                    }
                    case 2:
                        adminViewAll();
                        break;
                    case 3:
                    {
                        std::string nameQuery;
                        std::cout<<"\n";
                        std::cout<<"enter name you'd like to search for: ";
                        std::cin>>nameQuery;
                        adminSearch(nameQuery);
                    }
                        break;
                    case 4:
                    {
                        int empQuery;
                        std::cout<<"\n";
                        std::cout<<"enter employee id you'd like to search for: ";
                        std::cin>>empQuery;
                        adminSearch(empQuery);
                    }
                        break;
                    case 5:
                    {
                        int empid;
                        std::cout<<"\n";
                        std::cout<<"enter employee id you'd like to delete: ";
                        std::cin>>empid;
                        adminRemoveData(empid);
                        adminViewAll();
                    }
                        break;
                    case 6:
                    {
                        int empid;
                        std::string name;
                        std::cout<<"\n";
                        std::cout<<"enter employee id whose name you'd like to change: ";
                        std::cin>>empid;
                        std::cout<<"emter new name: "; std::cin>>name;
                        adminEditName(empid, name);
                        adminViewAll();
                    }
                        break;
                    case 7:
                    {
                        int empid;
                        int contact;
                        std::cout<<"\n";
                        std::cout<<"enter employee id whose contact you'd like to change: ";
                        std::cin>>empid;
                        std::cout<<"emter new contact number: "; std::cin>>contact;
                        adminEditContact(empid, contact);
                        adminViewAll();
                    }
                        break;
                    case 8:
                    {
                        int empid;
                        std::string des;
                        std::cout<<"\n";
                        std::cout<<"enter employee id whose designation you'd like to change: ";
                        std::cin>>empid;
                        std::cout<<"emter new designation: "; std::cin>>des;
                        adminEditDesignation(empid, des);
                        adminViewAll();
                    }
                        break;
                    case 9:
                    {
                        int empid;
                        int salary;
                        std::cout<<"\n";
                        std::cout<<"enter employee id whose salary you'd like to change: ";
                        std::cin>>empid;
                        std::cout<<"emter new salary: "; std::cin>>salary;
                        adminEditSalary(empid, salary);
                        adminViewAll();
                    }
                        break;
                    default: std::cout<<"Invalid choice, program exited. "<<std::endl;
                    break;
                }
                
            
                
                break;
            default:
                std::cout<<"Invalid choice, program exited. " <<std::endl;
                break;
        }
    }
    while (true);
    return 0;
}
