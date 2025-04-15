A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 

Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.


Code: 
using System;
using System.Collections.Generic;

public class TrieNode
{
    public Dictionary<char, TrieNode> Children { get; set; } // Corrected type: TrieNode instead of Trie
    public bool IsWordEnd { get; set; } // Added the IsWordEnd property

    public TrieNode()
    {
        Children = new Dictionary<char, TrieNode>();
        IsWordEnd = false; // Initialize IsWordEnd
    }
}

public class Trie
{
    private readonly TrieNode _root;

    public Trie()
    {
        _root = new TrieNode();
    }

    public void Insert(string word)
    {
        TrieNode current = _root; // Corrected "TrienNode" to "TrieNode"
        foreach (char c in word)
        {
            if (!current.Children.ContainsKey(c)) // Fixed typo: "ContainKey" to "ContainsKey"
            {
                current.Children[c] = new TrieNode();
            }
            current = current.Children[c];
        }
        current.IsWordEnd = true;
    }

    public bool Search(string word)
    {
        TrieNode current = _root;
        foreach (char c in word)
        {
            if (!current.Children.ContainsKey(c)) // Fixed typo: "ContainKey" to "ContainsKey" and corrected access
            {
                return false;
            }
            current = current.Children[c];
        }
        return current.IsWordEnd; // Checks if it is the end of a word
    }

    public bool StartsWith(string prefix)
    {
        TrieNode current = _root;
        foreach (char c in prefix) // Fixed loop to iterate over prefix (not "word")
        {
            if (!current.Children.ContainsKey(c)) // Fixed typo: "ContainKey" to "ContainsKey"
            {
                return false;
            }
            current = current.Children[c];
        }
        return true; // Returns true if the prefix is found
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.Insert(word);
 * bool param_2 = obj.Search(word);
 * bool param_3 = obj.StartsWith(prefix);
 */
