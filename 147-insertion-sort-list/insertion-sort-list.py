class Solution:
    def insertionSortList(self, head):
        cur = head
        while cur:
            j = head
            while j != cur:
                if j.val > cur.val: 
                    j.val, cur.val = cur.val, j.val
                j = j.next
            cur = cur.next
        return head