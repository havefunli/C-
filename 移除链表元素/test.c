#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct ListNode* find_head(struct ListNode* ptr, int val)
{
    while (ptr != NULL)
    {
        if (ptr->val == val)
        {
            struct ListNode* ps = ptr;
            ptr = ptr->next;
            free(ps);
            ps = NULL;
        }
        else
            return ptr;
    }
}

struct ListNode* removeElements(struct ListNode* head, int val)
{
    if (head == NULL)
    {
        return head;
    }
    head = find_head(head, val);

    struct ListNode* ptr = head;
    struct ListNode* ps = head->next;
    if (head == NULL)
    {
        return head;
    }

    while (ps)
    {
        if (ps->val == val)
        {
            ptr->next = ps->next;
            free(ps);
            ps = ptr->next;
        }
        else
        {
            ptr = ps;
            ps = ptr->next;
        }
    }

    return head;
}