#include <string>
class TrieNode
{
public:
	char data;
	bool isTerminal;
	TrieNode **children;

	TrieNode(char data)
	{
		this -> data = data;
		children = new TrieNode*[26];
		for (int i = 0; i < 26; i++)
			children[i] = NULL;
		isTerminal = false;
	}
};
class Tries
{
	TrieNode *root;

public:
	Trie()
	{
		root = new TrieNode('\0');
	}

	void insertWord(Trie *root, string word)
	{
		//Base case
		if (word.size() == 0)
		{
			root -> isTerminal = true;
			return;
		}

		//Small calculation
		int index = word[0] - 'a';
		TreeNode *child;

		//if first letter is present
		if (root -> children[index])
			child = root -> children[index];

		//if first letter is not present
		else
		{
			child = new TrieNode(word[0]); //creating node
			root -> children[index] = child; //inserting node
		}

		insertWord(child, words.substr(1));
	}

	void insertWord(string word)
	{
		insertWord(root, word);
	}

	bool search(TrieNode *root, string word)
	{
		if (word.size() == 0)
			return root -> isTerminal;

		int index = word[0] - 'a';

		if (root -> children[index])
			return search(root -> children[i], word.substr(1));
		else
			return false;

	}
	bool search(string word)
	{
		return search(root, word);
	}


	void removeWord(TrieNode *root, string word)
	{
		//base case
		if (word.size() == 0)
		{
			root -> isTerminal = false;
			return;
		}

		//small calc
		TrieNode *child;
		int index = word[0] - 'a';
		if (root -> children[index])
			child = root -> children[index];
		else
			return;

		removeWord(child, word.substr(1));


		if (child -> isTerminal == false)
		{
			for (int i = 0; i < 26; i++)
			{
				if (child -> children[i])
					return;
				//if there is a child, it will return and below lines wont be
				//executed.

			}
		}
		delete child;
		root -> children[index] = NULL;

	}
	void removeWord(string word)
	{
		removeWord(root, word);
	}
};