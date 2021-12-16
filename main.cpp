#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;   

// creat a class of code
class Node{
	public:
		//the data in node
		int  num;  
		//define the branchs for direction to next node
		Node *llink;  
		Node *rlink; 
};
class Tree{
	private:
		//indicatot variable of direct to root
		Node *root;
		//direct to new node for insert node
		Node *newNode;
		//dirct to current code when serching the node for node for insert
		Node *current;
		Node *ptr;
		vector<int>each_node_in_tree; //for delete_f

		
	public:
		Tree(){
			root=NULL;
			current=NULL;
			ptr=root;
			tree_treval(root);
		}
		Node *get_root(){
			return root;
		}

		void insert_f(int input_data){
			ptr=root;
			newNode=new Node();
			newNode->rlink=NULL;
			newNode->llink=NULL;
			if(root==NULL){
				newNode->num=input_data;	
				root=newNode;
			}else{
				current=root;
				newNode->num=input_data;
				while(current->llink!=NULL||current->rlink!=NULL){
					if(newNode->num <= current->num){
						if(current->llink==NULL){
							break;
						}
						current=current->llink;
					}
					else{
						if(current->rlink==NULL){
							break;
						}
						current=current->rlink;
					}
				}
				if(newNode->num<=current->num){
					current->llink=newNode;
					// printf("to left: %d\n",newNode->num);
				}else{
					current->rlink=newNode;
					// printf("to right: %d\n",newNode->num);
				}
			}
		}

		void display_f(Node *root){
			if(root!=NULL){
				printf("%d || ",root->num);
				display_f(root->llink);
				display_f(root->rlink);
			}
		}
		void display_f(){
			display_f(get_root());
		}
		//find the number ,which i want to deleted
		Node *search_node(int node_num){
			Node *ptr=root;
			while(true){
				if(ptr->num>=node_num){
					ptr=ptr->llink;
				}else{
					ptr=ptr->rlink;
				}
				if(ptr->num==node_num){
					return ptr;
				}
			}
		}
		void delete_f(int delete_num){
			Node *deleted_node=search_node(delete_num);//The node,where deleted_num in there.			
			Node *prev,*prev_split,*replace_node;
			bool split_flag;
			prev=deleted_node;
			if(prev->llink!=NULL){
				prev=prev->llink;
				if(prev->rlink!=NULL){
					while(prev->rlink!=NULL){
						prev_split=prev;
						prev=prev->rlink;
					}
				}
				split_flag=true;
			}
			if(prev->rlink!=NULL){
				prev=prev->rlink->rlink;
				while(prev->llink!=NULL){
					prev_split=prev;
					prev=prev->llink;
				}
				split_flag=false;
			}
			
			if(split_flag){
				prev_split->rlink=NULL;
			}else{
				prev_split->llink=NULL;
			}
			replace_node=prev;
			cout<<"node"<<replace_node->num<<" replace node"<<deleted_node->num<<endl; 
			deleted_node->num=replace_node->num;
			
			tree_treval(replace_node);
			for(int i=1;i<each_node_in_tree.size();i++){
				insert_f(each_node_in_tree[i]);
				// cout<<replace_tree[i]<<" "<<endl;
			}
		}

		void tree_treval(Node *root){
			if(root!=NULL){
				each_node_in_tree.push_back(root->num);
				tree_treval(root->llink);
				tree_treval(root->rlink);
			}

		}
};

int main(void){

	Tree tree;
	tree.insert_f(20);
	tree.insert_f(30);
	tree.insert_f(35);
	tree.insert_f(25);
	tree.insert_f(29);
	tree.insert_f(28);
	tree.insert_f(26);
	tree.insert_f(27);

	tree.delete_f(30);
	tree.display_f();

}



