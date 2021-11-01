#include <iostream>
using namespace std;

class List{
    private:
        typedef struct lst{
            int data = 0;
            struct lst* prev = NULL;
            struct lst* next = NULL;
            bool is_end = true;
        }list;
        list* head;
        list* create(int data, list* next=NULL, list* prev=NULL, bool is_end=true){
            list* nod = new list;
            nod->data = data;
            if(!next)
                nod->next = nod;
            else
                nod->next = next;
            if(!prev)
                nod->prev = nod;
            else
                nod->prev = prev;
            nod->is_end = is_end;
            return nod;
        }
    public:
        List(){
            head = NULL;
        }
        ~List(){
            list* temp;
            while(!head->is_end){
                temp = head;
                head = head->next;
                delete[] temp;
            }
            delete[] head;
        }
        void print(){
            if(!head)
                return;
            list* temp = head;
            while(!temp->is_end){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << temp->data << endl;
        }
        int length(){
            if(!head)
                return 0;
            int n;
            list* temp = head;
            for(n = 1; !temp->is_end; n++){
                temp = temp->next;
            }
            return n;
        }
        void push(int a){
            if(!head){
                head = create(a, head, head, true);
                return;
            }
            list* temp = create(a, head, head->prev, true);
            temp->prev->next = temp;
            temp->prev->is_end = false;
            head->prev = temp;
        }
        void deleteEveryK(int k){
            list* temp = head;
            for(int i = 1; temp->next != temp; i++){
                if(i == k){
                    list* buf = temp;
                    temp = temp->next;
                    buf->next->prev = buf->prev;
                    buf->prev->next = buf->next;
                    if(buf == head){
                        head = temp;
                    }
                    else{
                        buf->prev->is_end = buf->is_end;
                    }
                    delete[] buf;
                    i = 0;
                }
                else{
                    temp = temp->next;
                }
            }
        }
};

int main() {
    List l;
    int N, k;
    cin >> N >> k;
    for(int i = 1; i <= N; i++){
        l.push(i);
    }
    l.deleteEveryK(k);
    l.print();
}