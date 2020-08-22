#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

SinglyLinkedListNode* assign(SinglyLinkedListNode* nodeToCheck) {
    if(nodeToCheck == NULL){
        return NULL;
    }
    else {
        return nodeToCheck;
    }
}

void printLinkedList(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* node = head;
    while(node) {
        cout << node->data << '\t';
        node = node->next;
    }
    cout << '\n';

}

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* temp;
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* other;
    // Decide the head
    if(head1->data <= head2->data) {
        temp = assign(head1);
        head = assign(head1);
        other = assign(head2);
    }
    else {
        temp = assign(head2);
        head = assign(head2);
        other= assign(head1);
    }
    while(true) {
        if(temp->next==NULL && other!=NULL){
            temp->next = assign(other);
            break;
        }
        else if(other == NULL){
            break;
        }
        else if(temp->next != NULL && (temp->next->data <= other->data)) {
            temp = assign(temp->next);
        } 
        else {
            SinglyLinkedListNode* temp1;
            temp1 = assign(other);
            other = assign(other->next);
            temp1->next = assign(temp->next);
            temp->next = assign(temp1);

        }
    }
    return head;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        SinglyLinkedList* llist1 = new SinglyLinkedList();

        int llist1_count;
        cin >> llist1_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist1_count; i++) {
            int llist1_item;
            cin >> llist1_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist1->insert_node(llist1_item);
        }
      
      	SinglyLinkedList* llist2 = new SinglyLinkedList();

        int llist2_count;
        cin >> llist2_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist2_count; i++) {
            int llist2_item;
            cin >> llist2_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist2->insert_node(llist2_item);
        }

        SinglyLinkedListNode* llist3 = mergeLists(llist1->head, llist2->head);

        print_singly_linked_list(llist3, " ", fout);
        fout << "\n";

        free_singly_linked_list(llist3);
    }

    fout.close();

    return 0;
}
