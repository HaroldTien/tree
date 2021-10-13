#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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
//afasdfasf
class Tree{
	private:
		//indicatot variable of direct to root
		Node *root;
		//direct to new node for insert node
		Node *newNode;
		//dirct to current code when serching the node for node for insert
		Node *current;

	public:
		Tree(){
			root=NULL;
			current=NULL;
		}	
		void insert_f(int input_data){
			//instantiate a new node
			newNode=new Node();
			newNode->rlink=NULL;
			newNode->llink=NULL;
			
			//determine whether is first node of insert
			if(root==NULL){
				newNode->num=input_data;	
				root=newNode;
				// printf("%d\n",root->num);
			}else{
				current=root;
				newNode->num=input_data;
				while(current->llink!=NULL||current->rlink!=NULL){
					if(newNode->num <= current->num){
						if(current->llink==NULL){
							// printf("b");
							break;
						}
						current=current->llink;
						// printf("/\n");
					}
					else{
						if(current->rlink==NULL){
							// printf("b");
							break;
							
						}
						current=current->rlink;
						// printf("\\ \n");
					}
				}
				// printf("%d  %d\n",current->num,newNode->num);
				if(newNode->num<=current->num){
					current->llink=newNode;
					printf("to left: %d\n",newNode->num);
				}else{
					current->rlink=newNode;
					printf("to right: %d\n",newNode->num);
				}
			}
		}
		void display(){
			//
			if(current==NULL){
				current=root;	
			}
			if(current->llink!=NULL){
				current=current->llink;
			}else{
				printf("%d",current->num);
				// current=&current;
				// display();
			}
			
		}
};
int main(void){
	Tree tree;
	// int num;
	// scanf("%d",&num);
	tree.insert_f(14);
	tree.insert_f(5);
	tree.insert_f(7);
	tree.insert_f(18);
	// tree.display();

}















