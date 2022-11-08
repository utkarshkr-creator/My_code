class TrieNode {

    //pointer array for child nodes of each node
    TrieNode *childNode[26];
    int wordEndCnt;
    int prfCnt;
public:
    TrieNode* new_object()
    {
        TrieNode *new_node =new TrieNode();

        new_node->wordEndCnt = 0;
        new_node->prfCnt=0;

        for (int i = 0; i < 26; i++)
        {
            new_node->childNode[i] = NULL;
        }

        return new_node;
    }
    TrieNode * insert_key(TrieNode *root, string &key)
    {
        //initialize the currentNode pointer with the root node
        TrieNode *currentNode = root;

        int i = 0;
        int n=key.size();

        while (i<n)
        {
            if (currentNode->childNode[key[i] - 'a'] == NULL)
            {
                //If null make a new node
                TrieNode * newNode = new_object();

                //Point the X-'a' th index of current node to the new node
                currentNode->childNode[key[i] - 'a'] = newNode;
            }

            //Move the current node pointer to the newly created node.
            currentNode = currentNode->childNode[key[i] - 'a'];
            currentNode->prfCnt++;

            i++;
        }

        //Increment the wordEndCnt for the last currentNode pointer as it will point
        //the string that is the end of the string key.
        currentNode->wordEndCnt++;
        currentNode->prfCnt++;

        //return the updated root node
        return root;
    }
     bool search_key(TrieNode *root, string &queryString)
    {
            //Initialize the currentNode pointer with the root node
            TrieNode *currentNode = root;

            int i = 0;
 
            while (i<queryString.size())
            {

                if (currentNode->childNode[queryString[i] - 'a'] == NULL)
                {
                    //If null then the query string is not present in the Trie
                    //return false
                    return false;
                }
                //If not NULL
                //Move the currentNode pointer to the node pointed by X-'a' th index of the
                //current node
                currentNode = currentNode->childNode[queryString[i] - 'a'];
                i++;
            }

            //If currentNode pointer is not NULL
            //and wordEndCnt for the currentNode pointer
            //is greater than 0 then return true else
            //return false

            return currentNode != NULL && currentNode->wordEndCnt > 0;

        }
        bool search_prefix(TrieNode *root, string &queryString){
             
             TrieNode *currentNode = root;

            int i = 0;
 
            while (i<queryString.size())
            {

                if (currentNode->childNode[queryString[i] - 'a'] == NULL)
                {
                    //If null then the query string is not present in the Trie
                    //return false
                    return false;
                }
                //If not NULL
                //Move the currentNode pointer to the node pointed by X-'a' th index of the
                //current node
                currentNode = currentNode->childNode[queryString[i] - 'a'];
                i++;
            }

            //If currentNode pointer is not NULL
            //and wordEndCnt for the currentNode pointer
            //is greater than 0 then return true else
            //return false

            return currentNode != NULL && currentNode->prfCnt > 0;
        }

        void delete_key(TrieNode *root, string &queryString)
        {

            //Initialize the currentNode pointer with the root node
            TrieNode *currentNode = root;

            int i = 0;

            while (i<queryString.size())
            {
                //Check if the X-'a' th index is NULL or not
                if (currentNode->childNode[queryString[i] - 'a'] == NULL)
                {
                    //If null the query string is not present in the Trie
                    
                    return ;
                }
                //Move the currentNode pointer to the next node
                currentNode = currentNode->childNode[queryString[i] - 'a'];
                currentNode->prfCnt--;
                i++;
            }

            //If currentNode pointer is not NULL and
            //wordEndCnt for the currentNode is greater than 0
            if (currentNode != NULL && currentNode->wordEndCnt > 0)
            {
                //then decrement the wordEndCnt for the
                //currentNode
                currentNode->wordEndCnt--;
                currentNode->prfCnt--;
                
                //return true
                return;
            }

            //If the wordEndCnt for the currentNode is equal to 0
            //Then that string is not present in Trie
            //return false
            return ;
        }
};
