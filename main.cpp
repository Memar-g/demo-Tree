#include <iostream>

using namespace std;

struct node{
    int num;
    node* left,*right;
};
struct Node {
    int data;
    Node* firstChild;
    Node* nextSibling;
    //Node(int val) : data(val), firstChild(nullptr), nextSibling(nullptr) {}
};
node *root=NULL;
void BST();
void printTree(Node* node, int level = 0);
Node* createNode(int val);
void addChild(Node* parent, int childValue);
void bin_search_tree(int n);
int search_BST(node* root,int num);
void Max_BST();
void min_BST();
void displa();
void display(node* root);
void display1(node* root);
void display3(node* root);
void delete_BST(node* root,node* temp1,int key);
void DeleteBST(node *root, node *temp1, int key);
void leveltree(node* root,int key,int c);
int height(node* root);
int main()
{
    /*
    Node* root = createNode(1); // Create tree with root value 1

    addChild(root, 2); // Add child with value 2
    addChild(root, 3);// Add another child with value 3
    addChild(root->firstChild,4); // Add child to node with value 2

    cout << "Generic Tree:" << endl;
    printTree(root);
    */
    //addChild(parent,)

   char ch;
   cout<< "1.insert binary search tree"<<endl;
   cout<< "2.to search"<<endl;
   cout<< "3.find Max"<<endl;
   cout<< "4.find min"<<endl;
   cout<< "5.to delete"<<endl;
   cout<< "6.to find the level of a node"<<endl;
   cout<< "7.height of the tree"<<endl;
   //cout<< "3."<<endl;
   cin>>ch;
   cout<< endl;
switch(ch){
    case '1':{
        BST();
        displa();
        break;
    }
    case '2':{
        BST();
        int i=search_BST(root,5);
        if(i==-1)
           cout<< "the element is not found"<<endl;
        else
           cout<< "found"<<endl;
         displa();
        break;
    }
    case '3':{
        BST();
        Max_BST();
        break;
    }
    case '4':{
        BST();
        min_BST();
        break;
    }
    case '5':{
        BST();
       // bin_search_tree(7);
        delete_BST(root,root,6);
        //DeleteBST(root,root,9);
        displa();
        break;
    }
    case '6':{
        BST();
        leveltree(root,3,0);
        break;
    }
    case '7':{
        BST();
        cout<<height(root);
    }
}

   /*int i=search_BST(root,2);
   if(i==-1)
    cout<< "the element is not found"<<endl;
   else
    cout<< "found"<<endl;
   //Inorder(root);
   */
   //node* temp=root;
   //delete_BST(root,6);
   //Inorder(root);
}
// Function to create a new node

Node* createNode(int val) {
    Node* temp = new Node; // Allocate memory for a new node
    temp->data = val;      // Set the data value
    temp->firstChild = nullptr; // Initialize firstChild to nullptr
    temp->nextSibling = nullptr; // Initialize nextSibling to nullptr
    return temp;           // Return the newly created node
}

void addChild(Node* parent, int childValue) {

    Node* child = createNode(childValue);
    if (!parent->firstChild) {
        parent->firstChild = child; // If no children, set as first child
    } else {
        Node* sibling = parent->firstChild;
        while (sibling->nextSibling) {
            sibling = sibling->nextSibling; // Traverse to the last sibling
        }
        sibling->nextSibling = child; // Add as the next sibling
    }
}
void printTree(Node* node, int level) {
    if (node) {
        cout << string(level * 2, ' ') << node->data << endl; // Indent based on level
        printTree(node->firstChild, level + 1); // Print children
        printTree(node->nextSibling, level); // Print siblings
    }
}
void BST(){
    /*
   bin_search_tree(16);
   bin_search_tree(5);
   //bin_search_tree(18);
   bin_search_tree(10);
   bin_search_tree(7);
    bin_search_tree(6);
    bin_search_tree(8);
   bin_search_tree(15);
   bin_search_tree(2);
   bin_search_tree(1);
   bin_search_tree(4);
   bin_search_tree(3);
   */
   bin_search_tree(7);
   bin_search_tree(5);
   bin_search_tree(6);
   bin_search_tree(2);
   bin_search_tree(3);

}
void bin_search_tree(int n){
    node* temp=new node;
    temp->num=n;
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
        root=temp;

    else{
        node* temp1=root;
        int inserted=0;
        while(true){
            if(temp->num<temp1->num){
                if(temp1->left==NULL){
                    temp1->left=temp;
                    inserted=1;
                    break;
                }
                else
                    temp1=temp1->left;
            }
               // temp1=temp1->left;
            else{
                 if(temp1->right==NULL) {
                    temp1->right=temp;
                    inserted=1;
                    break;
                 }
                 else
                    temp1=temp1->right;
            }
        }
        /*
        if(temp->num<temp1->num)
            temp1->left=temp;

        else
             temp1->right=temp;
             */
    }
}
int search_BST(node* root,int key){

    int i=-1;
    if(root!=NULL){
    if(root->num==key){
        i=0;
    }
     else if(key<root->num){

       return( search_BST(root->left,key));
     }
     else{

        return(search_BST(root->right,key));
     }
    }
    return i;
}
void Max_BST(){
    node* temp=root;
    while(temp->right){
        temp=temp->right;
    }
    cout<< "the maximum number is : "<<temp->num;
}
void min_BST(){
    node* temp=root;
    while(temp->left){
        temp=temp->left;
    }
    cout<< "the minimum number is : "<<temp->num;
}
void delete_BST(node* root,node* temp1,int key){
    node* temp3;
  /*  if(key==16){
       node* temp=root;
       root=root->left;
       node* temp2=root;
       while(temp2->right!=NULL)
           temp2=temp2->right;
       temp2->right=temp->left;
       delete temp;
    }*/
   // node* temp1;
   // if(root!=NULL){
        if(root->num==key){
            node* temp=root;
            //if(key==16){
             //   node* temp2=root->left
            //}
            //else {
            if(temp1->left==root || key==6){
                if((root->left!=NULL && root->right==NULL) || (root->left==NULL &&root->right!=NULL)){
                    //node* temp=root;
                    if(temp->left!=NULL){

                       if(key==6){
                            //cout<<root->num;
                            //temp3=root;
                           // temp3=temp3->left;
                           root=root->left;
                           // delete_BST(root->left,root,key);
                            //cout<<root->num;
                       }
                       temp1->left=temp->left;
                    }
                     else{
                        temp1->left=temp->right;
                        if(key==16){
                            root=root->right;
                        }
                     }
                    delete temp;
                }
                else if(root->left!=NULL && root->right!=NULL){
                    node* temp2=temp->left;
                    temp1->left=temp->left;
                    while(temp2->right!=NULL)
                    temp2=temp2->right;
                    temp2->right=temp->right;
                    delete temp;
                }
            }
            //cout<< root->num;

             if(temp1->right==root){
                    if((root->left!=NULL && root->right==NULL) || (root->left==NULL &&root->right!=NULL)){
                    //node* temp=root;
                    if(temp->left!=NULL)
                       temp1->right=temp->left;
                     else
                        temp1->right=temp->right;
                    delete temp;
                }
                  else if(root->left!=NULL && root->right!=NULL){
                    node* temp2=temp->left;
                    temp1->right=temp->left;
                    while(temp2->right!=NULL)
                    temp2=temp2->right;
                    temp2->right=temp->right;
                    delete temp;
                }
            }
             if(root->left==NULL && root->right==NULL){

                    if(temp1->left==temp)
                       temp1->left=NULL;
                     else
                        temp1->right=NULL;

                    delete temp;
                    //cout<< root->num;
           }

           //else if(root->left!=NULL && root->right==NULL){
           //}
        }
        //}
        else if(key<root->num){
            //temp1=root;
            delete_BST(root->left,root,key);
        }
        else{
            //temp1=root;
            delete_BST(root->right,root,key);
        }
    //}

}
/*void display(){
    node* temp=root;
    while(temp->left!=NULL)
        temp=temp->left;
    while(temp!=root){
        cout<<temp->num<< " ";
        if(temp->right!=NULL)
    }
}
*/
void DeleteBST(node *root, node *temp1, int key)
{
    node* temp3,*temp4;
	 // a pointer that points to the currently deleted node
	// PDNP is a pointer that points to the parent node of currently deleted node
	if(root==NULL)
		cout<<"Data not found\n";
	else if (root->num>key)
		DeleteBST(root->left, root, key);// delete the element in the left subtree
	else if(root->num<key)
		DeleteBST(root->right, root, key);// delete the element in the right subtree
	else
	{
		node *temp=root;
		/*if(temp->left!=NULL){
            temp1->right=temp->left;
            delete temp;
		}*/
		if((temp->left==NULL) && (temp->right==NULL))
		{
			if (temp1->left==temp)
				temp1->left=NULL;
			else
				temp1->right=NULL;
			delete temp;
		}

		else
		{
		    //if(){

		    //}
			if(temp->left!=NULL) //find the maximum in the left
			{
				temp3=temp;
				temp4=temp->left;
				while(temp4->right!=NULL)
				{
					temp3=temp4;
					temp4=temp4->right;
				}
				temp->num=temp4->num;
				if(temp4->left!=NULL)
                    temp3->right=temp4->left;
                 else
                    temp3->right=NULL;
                delete temp4;
				//DeleteBST(root,temp1,temp->num);
			}
			else //find the minimum in the right
			{
				temp3=temp;
				temp4=temp->right;
				while(temp4->left!=NULL)
				{
					temp3=temp4;
					temp4=temp4->left;
				}
				root->num=temp->num;
				DeleteBST(temp,temp1,temp->num);
			}
		}
	}
}
void leveltree(node* root,int key,int Count){
    int i=-1;
    if(root!=NULL){
         if(root->num==key){
             i=0;
             cout<< "the level of node  is : "<<Count;
         }
         else if(key<root->num){
              leveltree(root->left,key,Count+1);
         }
        else{
            leveltree(root->right,key,Count+1);
        }
    }

    else
        cout<< "the element is not found";

    //cout<< "the level of node  is : "<<Count;
}
int height(node *root) {
    if (root == nullptr)
        return -1;

    // compute the height of left and right subtrees
    int lHeight = height(root->left);
    int rHeight = height(root->right);

    return max(lHeight, rHeight) + 1;

}
void displa()
{
    char ch;
    cout<< "1.preorder traversal"<<endl;
    cout<< "2.inorder traversal"<<endl;
    cout<< "3.postorder traversal"<<endl;
    cin>>ch;
    cout<<endl;
    switch(ch){
        case '1':{
            display1(root);
            break;
        }
         case '2':{
           display(root);
           break;
          }
          case '3':{
              display3(root);
              break;
          }
       }
}
void display1(node* root){
    if(root!=NULL){
        //display1(root);
        cout<< root->num<<" ";
        display1(root->left);
        display1(root->right);
    }
}
void display(node* root){
     if(root != NULL)
            {
            display(root->left);
            cout << root->num<< " "; // or any operation on the node
            display(root->right);
          }
}
void display3(node* root){
    if(root!=NULL){
        display3(root->left);
        display3(root->right);
        cout << root->num<< " ";
    }
}




