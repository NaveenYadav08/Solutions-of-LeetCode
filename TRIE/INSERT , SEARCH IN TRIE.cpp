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

	
	
During delete operation we delete the key in bottom up manner using recursion. The following are possible conditions when deleting key from trie, 

delete recursively 
if no child and end of word del it
---------------------------------------------------------------------------------------------------------------------------------------------------------------------


╭━━━┳━━━┳━━━┳━━━╮
┃╭━╮┃╭━╮┣╮╭╮┃╭━━╯
┃┃╱╰┫┃╱┃┃┃┃┃┃╰━━╮
┃┃╱╭┫┃╱┃┃┃┃┃┃╭━━╯
┃╰━╯┃╰━╯┣╯╰╯┃╰━━╮
╰━━━┻━━━┻━━━┻━━━╯

// Program for deleting nodes from trie
#include <bits/stdc++.h>
using namespace std;

const int numChar = 26;

// Trie node structure
struct Trienode
{
	struct Trienode *child[numChar];
	bool wordEnd;
};

/*
    Function to create the node which returns new trieNode initialized 
    to NULL
*/
struct Trienode* createNode(void)
{
	struct Trienode *newNode = new Trienode;
	newNode->wordEnd = false;

	for (int i = 0; i < numChar; i++)
		newNode->child[i] = NULL;

	return newNode;
}

/*
    If a node is not present, it will insert a word to the trie; if the 
    word is a prefix of trie node, and it will just mark the leaf node
*/
void trieInsert(struct Trienode *root, string word)
{
	struct Trienode *temp = root;

	for (int i = 0; i < word.length(); i++)
	{
		int index = word[i] - 'a';
		if (!temp->child[index])
		{
			// To create a new node
			temp->child[index] = createNode();
		}

		temp = temp->child[index];
	}

	// Indicates the last node as leaf
	temp->wordEnd = true;
}

// Function for searching word in the trie and return true if present
bool trieSearch(struct Trienode *root, string word)
{
	struct Trienode *temp = root;

	for (int i = 0; i < word.length(); i++)
	{
		int index = word[i] - 'a';
		if (!temp->child[index])
		{
			return false;
		}

		temp = temp->child[index];
	}

	return (temp != NULL && temp->wordEnd);
}

// Function to check if the root has any children or not.
bool trieEmpty(Trienode *root)
{
	for (int i = 0; i < numChar; i++)
	{
		if (root->child[i])
		{
			return false;
		}
	}

	return true;
}

// Function having a recursive call to delete a word from the Trie given
Trienode* trieDelete(Trienode *root, string word, int height = 0)
{
	// Condition if the tree is empty
	if (!root)
	{
		return NULL;
	}

	// The final character of the word is being handled
	if (height == word.size())
	{
		/*
		    After removal of the given word/key, the last node is 
		    not the end of the word
		*/
		if (root->wordEnd)
		{
			root->wordEnd = false;
		}

		// In case if the given word isn't prefix of any other word
		if (trieEmpty(root))
		{
			delete(root);
			root = NULL;
		}

		return root;
	}

	/*
	    In case it is not the last character, repeat for the child using 
	    ASCII value
	*/
	int index = word[height] - 'a';
	root->child[index] = trieDelete(root->child[index], word, height + 1);

	/*
	    In case the root does not have any child(its only child gets 
	    removed), then it is not the same for another word. The another 
	    word does not end here.
	*/
	if (trieEmpty(root) && root->wordEnd == false)
	{
		// Node deleted
		delete(root);
		root = NULL;
	}

	return root;
}

int main()
{
	string word[] = { "coding", "ninja", "play", "join", "us", "have",
		"fun" };
	int size = sizeof(word) / sizeof(word[0]);
	struct Trienode *root = createNode();

	// To construct the nodes in the trie
	for (int i = 0; i < size; i++)
	{
		trieInsert(root, word[i]);
	}

	// To search for a word in the trie inputted
	trieSearch(root, "coding") ? cout << "Yes, it is present!\n" : cout <<
		"No, it is not present!\n";

	trieSearch(root, "ninja") ? cout << "Yes, it is present!\n" : cout <<
		"No, it is not present!\n";

	// To delete a word in the trie
	trieDelete(root, "play");

	// To search the word deleted
	trieSearch(root, "playground") ? cout << "Yes, it is present!\n" : cout <<
		"No, it is not present!\n";
	return 0;
}

