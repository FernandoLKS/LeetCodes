#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int value;
    ListNode* next;
    ListNode() : value(0), next(nullptr) {}
    ListNode(int value) : value(value), next(nullptr) {}
    ListNode(int value, ListNode* next) : value(value), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2){

        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        int carry_value = 0;    
        
        while(list1 != nullptr || list2 != nullptr || carry_value != 0){
            int list1_value = (list1 != nullptr) ? list1->value : 0;
            int list2_value = (list2 != nullptr) ? list2->value : 0;

            int sum_values = list1_value + list2_value + carry_value;            
            int node_values = (sum_values > 9) ? sum_values - 10 : sum_values;

            carry_value = (sum_values > 9) ? 1 : 0;
       
            ListNode* newNode = new ListNode(node_values);

            if(head == nullptr){ 
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }            

            list1 = (list1 == nullptr) ? nullptr : list1->next;
            list2 = (list2 == nullptr) ? nullptr : list2->next;            
        }

        return head;
    }    
};

int main(){
    // list1 = 2 4 3
    ListNode* list1 = new ListNode(2);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(3);

    // list2 = 5 6 4
    ListNode* list2 = new ListNode(5);
    list2->next = new ListNode(6);
    list2->next->next = new ListNode(4);

    Solution Solution;

    ListNode* Result = Solution.addTwoNumbers(list1, list2);    

    while(Result != nullptr){
        cout << Result->value;
        Result = Result->next;
    }
    cout << endl;

    return 0;
}