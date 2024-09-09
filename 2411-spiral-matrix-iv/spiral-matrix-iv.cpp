/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m,vector<int> (n,-1));
        ListNode* temp=head;
        int topRow=0;
        int bottomRow=m-1;
        int leftColumn=0;
        int rightColumn=n-1;
        while(temp){
            for(int col=leftColumn;col<=rightColumn && temp;col++){
                matrix[topRow][col]=temp->val;
                temp=temp->next;
            }
            topRow++;
            for(int row=topRow;row<=bottomRow && temp; row++){
                matrix[row][rightColumn]=temp->val;
                temp=temp->next;
            }
            rightColumn--;
            for(int col=rightColumn;col>=leftColumn && temp;col--){
                matrix[bottomRow][col]=temp->val;
                temp=temp->next;
            }
            bottomRow--;
            for(int row=bottomRow;row>=topRow && temp;row--){
                matrix[row][leftColumn]=temp->val;
                temp=temp->next;
            }
            leftColumn++;
        }
        return matrix;
    }
};