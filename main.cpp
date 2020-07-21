#include <iostream>

struct Node {
    std::string lastName, firstName, insuranceType, address, dateVisited, SSN;
    struct Node *next;
}*front = NULL, *rear = NULL, *current = NULL;


void enqueue(std::string lname, std::string fname, std::string ins, std::string adrs, std::string dvisit, std::string soc){
    struct Node *t = new Node();
    if(t==NULL){
        std::cout << "Queue is full, sorry.\n";
    } else {
        t->lastName = lname;
        t->firstName = fname;
        t->insuranceType = ins;
        t->address = adrs;
        t->dateVisited = dvisit;
        t->SSN = soc;
        t->next = NULL;
        if(front == NULL){
            front = rear = current = t;
        } else {
            rear->next = t;
            rear = current = t;
        }
    }
}

int dequeue(){
    int x = -1;
    struct Node *temp;
    if(front == NULL){
        std::cout << "The queue is empty" << std::endl;
    } else if(current == front) {
        current++;
        temp = front;
        front = front->next;
        delete temp;
    } else {
        temp = front;
        front = front->next;
        delete temp;
    }
    return x;
}

void display(){
    struct Node *p = front;
    while(p!=NULL){
        std::cout <<
        "\nLast name: " << p->lastName <<
        "\nFirst name: " << p->firstName <<
        "\nInsurance type: " << p->insuranceType <<
        "\nAddress: " << p->address <<
        "\nDate Visited: " << p->dateVisited <<
        "\nSocial Security Number: " << p->SSN << std::endl;
        p = p->next;
    }
    std::cout << "\n---------------------------\n";
}

void nextPatient(){
    if(current != rear){
        current--;
    } else {
        std::cout << "We are viewing the last patient" << std::endl;
    }
}

int countPatients(struct Node *p){
    if(p!=NULL){
        return countPatients(p->next) + 1;
    } else {
        return 0;
    }
}

int main() {
    std::string lname, fname, ins, adrs, dvisit, soc;
    int choice;
    do {
        std::cout << "Menu\n";
        std::cout << "1. Add Patient\n";
        std::cout << "2. Delete Patient\n";
        std::cout << "3. Display all patients\n";
        std::cout << "4. Next patient\n";
        std::cout << "5. Total patients\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        switch(choice)
        {
        case 1:
            std::cout << "\nEnter Patient Last name: ";
            std::cin >> lname;
            std::cout << "\nEnter Patient first name: ";
            std::cin >> fname;
            std::cout << "\nEnter Patient Insurance Type: ";
            std::cin >> ins;
            std::cout << "\nEnter Patient Address: ";
            std::cin >> adrs;
            std::cout << "\nEnter Patient Date visited: ";
            std::cin >> dvisit;
            std::cout << "\nEnter Patient Social SN: ";
            std::cin >> soc;
            enqueue(lname, fname, ins, adrs, dvisit, soc);
            break;
        case 2:
            std::cout << dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            nextPatient();
            break;
        case 5:
            countPatients(front);
            break;
        default:
            std::cout << "Enter a valid choice";
        }
    }while(choice<7);

  return 0;
}
