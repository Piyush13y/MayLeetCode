/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/
//referred from geeksforgeeks

#define CHAR_SIZE 128

class Trie {
public:
    bool isLeaf;
    Trie* character[CHAR_SIZE];
    Trie() {
        this->isLeaf = false;

		for (int i = 0; i < CHAR_SIZE; i++)
			this->character[i] = nullptr;
    }
    
    void insert(string key) {
	Trie* curr = this;
	for (int i = 0; i < key.length(); i++)
	{
		if (curr->character[key[i]] == nullptr)
			curr->character[key[i]] = new Trie();

		curr = curr->character[key[i]];
	}
	curr->isLeaf = true;
    }
    
    bool search(string key) {
	if (this == nullptr)
		return false;

	Trie* curr = this;
	for (int i = 0; i < key.length(); i++)
	{
		curr = curr->character[key[i]];
		if (curr == nullptr)
			return false;
	}
	return curr->isLeaf;
    }
    
    bool startsWith(string key) {
	Trie* curr = this;
	for (int i = 0; i < key.length(); i++)
	{
		curr = curr->character[key[i]];
		if (curr == nullptr)
			return false;
	}
	return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
