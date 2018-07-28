//合并两个有序单向链表
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x){}
}ListNode, ListNode*;

//#方法一：while循环方式，⚠️链表节点的及时更新
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode* merge_node, *merge_head;
        //get merge head
        if(l1->val < l2->val){
            merge_node = l1;
            l1 = l1->next;
        }
        else{
            merge_node = l2;
            l2 = l2->next;
        }
        merge_head = merge_node;
        while(l1 && l2){
            if(l1->val < l2->val){
                merge_node->next = l1;
                merge_node = merge_node->next;
                l1 = l1->next;
            }
            else{
                printf("l2: l2->value is:%d\n", l2->val);
                merge_node->next = l2;
                merge_node = merge_node->next;
                l2 = l2->next;
            }                
        }
        merge_node->next = l1 ? l1 : l2;
        return merge_head;
    }
    
    //方法二：迭代递归的方法，⚠️链表迭代时需要考虑递归停止条件，以及下一步递归的输入内容
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //递归停止条件：
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *merge_list;
        if(l1->val < l2->val)
            merge_list = l1;
            merge_list->next = mergeTwoLists(l1->next, l2);
        }
        else{
            merge_list = l2;
            merge_list->next = mergeTwoLists(l1, l2->next);
        }
        return merge_list;
    }
    
    //评价：两种方法中递归的方法看上去代码更加简洁，但是while循环的方法耗时更少。
    
    
    
