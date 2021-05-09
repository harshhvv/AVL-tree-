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
//#include <iostream>
using namespace std;
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
}

void adminInsert(employe x){
    //    int emp_id = 99;
    //    char name[MAX_NAME_LEN] = "harsh";
    //    char address[MAX_ADDRESS_LEN] = "home";
    //    int ph_number = 87640;
    //    char designation[MAx_DES_LEN] = "boss";
    //    float salary = 9;
    //    std::cout<<"enter employee id: ";
    //    //std::cin>>emp_id;
    //    //std::cout<<"\n";
    //
    //    std::cout<<"Enter name: ";
    //    //scanf("%[^\n]", name);
    //    std::cout<<"\n";
    //
    //    std::cout<< "Enter address: ";
    //    //scanf("%[^\n]", address);
    //    std::cout<<"\n";
    //
    //    std::cout<<"Enter phone number: ";
    //    //std::cin>>ph_number;
    //    std::cout<<"\n";
    //
    //    std::cout<<"enter designation: ";
    //    //scanf("%[^\n]", designation);
    //    std::cout<<"\n";
    //
    //    std::cout<<"enter salary: ";
    //    //std::cin>>salary;
    //    std::cout<<"\n";
    //
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
    printf("working");
}


void adminRemoveData(int emp_id) {
    //    int emp_id;
    //    std::cout<<"enter employee id pls: ";
    //    std::cin>>emp_id;
    //    int pos = 0;
    
    if(head==NULL) {
        printf("Linked List not initialized");
        return;
    }
    
    if(head->emp_id == emp_id) {
        if(head->next != NULL) {
            head = head->next;
            return;
        } else {
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
    } else
        
        std::cout<<emp_id<<" not found"<<std::endl;
    
}

void adminSearch(int emp_id)
{
    struct employe *ptr;
    int i=1,flag;
    int count = 0;
    ptr = head;
    if(ptr == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        
        while (ptr!=NULL)
        {
            if(ptr->emp_id == emp_id)
            {
                count++;
                //printf("item found at location %d ",i);
                //std::cout<<"\n";
                std::cout <<"RESULT\n"<<count<<") "<< "Employee id: " << ptr->emp_id << ", "<< "Name: "<<ptr->name<<", " << "address: " << ptr->address <<", "<<"phone number: " << ptr->ph_number << ", " << "designation: " << ptr->designation << ", " << "salary: " <<ptr->salary<<std::endl;
                std::cout<<"\n";
                //ptr = ptr->next;
                
                flag=0;
            }
            else
            {
                flag=1;
            }
            i++;
            ptr = ptr -> next;
        }
        //        if(flag==1)
        //        {
        //            printf("Item not found\n");
        //        }
        
    }
    
}

void adminSearch(std::string name)
{
    struct employe *ptr;
    int i=1,flag;
    int count = 0;
    ptr = head;
    if(ptr == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        
        while (ptr!=NULL)
        {
            if(ptr->name == name)
            {
                count++;
                //printf("item found at location %d ",i);
                //std::cout<<"\n";
                std::cout <<"RESULT\n"<<count<<") "<< "Employee id: " << ptr->emp_id << ", "<< "Name: "<<ptr->name<<", " << "address: " << ptr->address <<", "<<"phone number: " << ptr->ph_number << ", " << "designation: " << ptr->designation << ", " << "salary: " <<ptr->salary<<std::endl;
                std::cout<<"\n";
                //ptr = ptr->next;
                
                flag=0;
            }
            else
            {
                flag=1;
            }
            i++;
            ptr = ptr -> next;
        }
        //        if(flag==1)
        //        {
        //            printf("Item not found\n");
        //        }
        
    }
    
}


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
                //std::cout<<"sorry no such employee found :( "<<std::endl;
            }
            ptr = ptr -> next;
        }
        
    }
    std::cout<<"Contact of employee with employee id "<<empid<<" changed to "<<num<<std::endl;
    adminSearch(empid);
}


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
                //std::cout<<"sorry no such employee found :( "<<std::endl;
            }
            ptr = ptr -> next;
        }
        
    }
    std::cout<<"Contact of employee with employee id "<<empid<<" changed to "<<des<<std::endl;
    adminSearch(empid);
}


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
                //std::cout<<"sorry no such employee found :( "<<std::endl;
            }
            ptr = ptr -> next;
        }
        
    }
    std::cout<<"Contact of employee with employee id "<<empid<<" changed to "<<add<<std::endl;
    adminSearch(empid);
}


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
                //std::cout<<"sorry no such employee found :( "<<std::endl;
            }
            ptr = ptr -> next;
        }
        
    }
    std::cout<<"Contact of employee with employee id "<<empid<<" changed to "<<sal<<std::endl;
    adminSearch(empid);
}

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
                //std::cout<<"sorry no such employee found :( "<<std::endl;
            }
            ptr = ptr -> next;
        }
        
    }
    std::cout<<"Contact of employee with employee id "<<empId<<" changed to "<<name<<std::endl;
    adminSearch(empId);
}

void swap(employe *a, employe *b){
    employe temp = *a;
    *a = *b;
    *b = temp;
}

//function to form partitions of array
int partition (employe arr[], int low, int high){
    //low is the starting index. high is the ending index
    int pivot = arr[high].emp_id; //setting value of pivot = last element of the array
    int i = low - 1;
    for (int j = low; j<=high-1; j++) {
//        count++;
        if (arr[j].emp_id<=pivot)  {//current element smaller than or equal to pivot
            i++;
            swap(&arr[i], &arr[j]); //swapping the 2 numbers
        }
    }
    swap(&arr[i + 1], &arr[high]); //swapping (i+1)th and last element
    return i+1;
}

void quickSort(employe arr[], int low, int high){
    if(low<high){
        //p specifies at which location to perform partition
        int p = partition(arr, low, high);
        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }
}


int main() {
    
    employe a, b, c, d, e, f, g, h, i, j;
    employe array[array_len] = { a, b, c, d, e, f, g, h, i, j };
    int high = 1;
    int pivot = array[high].emp_id;
    char userType;
    char normalViewYorN;
    std::string password;
    //gets(password);
//    std::cout<<"enter: ";
//    std::getline(std::cin,password);
//    std::cout<<password;
    
    //    employe a, b, c, d, e, f, g, h, i, j;
    //    employe array[array_len] = { a, b, c, d, e, f, g, h, i, j };
    //    for (int i = 0; i<array_len; i++) {
    //        array[i].emp_id = 0;
    //        array[i].name = "-";
    //        array[i].ph_number = 0;
    //        array[i].designation = "-";
    //        array[i].salary = 0;
    //    }
    
    
    //    a.emp_id = 69;
    //    a.name = "Harsh";
    //    a.ph_number = 87640;
    //    a.designation = "boss";
    //    a.salary = 69000;
    //
    //    b.emp_id = 70;
    //    b.name = "Hello";
    //    b.ph_number = 3456;
    //    b.designation = "manager";
    //    b.salary = 1000;
    
    
    //    adminInsert(a);
    //    adminInsert(b);
    
    std::cout<<"Enter as admin or viewer? Enter a for admin and v for viewer: ";
    std::cin>>userType;
    
    
    switch (userType) {
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
        case 'a':
            std::cout<<"enter: ";
            std::getline(std::cin,password);
            if(password == "admin")
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
            std::cout<<"Enter option number only: ";
            std::cout<<"\n";
            int choice;
            std::cin>>choice;
            switch (choice) {
                case 1:{
                    char choice;
                    int counter = 1;
                    
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
                            //                            std::cout<<"More values? y|n ";std::cin>>choice;
                            counter++;
                        }
                        else if (choice == 'n'){
                            adminViewAll();
                            break;
                        }
                        
                    }
                    
                    break;}
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
    
    
    main();
    return 0;
    //    employe a;
    //    a.emp_id = 69;
    //    a.name = "Harsh";
    //    a.ph_number = 87640;
    //    a.designation = "boss";
    //    a.salary = 69000;
    //
    //    employe b;
    //    b.emp_id = 70;
    //    b.name = "Hello";
    //    b.ph_number = 3456;
    //    b.designation = "manager";
    //    b.salary = 1000;
    
    //    adminInsert(a);
    //    adminInsert(b);
    //    adminViewAll();
    //adminRemoveData(70);
    //adminViewAll();
    //int empSearch = 70;
    //std::string nameSearch = "Hello";
    //adminSearch(empSearch);
    //adminSearch(nameSearch);
    
    //adminEditContact(a,6969);
    //adminEditDesignation(b,"normal");
    //adminEditAddress(b,"ulsan");
    //adminEditSalary(b, 99);
    //adminEditName(b, "ok");
    
    
    //return 0;
}
