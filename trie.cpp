#include<bits/stdc++.h>

using namespace std;

struct Trie {

    struct Node {

        Node* child[26];
        bool is_word;

        Node(){
            memset(child, 0, sizeof(child));
            is_word = false;
        }
    };

    Node* root;
    char DEFAULT;

    Trie(){
      	root = new Node;
        DEFAULT = 'a';
    }

    ~Trie(){
        Delete_Trie(root);
        delete root;
    }

    void Delete_Trie(Node* curr){
        for(auto& new_node : curr -> child){
            if(new_node){
                Delete_Trie(new_node);
                delete new_node;
            }
        }
    }

    void insert(string& word){
		Node* curr = root;
		for(auto& c : word){
			if(!curr -> child[c - DEFAULT]) curr -> child[c - DEFAULT] = new Node;
			curr = curr -> child[c - DEFAULT];
		}
		curr -> is_word = true;
    }

    bool search(string& word){
		Node* curr = root;
		for(auto& c : word){
			if(!curr -> child[c - DEFAULT]) return false;
			curr = curr -> child[c - DEFAULT];
		}
		return curr -> is_word;
    }

    bool is_prefix(string& word){
        Node* curr = root;
		for(auto& c : word){
			if(!curr -> child[c - DEFAULT]) return false;
			curr = curr -> child[c - DEFAULT];
		}
		return true;
    }
};


int main()
{
    Trie hi;

    vector<string>s = {"hiiii","biiii"};
    for(auto x : s)
        hi.insert(x);
    //hi.insert("Hello");
    cout << "OK" << '\n';
    string ss = "hio";
    if(hi.is_prefix(ss)){
        cout << "Good" << '\n';
    }
    else cout << "NO" << '\n';

   return 0;
}

