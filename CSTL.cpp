

template <class T>
struct nodeS
{
    T data;
    struct nodeS<T> * next;
};

template <class T>
class SinglyLL
{
    public :
        struct nodeS<T> * First;

        SinglyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPosition(T no, int pos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int pos);

        void Display();
        int Count();
};

template <class T>
SinglyLL<T> :: SinglyLL()
{
    First = NULL;
}

template <class T>
void SinglyLL<T> :: InsertFirst(T no)
{
    struct nodeS<T> * newn = new struct nodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
}

template <class T>
void SinglyLL<T> :: InsertLast(T no)
{
    struct nodeS<T> * newn = new struct nodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        struct nodeS<T> * temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
}

template <class T>
void SinglyLL<T> :: InsertAtPosition(T no, int pos)
{
    int nodeCount = Count();

    if((pos < 1) || (pos > nodeCount+1))
    {
        cout<<"Invalid postion"<<"\n";
        return;
    }
    
    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == nodeCount+1)
    {
        InsertLast(no);
    }
    else
    {
        struct nodeS<T> * newn = new struct nodeS<T>;
        newn->data = no;
        newn->next = NULL;

        struct nodeS<T> * temp = First;

        for(int iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

template <class T>
void SinglyLL<T> :: DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else 
    {
        struct nodeS<T> * temp = First;
        First = First->next;
        delete temp;
    }
}

template <class T>
void SinglyLL<T> :: DeleteLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct nodeS<T> * temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete (temp->next);
        temp->next = NULL;
    }
}

template <class T>
void SinglyLL<T> :: DeleteAtPosition(int pos)
{
    int nodeCount = Count();

    if((pos < 1) || (pos > nodeCount+1))
    {
        cout<<"Invalid postion"<<"\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == nodeCount)
    {
        DeleteLast();
    }
    else
    {
        struct nodeS<T> * temp1 = First;

        for(int iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp1 = temp1->next;
        }
        struct nodeS<T> * temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;
    }
}

template <class T>
void SinglyLL<T> :: Display()
{
    if(First == NULL)
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }

    struct nodeS<T> * temp = First;

    cout<<"Elements of Singly Linear LL :"<<"\n";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

template <class T>
int SinglyLL<T> :: Count()
{
    struct nodeS<T> * temp = First;
    int iCount = 0;

    while(temp != NULL)
    {
        iCount++;
        temp = temp->next;
    }

    return iCount;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
struct nodeD
{
    T data;
    struct nodeD<T> * next;
    struct nodeD<T> * prev;
};

template <class T>
class DoublyLL
{
    public :
        struct nodeD<T>* First;

        DoublyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPosition(T no, int pos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int pos);

        void Display();
        int Count();
};

template <class T>
DoublyLL<T> :: DoublyLL()
{
    First = NULL;
}

template <class T>
void DoublyLL<T> :: InsertFirst(T no)
{
    struct nodeD<T> * newn = new struct nodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
}

template <class T>
void DoublyLL<T> :: InsertLast(T no)
{
    struct nodeD<T> * newn = new struct nodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        struct nodeD<T> * temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
}

template <class T>
void DoublyLL<T> :: InsertAtPosition(T no, int pos)
{
    int NodeCount = Count();

    if((pos < 1) || (pos > NodeCount+1))
    {
        cout<<"Invalid postion"<<"\n";
        return;
    }
    
    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == NodeCount+1)
    {
        InsertLast(no);
    }
    else
    {
        struct nodeD<T> * newn = new struct nodeD<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        struct nodeD<T> * temp = First;

        for(int iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;
    }
}

template <class T>
void DoublyLL<T> :: DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else 
    {
        struct nodeD<T> * temp = First;
        First = First->next;
        First->prev = NULL;
        delete temp;
    }
}

template <class T>
void DoublyLL<T> :: DeleteLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct nodeD<T> * temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete (temp->next);
        temp->next = NULL;
    }
}

template <class T>
void DoublyLL<T> :: DeleteAtPosition(int pos)
{
    int NodeCount = Count();

    if((pos < 1) || (pos > NodeCount+1))
    {
        cout<<"Invalid postion"<<"\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == NodeCount)
    {
        DeleteLast();
    }
    else
    {
        struct nodeD<T> * temp = First;

        for(int iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        
        temp->next = temp->next->next;
        delete (temp->next->prev);
        temp->next->prev = temp;
    }
}

template <class T>
void DoublyLL<T> :: Display()
{
    if(First == NULL)
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }

    struct nodeD<T> * temp = First;

    cout<<"Elements of Doubly Linear LL :"<<"\n";

    cout<<"NULL<=>";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

template <class T>
int DoublyLL<T> :: Count()
{
    int iCount = 0;

    struct nodeD<T> * temp = First;

    while(temp != NULL)
    {
        iCount++;
        temp = temp->next;
    } 

    return iCount;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCL
{
    public :
        struct nodeS<T> * First;
        struct nodeS<T> * Last;

        SinglyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPosition(T no, int pos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int pos);

        void Display();
        int Count();

};

template <class T>
SinglyCL<T> :: SinglyCL()
{
    First = NULL;
    Last = NULL;
}

template <class T>
void SinglyCL<T> :: InsertFirst(T no)
{
    struct nodeS<T> * newn = new struct nodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = Last = newn;
        Last->next = First;
    }
    else
    {
        newn->next = First;
        First = newn;
        Last->next = First;
    }
}

template <class T>
void SinglyCL<T> :: InsertLast(T no)
{
    struct nodeS<T> * newn = new struct nodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = Last = newn;
        Last->next = First;
    }
    else
    {
        Last->next = newn;
        Last = newn;
        Last->next = First;
    }
}

template <class T>
void SinglyCL<T> :: InsertAtPosition(T no, int pos)
{
    int NodeCount = Count();

    if((pos < 1) || (pos > NodeCount+1))
    {
        cout<<"Invalid postion"<<"\n";
        return;
    }
    
    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == NodeCount+1)
    {
        InsertLast(no);
    }
    else
    {
        struct nodeS<T> * newn = new struct nodeS<T>;
        newn->data = no;
        newn->next = NULL;

        struct nodeS<T> * temp = First;

        for(int iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

template <class T>
void SinglyCL<T> :: DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else 
    {
        First = First->next;
        delete (Last->next);
        Last->next = First;
    }
}

template <class T>
void SinglyCL<T> :: DeleteLast()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        struct nodeS<T> * temp = First;

        while(temp->next != Last)
        {
            temp = temp->next;
        }

        delete (temp->next);

        Last = temp;
        Last->next = First;
    }
}

template <class T>
void SinglyCL<T> :: DeleteAtPosition(int pos)
{
    int NodeCount = Count();

    if((pos < 1) || (pos > NodeCount+1))
    {
        cout<<"Invalid postion"<<"\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == NodeCount)
    {
        DeleteLast();
    }
    else
    {
        struct nodeS<T> * temp1 = First;

        for(int iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp1 = temp1->next;
        }
        struct nodeS<T> * temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;
    }
}

template <class T>
void SinglyCL<T> :: Display()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }

    struct nodeS<T> * temp = First;

    cout<<"Elements of Singly Circular LL :"<<"\n";

    do
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }while(temp != First);

    cout<<"\n";
}

template <class T>
int SinglyCL<T> :: Count()
{
    int iCount = 0;
    struct nodeS<T> * temp = First;

    do
    {
        iCount++;
        temp = temp->next;
    }while(temp != First);

    return iCount;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCL
{
    public :
        struct nodeD<T> * First;
        struct nodeD<T> * Last;

        DoublyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPosition(T no, int pos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int pos);

        void Display();
        int Count();

};

template <class T>
DoublyCL<T> :: DoublyCL()
{
    First = NULL;
    Last = NULL;
}

template <class T>
void DoublyCL<T> :: InsertFirst(T no)
{
    struct nodeD<T> * newn = new struct nodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }

    Last->next = First;
    First->prev = Last;
}

template <class T>
void DoublyCL<T> :: InsertLast(T no)
{
    struct nodeD<T> * newn = new struct nodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = Last = newn;
    }
    else
    {
        Last->next = newn;
        newn->prev = Last;
        Last = newn;
    }

    Last->next = First;
    First->prev = Last;
}

template <class T>
void DoublyCL<T> :: InsertAtPosition(T no, int pos)
{
    int nodeDCount = Count();

    if((pos < 1) || (pos > nodeDCount+1))
    {
        cout<<"Invalid postion"<<"\n";
        return;
    }
    
    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == nodeDCount+1)
    {
        InsertLast(no);
    }
    else
    {
        struct nodeD<T> * newn = new struct nodeD<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        struct nodeD<T> * temp = First;

        for(int iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;
    }
}

template <class T>
void DoublyCL<T> :: DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else 
    {
        First = First->next;
        delete (Last->next);
        Last->next = First;
        First->prev = Last;
    }
}

template <class T>
void DoublyCL<T> :: DeleteLast()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        Last = Last->prev;
        delete (First->prev);

        First->prev = Last;
        Last->next = First;
    }
}

template <class T>
void DoublyCL<T> :: DeleteAtPosition(int pos)
{
    int nodeDCount = Count();

    if((pos < 1) || (pos > nodeDCount+1))
    {
        cout<<"Invalid postion"<<"\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == nodeDCount)
    {
        DeleteLast();
    }
    else
    {
        struct nodeD<T> * temp = First;

        for(int iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        
        temp->next = temp->next->next;
        delete (temp->next->prev);
        temp->next->prev = temp;

    }
}

template <class T>
void DoublyCL<T> :: Display()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }

    struct nodeD<T> * temp = First;

    cout<<"Elements of Doubly Circular LL :"<<"\n";

    do
    {
        cout<<"<=>| "<<temp->data<<" |";
        temp = temp->next;
    }while(temp != Last->next);

    cout<<"<=>\n";
}

template <class T>
int DoublyCL<T> :: Count()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"Linked list is empty"<<"\n";
        return 0;
    }

    int iCount = 0;
    struct nodeD<T> * temp = First;

    do
    {
        iCount++;
        temp = temp->next;
    }while(temp != Last->next);

    return iCount;
}
