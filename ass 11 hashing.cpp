#include<iostream> 
#include<cstring> 
using namespace std; 
 
struct Employee 
{ 
    int id; 
    string name; 
    int key; 
}; 
class HashTable 
{ 
    int list_size; 
    Employee Table[10]; 
public: 
    HashTable(){ 
        for(int i=0;i<10;i++) 
{ 
            Table[i].key=-1; 
            Table[i].name=""; 
            Table[i].id = -1; 
        } 
    } 
    int hashValue(int id) 
{ 
        return(id%10); 
    } 
    void insertRecord(int id, string name) 
{ 
        int index = hashValue(id); 
        int c = index; 
 
        while(Table[index].key != -1) 
{ 
            index= (index+1)%10; 
            if(c==index) 
{ 
                cout<<"Hashtable is full"<<endl; 
                return; 
            } 
        } 
        Table[index].key = c; 
        Table[index].id = id; 
        Table[index].name = name; 
    } 
 
    void displayRecord(){ 
        for(int i=0;i<10;i++) 
        { 
        if(Table[i].id != -1) 
        { 
        cout<<"id: "<<Table[i].id<<" Name: "<<Table[i].name<<" key: "<<Table[i].key<<endl; 
} 
} 
    } 
}; 
 
int main() 
{ 
    int choice=0, EmpID = 0, wantMore=1; 
    char name[100]=""; 
    cout<<"Welcome to Employee Management System!"<<endl; 
    HashTable h; // Creating an object of HashTable class 
 
    while(wantMore==1){ 
    
    cout<<"1.Insert element into the table"<<endl; 
    cout<<"2.Search element from the key"<<endl; 
        cout<<"3.Delete element at a key"<<endl; 
      cout<<"4.Print the Total HashTable"<<endl; 
      cout<<"Enter your choice: "; 
      cin>>choice; 
 
            if(choice==1){ 
                printf("Enter the EmpID: "); 
                cin>>EmpID; 
                printf("Enter the Name: "); 
                cin>>name; 
 
                h.insertRecord(EmpID,name); // Method for inserting data in Hashtable 
            } 
            else if(choice==2){ 
                printf("Enter the EmpID: "); 
                cin>>EmpID; 
 
                //h.searchRecord(EmpID); 
            } 
            else if(choice==3){ 
                printf("Enter the EmpID: "); 
                cin>>EmpID; 
 
                //h.deleteRecord(EmpID); 
            } 
            else if(choice==4){ 
                h.displayRecord(); 
            } 
            else{ 
                printf("Enter a valid choice"); 
            } 
    printf("Do You want to continue? (1-for yes, 0 for no) "); 
    cin>>wantMore; 
} 
 
return 0; 
}