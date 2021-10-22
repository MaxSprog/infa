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
        void insert(T data, int ind){//-1 --- в конец списка
            int n = length();
            if(ind > n){
                ind = n;
            }
            if(ind < 0 || !head){
                if(ind == -1 && head){
                    ind = n;
                }
                else{
                    ind = 0;
                }
            }
            if(ind < n || !n){
                if(ind == 0){
                    struct list *h = new struct list;
                    h->data = data;
                    h->next = head;
                    head = h;
                    return;
                }
                else{
                    struct list *temp, *lt, *rt;
                    rt = head;
                    for (int i = 0; i < ind; i++){
                        lt=rt;
                        rt=rt->next;
                    }
                    temp = new struct list;
                    temp->data = data;
                    lt->next = temp;
                    lt = temp;
                    lt->next = rt;
                    return;
                }
            }
            struct list *temp = head;
            struct list *h = new struct list;
            
            h->data = data;
            h->next = NULL;
            for(int i = 0; i < ind && temp->next; i++)
                temp = temp->next;
            temp->next = h;
        }
        int countNEAT7(){
            struct list* temp = head;
            int cnt = 0;
            while(temp){
                try{
                    if(temp->data < 0){
                        if(-1 * temp->data % 7 == 0){
                            cnt++;
                        }
                    }
                }
                catch(...){
                    return 0;
                }
                temp = temp->next;
            }
            return cnt;
        }
};

int main(){
    List<int> l;
    int p;
    for(;cin >> p;){
        l.insert(p, 0);
    }
    cout << l.countNEAT7();
}