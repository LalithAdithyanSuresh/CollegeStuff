#include <stdio.h>
#include <stdlib.h>

#define E_vertex -1

class Graph{
    private:
        int **Matrix;
        int *Vertices;
        int V_Count;
        void CreateNewVertex(int);
        int SearchVoid();
    public:
        Graph(){
            V_Count = 0;
            Vertices = (int *)malloc(sizeof(int));
            Matrix = (int **)malloc(sizeof(int));
        }
        int Insert(int);
        int Delete(int);
        int Search(int);
        void Display();
};


int main(){
    int data,opt;
    Graph G1;
    while(1==1){
        printf("\nOptions:\n\t1. Insert\n\t2. Delete\n\t3. Search\n\t4. Display\n\t5. Exit\n>>>");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            printf("Enter Vertex Value to Insert : ");
            scanf("%d",&data);
            if(G1.Insert(data) == 1){
                printf("Insert Successful");
            }else{
                printf("An error Occured");
            }
            break;
        case 2:
            printf("Enter Vertex Value to Delete : ");
            scanf("%d",&data);
            if(G1.Delete(data) == data){
                printf("Deletion Successful");
            }else{
                printf("Element not found");
            }
            break;
        case 3:
            printf("Enter Vertex Value to Search : ");
            scanf("%d",&data);
            if(G1.Search(data) == data){
                printf("Element Found");
            }else{
                printf("Element not Found");
            }
            break;
        case 4:
            printf("Displaying Adjacency Matrix :\n");
            G1.Display();
            break;
        case 5:
            return 1;
        default:
            break;
        }
    }
}

// Method to search for any empty space already present in the Matrix and array
int Graph::SearchVoid(){
    for(int i=0;i<V_Count;i++){
        if(Vertices[i] == E_vertex){
            return i;
        }
    }
    return -1;
}

// Method to Insert New Vertex and fill in values
int Graph::Insert(int Val){
    int V = SearchVoid();
    if(V == -1){
        CreateNewVertex(Val);
        V = V_Count-1;
    }else{
        Vertices[V] = Val;
    }
    char b='d';
    for(int i=0;i<V_Count;i++){
        if(Vertices[i]!=E_vertex){
            printf("Do you want to connect %d  -  %d (y/n) : ",Val,Vertices[i]);
            b = getchar();
            getchar();
            if(b == 'y'){
                Matrix[V][i] = 1;
                Matrix[i][V] = 1;
            }
        }
    }
    return 1;
}

// Method to Create and allocate space for new vertices that don't already have space
void Graph::CreateNewVertex(int V_Value){
    V_Count++;
    Vertices = (int *)realloc(Vertices,sizeof(int)*V_Count);
    Vertices[V_Count-1] = V_Value;
    Matrix = (int **)realloc(Matrix,sizeof(int *)*V_Count);
    Matrix[V_Count-1] = (int *)malloc(sizeof(int)*V_Count);
    for(int i=0;i<V_Count-1;i++){
        Matrix[i] = (int *)realloc(Matrix[i],sizeof(int)*V_Count);
        Matrix[i][V_Count-1] = 0;
    }
    for(int i=0;i<V_Count;i++){
        Matrix[V_Count-1][i] = 0;
    }
}

// Method to Delete a Vertex
int Graph::Delete(int Val){
    for(int i=0;i<V_Count;i++){
        if(Vertices[i] == Val){
            Vertices[i] = E_vertex;
            return 1;
        }
    }
    return 0;
}

// Method to search for a vertex in the Graph
int Graph::Search(int Val){
    for(int i=0;i<V_Count;i++){
        if(Vertices[i] == Val){
            return 1;
        }
    }
    return 0;
}

// Method to Display the Adjacency matrix
void Graph::Display(){
    printf("   ");
    for(int i=0;i<V_Count;i++){
        if(Vertices[i]!=E_vertex){
            printf(" %2d",Vertices[i]);
        }
    }
    printf("\n");
    for(int i=0;i<V_Count;i++){
        if(Vertices[i]!=E_vertex){
            printf(" %2d",Vertices[i]);
            for(int j=0;j<V_Count;j++){
                if(Vertices[j]!=E_vertex){
                    printf(" %2d",Matrix[i][j]);
                }
            }
            printf("\n");
        }
    }
}