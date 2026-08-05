// open hashing( seprate chaining )

#include <iostream>
using namespace std;
#include <vector>
template<typename newtype01, typename newtype02>


class my_unordered_map{    

private:    
int pairs_count=0;

struct node {
    newtype01 key;
    newtype02 value;
    struct node* next;
    
    node(newtype01 x,newtype02 y){
        key=x;
        value=y;
        next=nullptr; }};    

vector<node*> buckets{11, nullptr};


// hashcode   O(1)
size_t hashcode(const newtype01& key) {

    if constexpr (std::is_same_v<newtype01, int>) {                            // Case 1 int type

        size_t hash = key;                       //hashing
        hash ^=(hash >> 16);                  

        return hash % buckets.size();              //compression
    }
    else if constexpr (std::is_same_v<newtype01, std::string>) {               // Case 2  string type

        size_t hash = 0;                        
        for(char c : key)                        //hashing
            hash = hash * 31 + c;         

        return hash % buckets.size();              //compression
    }
    else {                                                                   // case 3
        cout << "This hashCode function is not valid for this datatype\n";
        return 0;
    }
}

// hashing O(n)
void hashing(vector<node*>& buckets){
    
     int oldBucketsSize = buckets.size();

     vector<node*> oldHeads(oldBucketsSize);
     for(int i = 0; i < oldBucketsSize; i++){
         oldHeads[i] = buckets[i];
         buckets[i] = nullptr;
     }
     
     buckets.resize(2 * oldBucketsSize);

     for(int i = 0; i < oldBucketsSize; i++) {

         node* current = oldHeads[i];

         while(current != nullptr) {

               node* NEXT = current->next;

               int newindex = hashcode(current->key);

               current->next = buckets[newindex];
               buckets[newindex] = current;

               current = NEXT;
         }
     }
}

public:

// searching  avg case:O(1) , worst case:O(n)  
bool search_pair(pair<newtype01,newtype02>p){

    int index= hashcode(p.first);
    node* CURRENT=buckets[index];

    while(CURRENT!=nullptr && CURRENT->key!=p.first )CURRENT=CURRENT->next;

    return CURRENT!=nullptr && CURRENT->key == p.first;
}

// insertion  avg case:O(1) , worst case:O(n)  
void insert_pair(pair<newtype01,newtype02>p){

    int index= hashcode(p.first);
    node*& head=buckets[index];

    if(head==nullptr){
        node* ptr = new node(p.first, p.second);
        ptr->next=nullptr;
        head=ptr;
        return;
    }
    
    node*CURRENT=head;
    while(CURRENT->key!=p.first && CURRENT->next!=nullptr )CURRENT=CURRENT->next;
    if(CURRENT->key==p.first)return;
       
    node* ptr = new node(p.first, p.second);
    CURRENT->next=ptr;
    pairs_count++;

    if(pairs_count > 0.7*buckets.size())hashing(buckets);
}    

// deletion   avg case:O(1) , worst case:O(n)  
void delete_pair(pair<newtype01,newtype02>p){
    
    int index= hashcode(p.first);
    node*& head=buckets[index];
    
    if(head==nullptr)return;
    if(head->key==p.first){ node*ptr=head; head=head->next; delete ptr; return; }

    node*CURRENT=head;
    node*NEXT=head->next;
    while(NEXT->key!=p.first && NEXT->next!=nullptr ){CURRENT=NEXT; NEXT=CURRENT->next;}
    if(NEXT->next==nullptr)return;
    CURRENT->next=NEXT->next;
    delete NEXT;   
}
};
          
int main() {

    my_unordered_map<int,int> mp;

    // 1. Search empty hashmap
    cout << mp.search_pair({10, 100}) << endl;   // expected: 0

    // 2. Insert first element
    mp.insert_pair({10, 100});
    cout << mp.search_pair({10, 100}) << endl;   // expected: 1

    // 3. Insert more elements
    mp.insert_pair({20, 200});
    mp.insert_pair({30, 300});
    mp.insert_pair({40, 400});

    // 4. Search existing elements
    cout << mp.search_pair({20, 200}) << endl;   // expected: 1
    cout << mp.search_pair({40, 400}) << endl;   // expected: 1

    // 5. Search non-existing element
    cout << mp.search_pair({99, 999}) << endl;   // expected: 0

    // 6. Try duplicate key
    mp.insert_pair({20, 999});
    cout << mp.search_pair({20, 999}) << endl;   // expected: 1
    cout << mp.search_pair({20, 200}) << endl;   // expected: 1

    // 7. Delete an element
    mp.delete_pair({20, 200});
    cout << mp.search_pair({20, 200}) << endl;   // expected: 0

    // 8. Delete first/head node
    mp.delete_pair({10, 100});
    cout << mp.search_pair({10, 100}) << endl;   // expected: 0

    // 9. Delete non-existing element
    mp.delete_pair({999, 999});

    // 10. Insert many elements to trigger rehashing
    for(int i = 50; i <= 100; i += 10) {
        mp.insert_pair({i, i * 10});
    }

    // 11. Check elements after rehash
    cout << mp.search_pair({50, 500}) << endl;   // expected: 1
    cout << mp.search_pair({80, 800}) << endl;   // expected: 1
    cout << mp.search_pair({100, 1000}) << endl; // expected: 1

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// close hashing(open addressing)

#include <iostream>
using namespace std;
#include <vector>

template<typename newtype01, typename newtype02>

class my_unordered_map{

private:    

int pairs_count=0;
struct node{
    newtype01 key;
    newtype02 value;
    bool occupied;
    bool deleted;

    node(){
         occupied= false;
         deleted= false;  
    }
}; 

vector<node>arr{11,node()};

// hashcode   O(1)

size_t hashcode(const newtype01& key) {

    if constexpr (std::is_same_v<newtype01, int>) {                            // Case 1 int type

        size_t hash = key;                       //hashing
        hash ^=(hash >> 16);                  

        return hash % arr.size();              //compression
    }
    else if constexpr (std::is_same_v<newtype01, std::string>) {               // Case 2  string type

        size_t hash = 0;                        
        for(char c : key)                        //hashing
            hash = hash * 31 + c;         

        return hash % arr.size();              //compression
    }
    else {                                                                   // case 3
        cout << "This hashCode function is not valid for this datatype\n";
        return 0;
    }
}

// hashing O(n)
void hashing(vector<node>& arr){
    int oldArrSize= arr.size();

    vector<node> oldElms(oldArrSize);
    for(int i = 0; i < oldArrSize; i++){
         oldElms[i] = arr[i];
         arr[i] =  node();
    }
     
    arr.resize(2 * oldArrSize);   
    for(int i = 0; i < oldArrSize; i++) {
         
         int loop_count=0;
         while(loop_count<oldArrSize){

              int newindex = (hashcode(oldElms[i].key)+loop_count)%arr.size();
              if(!arr[newindex].occupied ){
                arr[newindex] = oldElms[i];break;}
              loop_count++;    
         }     
    }     
}

public:
// searching  avg case:O(1) , worst case:O(n)  
bool search_pair(pair<newtype01,newtype02>p){

    int loop_count=0;
    while(loop_count<arr.size()){
                
        int index= (hashcode(p.first)+loop_count)%arr.size();

        if(!arr[index].occupied && !arr[index].deleted)return false;
        if(arr[index].occupied && p.first==arr[index].key)return true;
        loop_count++;        
    }
    return false;
}

// insertion  avg case:O(1) , worst case:O(n)  
void insert_pair(pair<newtype01,newtype02>p){
    
    for(int i=0;i<arr.size();i++){
        int index= (hashcode(p.first)+i)%arr.size();
        if(!arr[index].occupied && !arr[index].deleted)break;
        if(arr[index].occupied && p.first==arr[index].key)return;
    }

    int loop_count=0;
    while(loop_count<arr.size()){

      int index= (hashcode(p.first)+loop_count)%arr.size();

      if(!arr[index].occupied ){
         arr[index].key=p.first;
         arr[index].value=p.second;
         arr[index].occupied=true;
         arr[index].deleted=false;
         pairs_count++;break;}
      loop_count++;
    }        
    if(loop_count==arr.size() || pairs_count > 0.7*arr.size())hashing(arr);
}

// deletion   avg case:O(1) , worst case:O(n)  
void delete_pair(pair<newtype01,newtype02>p){
    
    int loop_count=0;
    while(loop_count!=arr.size()){
        
        int index= (hashcode(p.first)+loop_count)%arr.size();

        if(!arr[index].occupied && !arr[index].deleted)break;
        if(arr[index].occupied && p.first==arr[index].key){
           arr[index].occupied=false;
           arr[index].deleted=true;
           pairs_count--;break;}  
        loop_count++; 
    }
}

};

int main() {

    my_unordered_map<int,int> mp;

    // 1. Search empty hashmap
    cout << mp.search_pair({10, 100}) << endl;   // expected: 0

    // 2. Insert first element
    mp.insert_pair({10, 100});
    cout << mp.search_pair({10, 100}) << endl;   // expected: 1

    // 3. Insert more elements
    mp.insert_pair({20, 200});
    mp.insert_pair({30, 300});
    mp.insert_pair({40, 400});

    // 4. Search existing elements
    cout << mp.search_pair({20, 200}) << endl;   // expected: 1
    cout << mp.search_pair({40, 400}) << endl;   // expected: 1

    // 5. Search non-existing element
    cout << mp.search_pair({99, 999}) << endl;   // expected: 0

    // 6. Try duplicate key
    mp.insert_pair({20, 999});
    cout << mp.search_pair({20, 999}) << endl;   // expected: 1
    cout << mp.search_pair({20, 200}) << endl;   // expected: 1

    // 7. Delete an element
    mp.delete_pair({20, 200});
    cout << mp.search_pair({20, 200}) << endl;   // expected: 0

    // 8. Delete first/head node
    mp.delete_pair({10, 100});
    cout << mp.search_pair({10, 100}) << endl;   // expected: 0

    // 9. Delete non-existing element
    mp.delete_pair({999, 999});

    // 10. Insert many elements to trigger rehashing
    for(int i = 50; i <= 100; i += 10) {
        mp.insert_pair({i, i * 10});
    }

    // 11. Check elements after rehash
    cout << mp.search_pair({50, 500}) << endl;   // expected: 1
    cout << mp.search_pair({80, 800}) << endl;   // expected: 1
    cout << mp.search_pair({100, 1000}) << endl; // expected: 1

    return 0;
}