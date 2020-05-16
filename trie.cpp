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

#define CHAR_SIZE 128

class Trie {
public:
    bool isLeaf;
	Trie* character[CHAR_SIZE];
    /** Initialize your data structure here. */
    Trie() {
        this->isLeaf = false;

		for (int i = 0; i < CHAR_SIZE; i++)
			this->character[i] = nullptr;
    }
    
    /** Inserts a word into the trie. */
    void insert(string key) {
        // start from root node
	Trie* curr = this;
	for (int i = 0; i < key.length(); i++)
	{
		// create a new node if path doesn't exists
		if (curr->character[key[i]] == nullptr)
			curr->character[key[i]] = new Trie();

		// go to next node
		curr = curr->character[key[i]];
	}

	// mark current node as leaf
	curr->isLeaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string key) {
        // return false if Trie is empty
	if (this == nullptr)
		return false;

	Trie* curr = this;
	for (int i = 0; i < key.length(); i++)
	{
		// go to next node
		curr = curr->character[key[i]];

		// if string is invalid (reached end of path in Trie)
		if (curr == nullptr)
			return false;
	}

	// if current node is a leaf and we have reached the
	// end of the string, return true
	return curr->isLeaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string key) {
        // return false if Trie is empty
	//if (this == nullptr)
		//return false;

	Trie* curr = this;
	for (int i = 0; i < key.length(); i++)
	{
		// go to next node
		curr = curr->character[key[i]];

		// if string is invalid (reached end of path in Trie)
		if (curr == nullptr)
			return false;
	}

	// if current node is a leaf and we have reached the
	// end of the string, return true
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
