#include <iostream>

struct Node {
    // initializing the string values for the nodes
    std::string lastName, firstName, insuranceType, address, dateVisited, SSN;

    // next pointer
    struct Node *next;

    //global variables
}*front = NULL, *rear = NULL, *current = NULL;


void enqueue(std::string lname, std::string fname, std::string ins, std::string adrs, std::string dvisit, std::string soc){
    // creating new node when pushing node
    struct Node *t = new Node();
    // checks to see if there's enough space in memory
    if(t==NULL){
        std::cout << "Queue is full, sorry.\n";
    } else {
        // assigns parameters to data members
        t->lastName = lname;
        t->firstName = fname;
        t->insuranceType = ins;
        t->address = adrs;
        t->dateVisited = dvisit;
        t->SSN = soc;
        t->next = NULL;
        // if front variable is NULL
        if(front == NULL){
            // making front, rear and current set to new node
            front = rear = current = t;
        } else {
            // these two lines add the new node to the end of the queue
            rear->next = t;
            rear = current = t;
        }
    }
}

int dequeue(){
    // returns -1 if there is nothing to dequeue
    int x = -1;
    // creates a temp node for deleting node
    struct Node *temp;
    if(front == NULL){
        std::cout << "The queue is empty" << std::endl;
        // checks if current node is equal to front node
    } else if(current == front) {
        // increment current variable one
        current++;
        // gives values from front to temp
        temp = front;

        //moves front variable to the next of front
        front = front->next;
        // deletes newly made variable, essentially getting rid of previous element
        delete temp;
    } else {

        // gives values form front to temp
        temp = front;
        // moves front variable to the next of front
        front = front->next;

        // deletes newly variable, essentially getting rid of previous element
        delete temp;
    }
    return x;
}

void display(){
    // front global variable is set to *p
    struct Node *p = front;
    while(p!=NULL){
        std::cout <<
        "\nLast name: " << p->lastName <<
        "\nFirst name: " << p->firstName <<
        "\nInsurance type: " << p->insuranceType <<
        "\nAddress: " << p->address <<
        "\nDate Visited: " << p->dateVisited <<
        "\nSocial Security Number: " << p->SSN << std::endl;
        // moves p to next value in queue
        p = p->next;
    }
    std::cout << "\n---------------------------\n";
}

// method to move current pointer to next patient
void nextPatient(){
    if(current != rear){
            //moves current pointer towards the front
        current--;
    } else {
        std::cout << "We are viewing the last patient" << std::endl;
    }
}

// method to count total patients recursively
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
