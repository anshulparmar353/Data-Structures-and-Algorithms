#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

class Hashing{

    vector<list<int>> hashtable;
    int buckets;
public:
    Hashing(int size){
        buckets = size;
        hashtable.resize(size);
    }

    int hashvalue(int key){
        return key % buckets; // division method
    }

    void add(int key){
        int idx = hashvalue(key);
        hashtable[idx].push_back(key);
    }

    list<int>::iterator search(int key){
        int idx = hashvalue(key);
        return find(hashtable[idx].begin(),hashtable[idx].end(),key);
    }

    void deletekey(int key){
        int idx = hashvalue(key);
        if(search(key)!=hashtable[idx].end()){
            hashtable[idx].erase(search(key));
            cout<<key <<" is deleted"<<endl;
        }else{
            cout<<"The key is not present in the hashtable"<<endl;
        }
    }

    void traverse(){
        cout << "Elements in the hash table: " << endl;
        for(int i = 0; i < buckets; ++i){
            cout << "Bucket " << i << ": ";
            for(auto key : hashtable[i]){
                cout << key << " ";
            }
            cout << endl;
        }
    }

};
                    
int main(){

    Hashing h1(5);
    h1.add(2);
    h1.add(11);
    h1.add(7);
    h1.add(4);

    h1.deletekey(7);

    h1.traverse();
    
    return 0;
}