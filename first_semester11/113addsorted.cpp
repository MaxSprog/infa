#include <iostream>
#include <cstddef>

using namespace std;

template <class T>
class List{
    private:
        struct list {
            T data;
            struct list * next;
        };
        struct list *head;

    public:
        List(){
            head = new struct list;
            head = NULL;
        }
        ~List(){
            struct list* temp;
            while(head){
                temp = head;
                head = temp->next;
                delete[] temp;
            }
            delete[] head;
        }
        void makenull(){
            struct list *temp;
            while (head){
                temp = head;
                head = temp->next;
                delete[] temp;
            }
        }
        int length(){
            int cnt = 0;
            struct list *temp = head;
            while(temp){
                temp = temp->next;
                cnt++;
            }
            return cnt;
        }
        void print(){
            struct list *temp = head;
            while(temp){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        void deleteElement(T data){
            struct list *temp = head;
            if (temp->data == data){
                head = temp->next;
                delete[] temp;
                return;
            }
            while(temp->next->data != data && temp->next->next){
                temp = temp->next;
            }
            if(!temp->next)
                return;
            struct list *nxtemp = temp->next->next;
            delete[] temp->next;
            temp->next = nxtemp;
        }
        void addSorted(T data){
            if(!head){
                head = new struct list;
                head->data = data;
                head->next = NULL;
                return;
            }
            if(head->data == data){
                return;
            }
            if(!head->next && data > head->data){
                struct list *temp = new struct list;
                temp->data = data;
                temp->next = NULL;
                head->next = temp;
                return;
            }
            else if(!head->next || head->data > data){
                struct list *temp = new struct list;
                temp->data = data;
                temp->next = head;
                head = temp;
                return;
            }
            struct list *temp = head;
            while(temp->next){
                if(temp->next->data > data)
                    break;
                temp = temp->next;
            }
            if(data == temp->data){
                return;
            }
            struct list *p = new struct list;
            p->next = temp->next;
            p->data = data;
            temp->next = p;
        }
};

int main(){
    List<int> l;
    int p;
    for(;cin >> p;){
        l.addSorted(p);
    }
    l.print();
}