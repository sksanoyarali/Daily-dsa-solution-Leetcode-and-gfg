// #Merge two sorted linked lists
class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        Node* newhead=new Node(-1);
        Node * curr=newhead;
        while(head1!=NULL && head2!=NULL){
            if(head1->data<head2->data){
                curr->next=head1;
                curr=head1;
                head1=head1->next;
            }
            else{
                curr->next=head2;
                curr=head2;
                head2=head2->next;
            }
        }
        if(head1!=NULL){
            curr->next=head1;
        }
        if(head2!=NULL){
            curr->next=head2;
        }
        
        return newhead->next;
    }
};