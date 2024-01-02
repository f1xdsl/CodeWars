//You are given two non - empty linked lists representing two non - negative integers.
// The digits are stored in reverse order, and each of their nodes contains a single digit.
// Add the two numbers and return the sum as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Example 1:
//
//2->4->3
//5->6->4
//
//7->0->8
//
//Input: l1 = [2, 4, 3], l2 = [5, 6, 4]
//Output : [7, 0, 8]
//Explanation : 342 + 465 = 807.
//Example 2 :
//
//    Input : l1 = [0], l2 = [0]
//    Output : [0]
//    Example 3 :
//
//    Input : l1 = [9, 9, 9, 9, 9, 9, 9], l2 = [9, 9, 9, 9]
//    Output : [8, 9, 9, 9, 0, 0, 0, 1]


#import<cmath>
#import<string>
class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::string strx = "";

        std::string stry = "";
        while (l1) {
            strx = std::to_string(l1->val) + strx;
            l1 = l1->next;
        }
        while (l2) {
            stry = std::to_string(l2->val) + stry;
            l2 = l2->next;
        }
        std::reverse(stry.begin(), stry.end());
        std::reverse(strx.begin(), strx.end());

        std::string str = "";
        int buff = 0;
        for (int i = 0; i < (strx.length() > stry.length() ? strx.length() : stry.length()); i++) {
            if (i < strx.length() && i < stry.length()) {
                str = std::to_string((((strx[i] - '0' + stry[i] - '0') + buff) % 10)) + str;
                buff = ((strx[i] - '0' + stry[i] - '0') + buff) / 10;
            }
            else if (i >= strx.length()) {
                str = std::to_string((((stry[i] - '0') + buff) % 10)) + str;
                buff = ((stry[i] - '0') + buff) / 10;
            }
            else {
                str = std::to_string((((strx[i] - '0') + buff) % 10)) + str;
                buff = ((strx[i] - '0') + buff) / 10;
            }
        }
        if (buff) str = std::to_string(buff) + str;
        ListNode* l3 = new ListNode;
        if (str == "0") l3->val = 0;
        else {
            l3->val = str[0] - '0';
            str.erase(0, 1);
            while (!str.empty()) {
                ListNode* tmp = new ListNode(str[0] - '0', l3);
                l3 = tmp;
                str.erase(0, 1);
            }

        }
        return l3;
    }
};