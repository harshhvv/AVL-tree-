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

#include <string.h>
#include <iostream>
//using namespace std;
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
employe *prev = NULL;

void adminViewAll(){
    int count = 0;
    employe *ptr = head;
    std::cout << "ALl data of all employees: "<<std::endl;    //start from the beginning
    while(ptr != NULL) {
        count++;
        std::cout << count << "). " << "Employee id: " << ptr->emp_id << ", "<< "Name: "<<ptr->name<<", " << "address: " << ptr->address <<", "<<"phone number: " << ptr->ph_number << ", " << "designation: " << ptr->designation << ", " << "salary: " <<ptr->salary<<std::endl;
        ptr = ptr->next;
    }
    printf(" End of entries");
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

void adminInsert(int emp_id, char name[MAX_NAME_LEN], char address[MAX_ADDRESS_LEN], int ph_number, char designation[MAx_DES_LEN], float salary){
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
    link->emp_id = emp_id;
    link->name = name;
    //strcpy(link->name, name);
    link->address = address;
    //strcpy(link->address, address);
    link->ph_number = ph_number;
    link->designation = designation;
    //strcpy(link->designation, designation);
    link->salary = salary;
    
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
}


void adminRemoveData() {
    int emp_id;
    std::cout<<"enter employee id pls: ";
    std::cin>>emp_id;
    int pos = 0;
    
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
        prev = current;
        current = current->next;
    }
    
    if(current->emp_id == emp_id) {
        prev->next = prev->next->next;
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


void adminEditContact(int num) {
    int emp_id;
    std::cout<<"\n";
    std::cout<<"whose contact would u like to edit? ";
    std::cin>>emp_id;
    std::cout<<"following details were found: "<<std::endl;
    adminSearch(emp_id);
   int pos = 0;
   
   if(head==NULL) {
      printf("Linked List not initialized");
      return;
   }

   current = head;
   while(current->next!=NULL) {
      if(current->emp_id == emp_id) {
         current->ph_number = num;
         //printf("\n%d found at position %d, replaced with %d\n", old, pos, new);
          std::cout<<"contact number updated :) "<<std::endl;
          adminSearch(emp_id);
         return;
      }
      
      current = current->next;
      pos++;
   }
   
    std::cout<<"something happened :'( ";
}


void adminEditDesignation(std::string old, std::string num) {
    int emp_id;
    std::cout<<"\n";
    std::cout<<"whose designation would u like to edit? ";
    std::cin>>emp_id;
    std::cout<<"following details were found: "<<std::endl;
    adminSearch(emp_id);
   int pos = 0;
   
   if(head==NULL) {
      printf("Linked List not initialized");
      return;
   }

   current = head;
   while(current->next!=NULL) {
      if(current->designation == old) {
         current->designation = num;
         //printf("\n%d found at position %d, replaced with %d\n", old, pos, new);
          std::cout<<"designation updated :) "<<std::endl;
          adminSearch(emp_id);
         return;
      }
      
      current = current->next;
      pos++;
   }
   
    std::cout<<"something happened :'( ";
}



int main(int argc, const char * argv[]) {
    adminInsert(69, "Harsh", "jaipur", 87640, "boss", 69000);
    adminInsert(70, "Hello", "kashmir", 3456, "manager", 1000);
    adminViewAll();
    //    adminRemoveData();
    //    adminViewAll();
    int empSearch = 70;
    std::string nameSearch = "hello";
    adminSearch(empSearch);
    adminSearch(nameSearch);
    
    adminEditContact(6969);
    //adminEditDesignation("manager", "normal");
    
    
    return 0;
}
