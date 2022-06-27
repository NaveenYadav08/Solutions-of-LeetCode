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

// C++ implementation of search and insert
// operations on Trie
#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode
{
	struct TrieNode *children[26];

	// isEndOfWord is true if the node represents
	// end of a word
	bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
	struct TrieNode *pNode = new TrieNode;

	pNode->isEndOfWord = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;

	return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key)
{
	struct TrieNode *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}

	// mark last node as leaf
	pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else
// false
bool search(struct TrieNode *root, string key)
{
	struct TrieNode *pCrawl = root;

	for (int i = 0; i < key.size(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			return false;

		pCrawl = pCrawl->children[index];
	}

	return (pCrawl->isEndOfWord);
}

// Driver
int main()
{
	// Input keys (use only 'a' through 'z'
	// and lower case)
	string keys[] = {"the", "a", "there",
					"answer", "any", "by",
					"bye", "their" };
	int n = sizeof(keys)/sizeof(keys[0]);

	struct TrieNode *root = getNode();

	// Construct trie
	for (int i = 0; i < n; i++)
		insert(root, keys[i]);

	// Search for different keys
	search(root, "the")? cout << "Yes\n" :
						cout << "No\n";
	search(root, "these")? cout << "Yes\n" :
						cout << "No\n";
	search(root, "their")? cout << "Yes\n" :
						cout << "No\n";
	search(root, "thaw")? cout << "Yes\n" :
						cout << "No\n";
	return 0;
}

