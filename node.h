template <class T>
class Node {
    public:
        T data; // hash data
        Node *next; // next in LinkedList
        Node(){
           // data = NULL;
            next = nullptr;
        }
        Node(T val){
            data = val;
            next = nullptr;
        }
};