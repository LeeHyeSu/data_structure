#include <stdio.h>
#include <stdlib.h>

 #define MAX_ELEMENT 100
 typedef struct TreeNode {
         int weight;
         struct TreeNode *left_child;
         struct TreeNode *right_child;
 } TreeNode;
 typedef struct {
         TreeNode *ptree;
         int key;
 } element;
 typedef struct {
         element heap[MAX_ELEMENT];
         int heap_size;
 } HeapType;

 // 초기화 함수
void init(HeapType *h)
 {
         h->heap_size =0;
 }
 // 삽입 함수
void insert_min_heap(HeapType *h, element item) 
 { 
     int i; 
     i = ++(h->heap_size); 

     //  트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
    while((i != 1) && (item.key < h->heap[i/2].key)){ 
            h->heap[i] = h->heap[i/2]; 
        i /= 2; 
     } 
     h->heap[i] = item;     // 새로운 노드를 삽입
} 
 // 삭제 함수
element delete_min_heap(HeapType *h) 
 { 
     int parent, child; 
     element item, temp;

     item = h->heap[1];
     temp = h->heap[(h->heap_size)--];
     parent = 1;        
     child = 2;
     while( child <= h->heap_size ){
           // 현재 노드의 자식노드중 더 작은 자식노드를 찾는다.
           if( ( child < h->heap_size ) && 
               (h->heap[child].key) > h->heap[child+1].key)
               child++;
           if( temp.key <= h->heap[child].key ) break;
           // 한단계 아래로 이동
          h->heap[parent] = h->heap[child];
           parent = child;
           child *= 2;
     }
     h->heap[parent] = temp;
     return item;
 } 

 // 이진 트리 생성 함수
TreeNode *make_tree(TreeNode *left, TreeNode *right)
 {
         TreeNode *node=(TreeNode *)malloc(sizeof(TreeNode));
         if( node == NULL ){
                 fprintf(stderr,"메모리 에러\n");
                 exit(1);
         }
         node->left_child = left;
         node->right_child = right;
         return node;
 }
 // 이진 트리 제거 함수
void destroy_tree(TreeNode *root)
 {
         if( root == NULL ) return;
         destroy_tree(root->left_child);
         destroy_tree(root->right_child);
         free(root);
 }

// 허프만 코드 출력 함수
void print_huffman_code(TreeNode *tree, char *code, int n)
{
	if(tree) {
		n++;
		code[n] = '1';
		print_huffman_code(tree->left_child, code, n);
		code[n] = '0';
		print_huffman_code(tree->right_child, code, n);
		code[n] = '\0';
		if(tree->left_child == NULL || tree->right_child == NULL)
			printf("%2d번 출연한 문자의 코드 : \t%s\n", tree->weight, code);
	}
}

 // 허프만 코드 생성 함수
void huffman_tree(int freq[], int n)
 {
         int i;
         TreeNode *node, *x;
         HeapType heap;
         element e, e1, e2;
		 char* code = (char*)malloc(sizeof(char));

         init(&heap);
         for(i=0;i < n; i++) {       
			node = make_tree(NULL, NULL);
            e.key = node->weight = freq[i];
			e.ptree = node;
            insert_min_heap(&heap, e);
         }
         for(i=1;i < n; i++) {          
			e1 = delete_min_heap(&heap);                
			e2 = delete_min_heap(&heap);
            x = make_tree(e1.ptree, e2.ptree); 
            e.key = x->weight = e1.key + e2.key;
            e.ptree = x;
            insert_min_heap(&heap, e);
         }
         e = delete_min_heap(&heap); // 최종 트리
		 print_huffman_code(e.ptree, code, -1);
		 destroy_tree(e.ptree);
 }

void main()
 {
        int freq[] = { 1, 10, 11, 14, 15, 35, 45, 1000  };

        huffman_tree(freq, 8);

 }