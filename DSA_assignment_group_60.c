#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#define T INT_MAX
#define NO_OF_NODES 200000 // Set the required number according to the user's need
#define THRESHOLD 5 // Set the required number according to the user's need

// Definition of the List struct
typedef struct Lnode{
    int val;
    struct Lnode* next;
} Lnode;

// Definition of the MNode struct
typedef struct Mnode{
    Lnode* list;
    // dirty is not used
} Mnode;

//Global variable of array based implementation
Mnode tree[NO_OF_NODES];
int depth=0;


// Function for creating a new node for list
Lnode* createListNode(int data){
    Lnode* node=(Lnode*) malloc(sizeof(Lnode));
    node->val=data;
    node->next=NULL;
    return node;
}

// Function to return the value of an MNode
int valueOfMound(Mnode mnode){
    if(mnode.list==NULL)return T;
    return (mnode.list)->val;
}

// Function for Binary search for a random leaf to root path
int binarySearch(int leaf,int data){
    int start=1;
    int end=leaf;
    int ans=-1;
    
    while(start<=end){
        int startLevel=log2(start); // Level of the start node
        int endLevel=log2(end); // Level of the end node
        int dif=endLevel-startLevel;
        dif=dif/2;  
        int mid=end/(pow(2,dif)); // to find the middle node between start and end node

        // Binary search algorithm 
        if(valueOfMound(tree[mid])<=data ){
            if(pow(2,dif-1)<1){
                start=start*pow(2,1-dif);   
            }
            else{
                start=end/pow(2,dif-1);
            }
        }
        else{
            ans=mid;
            end=mid/2;
        }
    }
    return ans;
}

// Function to get random leaf at current depth
int randleaf(){
    int ran=0;
    int low=(int)(pow(2,depth));
    int high=(int)(pow(2,depth+1)-1);
    ran=(rand()%(high-low+1)) + low;
    return ran;
}

// Function for finding a insert position
int insertPosition(int data){
    
    while(1){
        for(int i=0;i<THRESHOLD;i++){
            int leaf=randleaf(); // Function call to get a random leaf
            //printf("rand %d |", leaf);
            if(valueOfMound(tree[leaf])>=data){
                int position=binarySearch(leaf,data);
                //printf("binary search location %d |",position);
                return position;
            }
        }
        depth++;
    }
    return 0;
}

// Function to insert a value into a Mound
void insert(int data){
    Lnode* ln=createListNode(data);
    int insertionPoint=insertPosition(data);
    //printf(" insertions point %d |",insertionPoint);
    if(tree[insertionPoint].list!=NULL){
        ln->next=tree[insertionPoint].list;
    }
    tree[insertionPoint].list=ln;
}

// Function to restore the Mound property in a triangle of nodes
void moundify(int pos){
    int min=pos;
    int left=pos*2;
    int right=pos*2+1;
    if((valueOfMound(tree[left]) < valueOfMound(tree[pos])) || (valueOfMound(tree[right]) < valueOfMound(tree[pos]))){
        if(valueOfMound(tree[left])> valueOfMound(tree[right])){
            min=right;
        }
        else{
            min=left;
        }

        // swap two MNodes
        Mnode temp=tree[pos];
        tree[pos]=tree[min];
        tree[min]=temp;
        moundify(min);
        return;
    }
    return;
}

// Function to extract the minimum value from a Mound
int extractMin(){
    if(tree[1].list==NULL)return T;
    int min=tree[1].list->val;
    Lnode* root=tree[1].list;
    tree[1].list=tree[1].list->next;
    free(root);
    moundify(1);
    return min;
}

/* Function that repeatedly performs 
extractMin() operation and 
prints the extracted object each time,
until all the objects in the mound are exhausted.
*/
void extractAll(){
    int min=extractMin();
    while(min!=T){
        printf("%d\n",min);
        min=extractMin();
    }
}

// Main Function
int main(){
    
    // Open the file for reading
    FILE *fp;
    fp = fopen("PQ_Data.txt", "r");
    
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    
    // Read the values from the file and insert them into the Mound
    int value;
    while (fscanf(fp, "%d", &value) != EOF) {
        //printf("data %d : ",value);
        insert(value);
        //printf("\n");
    }

    // Close the file
    fclose(fp);


    printf("\n");

    // for(int i=0;i<NO_OF_NODES;i++){
    //     Lnode*t=tree[i].list;
    //     bool checkNull=(t!=NULL);
    //     if(t!=NULL)printf("tree at %d: ",i);
    //     while(t!=NULL){
    //         printf("%d, ",t->val);
    //         t=t->next;
    //     }
    //     if(checkNull)
    //     printf("\n");
    // }

    printf("\n");

    // Extract the minimum value and print it
    printf("Extract Min\n\n");
    extractAll();
    
    return 0;
}