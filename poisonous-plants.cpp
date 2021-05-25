#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
class SinglyLinkedListNode {
    public:
        int data;
        bool alive;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->alive = true;
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


SinglyLinkedListNode* delete_dead_nodes(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* node = head;
    while(node->next){
        if(!node->next->alive){
            SinglyLinkedListNode* temp = node->next;
            node->next = node->next->next;
            free(temp); 
        } else {
            node= node->next;
        }
    }
    return head;
}
int prune(SinglyLinkedListNode* head) {

    SinglyLinkedListNode *ptr = head;
    int count = 0;
    while (ptr)
    {
        if(ptr->next && ptr->data < ptr->next->data) {
            ptr->next->alive=0;
            if(!count){
                count++;
            }
        }
        ptr=ptr->next;
    }
    if(count>0){
        head = delete_dead_nodes(head);
        count = (count + prune(head));
    }
    return count;
}
// Complete the poisonousPlants function below.
int poisonousPlants(vector<int> p) {
    SinglyLinkedList* llist = new SinglyLinkedList();
    for(long unsigned int i = 0; i < p.size(); i++){
        llist->insert_node(p[i]);
    }
    int count =  prune(llist->head);
    return count;

};

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string p_temp_temp;
    getline(cin, p_temp_temp);

    vector<string> p_temp = split_string(p_temp_temp);

    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        int p_item = stoi(p_temp[i]);

        p[i] = p_item;
    }

    int result = poisonousPlants(p);

    cout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
