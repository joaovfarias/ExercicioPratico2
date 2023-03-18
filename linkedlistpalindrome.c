#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *Push(struct ListNode *head, int value);
void PrintList(struct ListNode *head);
bool isPalindrome(struct ListNode* head);

int main(){

    struct ListNode *list = NULL;
    list = Push(list, 1);
    list = Push(list, 0);
    list = Push(list, 1);

    PrintList(list);
    printf("%d", isPalindrome(list));

}

struct ListNode *Push(struct ListNode *head, int value){

    struct ListNode *element = (struct ListNode *)malloc(sizeof(struct ListNode));
    element->val = value;

    if (head == NULL){
        head = element;
        element->next = NULL;
        return head;
    }

    element->next = head;
    head = element;
    return head;
}

void PrintList(struct ListNode *head){

    for (struct ListNode *tmp = head; tmp != NULL; tmp = tmp->next){
        printf("%d\n", tmp->val);
    }
    printf("\n");
}


bool isPalindrome(struct ListNode* head){

    if (head == NULL){
        return false;
    }

    if (head->next == NULL){
        return true;
    }

    int count = 0;
    int idx = 0;
    int half;
    int *firstHalf;
    int *secondHalf;
    struct ListNode *lastTmp;

    for (struct ListNode *tmp = head; tmp != NULL; tmp = tmp->next){
        count++;
    }
    if (count % 2 == 0){
        half = count / 2;
        firstHalf = malloc(sizeof(int) * half);
        secondHalf = malloc(sizeof(int) * half);
        for (struct ListNode *tmp = head; idx != half; tmp = tmp->next){
            firstHalf[idx] = tmp->val;
            idx++;
            lastTmp = tmp->next;
        }
        idx = half - 1;
        for (struct ListNode *tmp = lastTmp; idx != -1; tmp = tmp->next){
            secondHalf[idx] = tmp->val;
            idx--;
        }

        for (int i = 0; i < half; i++){
            if (firstHalf[i] != secondHalf[i]){
                return false;
            }
        }
        return true;

    }
    else{
        half  = (count / 2) + 1;
        firstHalf = malloc(sizeof(int) * (half - 1));
        secondHalf = malloc(sizeof(int) * (half - 1));
        for (struct ListNode *tmp = head; idx != half - 1; tmp = tmp->next){
            firstHalf[idx] = tmp->val;
            idx++;
            lastTmp = tmp->next;
        }
        idx = half - 2;
        for (struct ListNode *tmp = lastTmp->next; idx != -1; tmp = tmp->next){
            secondHalf[idx] = tmp->val;
            idx--;
        }

        for (int i = 0; i < half - 1; i++){
            if (firstHalf[i] != secondHalf[i]){
                return false;
            }
        }
        return true;
    }


}