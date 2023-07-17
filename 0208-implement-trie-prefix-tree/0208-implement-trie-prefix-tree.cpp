struct Node{

	Node *links[26];
	bool flag=false;

	bool containsKey(char ch){
		return links[ch-'a']!=NULL;
	}
    
	void put(char ch,Node *node){
		links[ch-'a']=node;
	}
    
	Node *get(char ch){
		return links[ch-'a'];
	}
	void setEnd(){
		flag=true;
	}
	bool isEnd(){
		return flag;
	}
};

class Trie {

private: Node *root;

public:
	Trie() {
		root = new Node();
	}

	void insert(string word) {
		Node *node=root;
		for(int i=0;i<word.size();i++){
			if(!node->containsKey(word[i])){
				node->put(word[i],new Node());
			}
			node=node->get(word[i]); //get reference link of next node
		}
		node->setEnd(); //set that the word has ended using flag = true
	}

	bool search(string word) {
		Node *node=root;
		for(int i=0;i<word.size();i++){
			if(!node->containsKey(word[i])){
				return false;
			}
			node=node->get(word[i]); //move to next reference
		}
		return node->isEnd(); //returns true if flag is true and word length has ended
	}

	bool startsWith(string prefix) {
		Node *node=root;
		for(int i=0;i<prefix.size();i++){
			if(!node->containsKey(prefix[i])){
				return false;
			}
			node=node->get(prefix[i]);
		}
		return true; //returns true if word length has ended (no need to check flag)
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */