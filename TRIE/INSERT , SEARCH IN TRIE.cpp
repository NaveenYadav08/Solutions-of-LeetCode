CAN REFER TO THIS LINK -   https://takeuforward.org/data-structure/implement-trie-1/


Implement Trie – 1
Problem Statement: Implementing insertion, search, and startWith operations in a trie or prefix-tree.

Implementation: 

Type 1: To insert a string “word” in Trie.                           

Type 2: To check if the string “word” is present in Trie or not.

Type 3: To check if there is any string in the Trie that starts with the given prefix string “word”.        
  
Example:
Input: type = {1, 1, 2, 3, 2};
value = {"hello", "help", "help", "hel", "hel"};
Output: 
true
true
false
Explanation: 
Trie object initialized
“hello” inserted in the trie.
“help” insertedin the trie 
“help” searched in the trie //returns true
Checked if any previously inserted word has the prefix “hel” //return true
“hel” searches in the trie //returns true


----------------------------------------------------------------------------------------------------------------------------------------------------------------------

Approach: Trie struct has 2 variables Node *links[26] (for storing characters); assuming all words have lowercase letters and a bool flag. 
The flag is always false except when the word ends.



Insert: The last reference trie’s flag has to be to true since the word is completed. The diagram shows the insertion of the word “apple”.

The basic idea of insertion is that if the reference trie does not exist create a new trie and if it does simply traverse to it.

Search: Search if the word is present in the trie or not,

Start from the root and traverse through the word. while traversing through the word check if the reference trie for that character exists or not. 
If it exists move to the reference trie, else return false. Once the word is traversed character by character return the flag at that particular trie.

startsWith: Check if the word inserted previously has the prefix “prefix” or not.

It is similar to a search operation. Start from the root of the trie and traverse through the “prefix”.
If the reference trie for a character is not present return false else transverse to the reference trie.Once the “prefix’ is traversed completely character by character return true.

---------------------------------------------------------------------------------------------------------------------------------------------------------------------


╭━━━┳━━━┳━━━┳━━━╮
┃╭━╮┃╭━╮┣╮╭╮┃╭━━╯
┃┃╱╰┫┃╱┃┃┃┃┃┃╰━━╮
┃┃╱╭┫┃╱┃┃┃┃┃┃╭━━╯
┃╰━╯┃╰━╯┣╯╰╯┃╰━━╮
╰━━━┻━━━┻━━━┻━━━╯

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MAXN 100001
#define INF 1e18+1
struct Node {
	Node *links[26];
	bool flag = false;
	//checks if the reference trie is present or not
	bool containKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}
	//creating reference trie
	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
	}
	//to get the next node for traversal
	Node *get(char ch) {
		return links[ch - 'a'];
	}
	//setting flag to true at the end of the word
	void setEnd() {
		flag = true;
	}
	//checking if the word is completed or not
	bool isEnd() {
		return flag;
	}
};
class Trie {
private:
	Node* root;
public:
	Trie() {
		//creating new obejct
		root = new Node();
	}

	void insert(string word) {
		//initializing dummy node pointing to root initially
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				node->put(word[i], new Node());
			}
			//moves to reference trie
			node = node->get(word[i]);
		}
		node->setEnd();
	}

	bool search(string word) {
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				return false;
			}
			node = node->get(word[i]);
		}
		return node->isEnd();
	}

	bool startsWith(string prefix) {
		Node* node = root;
		for (int i = 0; i < prefix.size(); i++) {
			if (!node->containKey(prefix[i])) {
				return false;
			}
			node = node->get(prefix[i]);
		}
		return true;
	}
};

int main()
{
	int n = 5;
	vector<int>type = {1, 1, 2, 3, 2};
	vector<string>value = {"hello", "help", "help", "hel", "hel"};
	Trie trie;
	for (int i = 0; i < n; i++) {
		if (type[i] == 1) {
			trie.insert(value[i]);
		}
		else if (type[i] == 2) {
			if (trie.search(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
		else {
			if (trie.startsWith(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
	}
}
