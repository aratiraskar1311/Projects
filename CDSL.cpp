#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////////
//
//Generic code of Singly Linear LL
//
/////////////////////////////////////////////////////////////////////

template<class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template<class T>
class SinglyLL
{
    private:
        struct nodeSL<T> * First;
        int iCount;

public:
    SinglyLL();

    void Display();
    int Count();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);

    T Addition();
    int EvenCount();
    int OddCount();
    int Frequency(T No);
    bool Search(T No);
    int FirstOccurance(T No);
    int LastOccurance(T No);
    void SumDigits();
    T FactorsAddition(T iNo);
    void SumFactors();
    bool CheckPerfect(T iNo);
    void DisplayPerfect();
    int MiddleElement();
    int MiddleElementX();


};

template<class T>
SinglyLL<T>::SinglyLL()
{
    cout<<"Inside constructor\n";
    First = NULL;
    iCount = 0;
}

template<class T>
void SinglyLL<T>::Display()
{
    struct nodeSL<T> * temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"|->";
        temp = temp->next;

    }
    printf("NULL\n");
}

template<class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template<class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct nodeSL<T> * newn = NULL;

    newn = new nodeSL<T> ;        //dynamic memory alloacte 

    newn->data = No;
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
    iCount++;

}

template<class T>
void SinglyLL<T>::InsertLast(T No)
{
     struct nodeSL<T> * newn = NULL;
     struct nodeSL<T> * temp = First;

    newn = new nodeSL<T>;        

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;

    }
    iCount++;
}

template<class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeSL<T> * newn = NULL;
    int i = 0;
    struct nodeSL<T> * temp;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else 
    {
        temp = First;
        
        newn = new nodeSL<T>;
        newn->data = No;
        newn->next = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp -> next = newn;
        iCount++;
    }
}

template<class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First -> next;
        delete temp;
    }
    iCount--;
}

template<class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = NULL;
    }
    iCount--;
}

template<class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSL<T> * temp1;
    struct nodeSL<T> * temp2;


    if((iPos < 1)||(iPos > iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }
}

template <class T>
T SinglyLL<T>::Addition()
{
    T iSum = 0;

    while(First != NULL)
    {
        iSum = iSum + (First -> data);
        First = First -> next;
    }
    return iSum;
}

template <class T>
int SinglyLL<T>::EvenCount()
{
    int iCount = 0;

    while(First != NULL)
    {
        if((First -> data) % 2 == 0)
        {
            iCount++;
        }
         First = First -> next;
    }
    return iCount;
} 

template <class T>
int SinglyLL<T>::OddCount()
{
    int iCount = 0;

    while(First != NULL)
    {
        if((First -> data) % 2 != 0)
        {
            iCount++;
        }
         First = First -> next;
    }
    return iCount;
} 

template <class T>
int SinglyLL<T>::Frequency(T No)
{
    int iCount = 0;

    while(First != NULL)
    {
        if(First -> data == No)
        {
            iCount++;
        }
        First = First -> next;
    }
    return iCount;
}

template <class T>
bool SinglyLL<T>::Search(T No)
{
    bool bFlag = false;

    while(First != NULL)
    {
        if((First -> data) == No)
        {
            bFlag = true;
            break;
        }
        First = First -> next;
    }
    return bFlag;
}

template <class T>
int SinglyLL<T>::FirstOccurance(T No)
{
    int iCount = 1;
    int iPos = -1;

    while(First != NULL)
    {
        if((First -> data) == No)
        {
            iPos = iCount;
            break;
        }
        iCount++;
        First = First -> next;
    }
    return iPos;
}

template <class T>
int SinglyLL<T>::LastOccurance(T No)
{
    int iCount = 1;
    int iPos = -1;

    while(First != NULL)
    {
        if((First -> data) == No)
        {
            iPos = iCount;
        }
        iCount++;
        First = First -> next;
    }
    return iPos;
}

template <class T>
void SinglyLL<T>::SumDigits()
{
    T iDigit = 0;
    T iSum = 0;
    T iNo = 0;

    while(First != NULL)
    {
        iNo = First -> data;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iSum = iSum + iDigit;
            iNo = iNo / 10;
        }
        cout<<iSum<<endl;
        iSum = 0;

        First = First -> next;    
    }   
}

template <class T>
T SinglyLL<T>::FactorsAddition(T iNo)
{
    int i = 0;
    T iSum = 0;

        for(i = 1; i <= iNo/2; i++)
        {
            if((iNo % i) == 0)
            {
                iSum = iSum + i;
            }
        }
       return iSum;
}

template <class T>
void SinglyLL<T>::SumFactors()
{
    while(First != NULL)
    {
       if(FactorsAddition(First -> data) == true)
        {
            cout<<First -> data<<endl;
        }
        First = First -> next;
        
    }
}

template <class T>
bool SinglyLL<T>::CheckPerfect(T iNo)
{
    int i = 0;
    T iSum = 0;

        for(i = 1; i <= iNo/2; i++)
        {
            if((iNo % i) == 0)
            {
                iSum = iSum + i;
            }
        }
       
       if(iSum == iNo)
       {
            return true;
       }
       else
       {
            return false;
       }
}

template <class T>
void SinglyLL<T>::DisplayPerfect()
{
    while(First != NULL)
    {
        if(CheckPerfect(First -> data) == true)
        {
            cout<<"Perfect number of LL is : "<<First -> data<<endl;
        }
    
        First = First -> next;   
    }
}

template <class T>
int SinglyLL<T>::MiddleElement()
{
    int iCnt = 0;
    struct nodeSL<T> * temp = First;
    int iPos = 0;
    int i = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp -> next;
    }
    iPos = iCnt/2;

    for(i = 1; i <= iPos; i++)
    {
        First = First -> next;
    }
    return First -> data;
}

template <class T>
int SinglyLL<T>::MiddleElementX()
{
    struct nodeSL<T> * Teacher = First;
    struct nodeSL<T> * Student = First;

    while((Teacher !=NULL) && (Teacher -> next != NULL))
    {
        Teacher = Teacher -> next->next;
        Student = Student -> next;
    }

    return (Student -> data);
}



/////////////////////////////////////////////////////////////
//
// Generic Code of Singly Circular LL
//
/////////////////////////////////////////////////////////////

template<class T>
struct nodeSC
{
    T data;
    struct nodeSC<T> *next;
};

template<class T>
class SinglyCLL
{
    private:
        struct nodeSC<T> * First;
        struct nodeSC<T> * Last;
        int iCount;

    public:
        SinglyCLL();
        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        T Addition();
        int EvenCount();
        int OddCount();
        int Frequency(T No);
        bool Search(T No);
        int FirstOccurance(T No);
        int LastOccurance(T No);
        void SumDigits();
        T FactorsAddition(T iNo);
        void SumFactors();
        bool CheckPerfect(T iNo);
        void DisplayPerfect();
        int MiddleElement();
        int MiddleElementX();
    
};

template<class T>
SinglyCLL<T>::SinglyCLL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template<class T>
void SinglyCLL<T>::Display()
{
    struct nodeSC<T> * temp = NULL;

    if((First == NULL) && (Last == NULL))
    {
        cout<<"LL is empty"<<endl;
        return;
    }

    temp = First;
    do
    {
        cout<<"|"<<temp -> data<<"|->";
        temp = temp -> next;
    }while(temp != First);
    cout<<endl;
}

template<class T>
int SinglyCLL<T>::Count()
{

    return iCount;
}

template<class T>
void SinglyCLL<T>::InsertFirst(T No)
{
    struct nodeSC<T> * newn = NULL;

    newn = new nodeSC<T>;

    newn -> data = No;
    newn -> next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn -> next = First;
        First = newn;
    }
    Last -> next = First;
    iCount++;
}

template<class T>
void SinglyCLL<T>::InsertLast(T No)
{
    struct nodeSC<T> * newn = NULL;

    newn = new nodeSC<T>;

    newn -> data = No;
    newn -> next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last -> next = newn;
        Last = newn;
    }
    Last -> next = First;
    iCount++;
}

template<class T>
void SinglyCLL<T>::InsertAtPos(T No, int iPos)
{
    int i = 0;
    struct nodeSC<T> * newn = NULL;
    struct nodeSC<T> * temp = NULL;


    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid Position"<<endl;
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeSC<T>;

        newn -> data = No;
        newn -> next = NULL;

        temp = First;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;
        iCount++;
    }
}

template<class T>
void SinglyCLL<T>::DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First -> next;
        delete Last -> next;
        Last -> next = First;  
    }
    iCount--;
}

template<class T>
void SinglyCLL<T>::DeleteLast()
{
    struct nodeSC<T> * temp = NULL;

    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        temp = First;

        while(temp -> next != Last)
        {
            temp = temp -> next;
        }
        temp -> next = First;
        delete Last;
        Last = temp;
        
    }
    iCount--;
}

template<class T>
void SinglyCLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSC<T> * temp1 = NULL;
    struct nodeSC<T> * temp2 = NULL;


    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1 -> next;
        }
        temp2  = temp1 -> next;
        temp1 -> next = temp2 -> next;
        delete temp2;
        iCount--;
    }
}

template <class T>
T SinglyCLL<T>::Addition()
{
    T iSum = 0;

    while(First != NULL)
    {
        iSum = iSum + (First -> data);
        First = First -> next;
    }
    return iSum;
}

template <class T>
int SinglyCLL<T>::EvenCount()
{
    int iCount = 0;

    while(First != NULL)
    {
        if((First -> data) % 2 == 0)
        {
            iCount++;
        }
         First = First -> next;
    }
    return iCount;
} 

template <class T>
int SinglyCLL<T>::OddCount()
{
    int iCount = 0;

    while(First != NULL)
    {
        if((First -> data) % 2 != 0)
        {
            iCount++;
        }
         First = First -> next;
    }
    return iCount;
} 

template <class T>
int SinglyCLL<T>::Frequency(T No)
{
    int iCount = 0;

    while(First != NULL)
    {
        if(First -> data == No)
        {
            iCount++;
        }
        First = First -> next;
    }
    return iCount;
}

template <class T>
bool SinglyCLL<T>::Search(T No)
{
    bool bFlag = false;

    while(First != NULL)
    {
        if((First -> data) == No)
        {
            bFlag = true;
            break;
        }
        First = First -> next;
    }
    return bFlag;
}

template <class T>
int SinglyCLL<T>::FirstOccurance(T No)
{
    int iCount = 1;
    int iPos = -1;

    while(First != NULL)
    {
        if((First -> data) == No)
        {
            iPos = iCount;
            break;
        }
        iCount++;
        First = First -> next;
    }
    return iPos;
}

template <class T>
int SinglyCLL<T>::LastOccurance(T No)
{
    int iCount = 1;
    int iPos = -1;

    while(First != NULL)
    {
        if((First -> data) == No)
        {
            iPos = iCount;
        }
        iCount++;
        First = First -> next;
    }
    return iPos;
}

template <class T>
void SinglyCLL<T>::SumDigits()
{
    T iDigit = 0;
    T iSum = 0;
    T iNo = 0;

    while(First != NULL)
    {
        iNo = First -> data;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iSum = iSum + iDigit;
            iNo = iNo / 10;
        }
        cout<<iSum<<endl;
        iSum = 0;

        First = First -> next;    
    }   
}

template <class T>
T SinglyCLL<T>::FactorsAddition(T iNo)
{
    int i = 0;
    T iSum = 0;

        for(i = 1; i <= iNo/2; i++)
        {
            if((iNo % i) == 0)
            {
                iSum = iSum + i;
            }
        }
       return iSum;
}

template <class T>
void SinglyCLL<T>::SumFactors()
{
    while(First != NULL)
    {
       if(FactorsAddition(First -> data) == true)
        {
            cout<<First -> data<<endl;
        }
        First = First -> next;
        
    }
}

template <class T>
bool SinglyCLL<T>::CheckPerfect(T iNo)
{
    int i = 0;
    T iSum = 0;

        for(i = 1; i <= iNo/2; i++)
        {
            if((iNo % i) == 0)
            {
                iSum = iSum + i;
            }
        }
       
       if(iSum == iNo)
       {
            return true;
       }
       else
       {
            return false;
       }
}

template <class T>
void SinglyCLL<T>::DisplayPerfect()
{
    while(First != NULL)
    {
        if(CheckPerfect(First -> data) == true)
        {
            cout<<"Perfect number of LL is : "<<First -> data<<endl;
        }
    
        First = First -> next;   
    }
}

template <class T>
int SinglyCLL<T>::MiddleElement()
{
    int iCnt = 0;
    struct nodeSC<T> * temp = First;
    int iPos = 0;
    int i = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp -> next;
    }
    iPos = iCnt/2;

    for(i = 1; i <= iPos; i++)
    {
        First = First -> next;
    }
    return First -> data;
}

template <class T>
int SinglyCLL<T>::MiddleElementX()
{
    struct nodeSC<T> * Teacher = First;
    struct nodeSC<T> * Student = First;

    while((Teacher !=NULL) && (Teacher -> next != NULL))
    {
        Teacher = Teacher -> next->next;
        Student = Student -> next;
    }

    return (Student -> data);
}

/////////////////////////////////////////////////////////////
//
// Generic code of Doubly Linear LL
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeDL
{
    T data;
    struct nodeDL<T> *next;
    struct nodeDL<T> *prev;
};

template <class T>
class DoublyLL
{
    private:
        struct nodeDL<T> * First;
        int iCount;

    public:
        DoublyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        T Addition();
        int EvenCount();
        int OddCount();
        int Frequency(T No);
        bool Search(T No);
        int FirstOccurance(T No);
        int LastOccurance(T No);
        void SumDigits();
        T FactorsAddition(T iNo);
        void SumFactors();
        bool CheckPerfect(T iNo);
        void DisplayPerfect();
        int MiddleElement();
        int MiddleElementX();
};
    
template <class T>
DoublyLL<T>::DoublyLL()
{
    cout<<"Inside Constructor\n";
    First = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T>::Display()
{
    struct nodeDL<T> * temp = First;

    printf("NULL<=>");
    while(temp != NULL)
    {
        cout<<"|"<<temp -> data<<"|<=>";
        temp = temp -> next;
    }
    printf("NULL\n");

}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T No)
{
    struct nodeDL<T> * newn = NULL;

    newn = new nodeDL<T>;

    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First -> prev = newn;

        First = newn;
    }
    iCount++;

}

template <class T>
void DoublyLL<T>::InsertLast(T No)
{
    struct nodeDL<T> * newn = NULL;
    struct nodeDL<T> * temp = First;

    newn = new nodeDL<T>;

    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;

        }
        temp -> next = newn;
        newn -> prev = temp;
        newn -> next = NULL;
    }
    iCount++;

}

template <class T>
void DoublyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDL<T> * newn = NULL;
    struct nodeDL<T> * temp = First;
    int i = 0;

    newn = new nodeDL<T>;

    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }
            temp -> next -> prev = newn;
            newn -> next = temp -> next;
            newn -> prev = temp;
            temp -> next = newn;
            iCount++;
        }
        
    }

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    struct nodeDL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = temp -> next;
        First -> next -> prev = NULL;
        delete temp;

    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    struct nodeDL<T> * temp1 = First;
    struct nodeDL<T> * temp2 = NULL;

    if(First == NULL)
    {
        cout<<"LL is empty";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp1 -> next -> next != NULL)
        {
            temp1 = temp1 -> next;
        }
            temp2 = temp1 -> next;
            temp1 -> next = NULL;
            delete temp2;

        }
        iCount--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    struct nodeDL<T> * temp1 = First;
    struct nodeDL<T> * temp2 = NULL;

    int i = 0;


    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1 -> next;
        }
            

        temp2 = temp1 -> next; 
        temp1 -> next = temp2 -> next;
        temp2 -> next -> prev = temp1;
        delete temp2;

        iCount--;
    }
        
}

template <class T>
T DoublyLL<T>::Addition()
{
    T iSum = 0;

    while(First != NULL)
    {
        iSum = iSum + (First -> data);
        First = First -> next;
    }
    return iSum;
}

template <class T>
int DoublyLL<T>::EvenCount()
{
    int iCount = 0;

    while(First != NULL)
    {
        if((First -> data) % 2 == 0)
        {
            iCount++;
        }
         First = First -> next;
    }
    return iCount;
} 

template <class T>
int DoublyLL<T>::OddCount()
{
    int iCount = 0;

    while(First != NULL)
    {
        if((First -> data) % 2 != 0)
        {
            iCount++;
        }
         First = First -> next;
    }
    return iCount;
} 

template <class T>
int DoublyLL<T>::Frequency(T No)
{
    int iCount = 0;

    while(First != NULL)
    {
        if(First -> data == No)
        {
            iCount++;
        }
        First = First -> next;
    }
    return iCount;
}

template <class T>
bool DoublyLL<T>::Search(T No)
{
    bool bFlag = false;

    while(First != NULL)
    {
        if((First -> data) == No)
        {
            bFlag = true;
            break;
        }
        First = First -> next;
    }
    return bFlag;
}

template <class T>
int DoublyLL<T>::FirstOccurance(T No)
{
    int iCount = 1;
    int iPos = -1;

    while(First != NULL)
    {
        if((First -> data) == No)
        {
            iPos = iCount;
            break;
        }
        iCount++;
        First = First -> next;
    }
    return iPos;
}

template <class T>
int DoublyLL<T>::LastOccurance(T No)
{
    int iCount = 1;
    int iPos = -1;

    while(First != NULL)
    {
        if((First -> data) == No)
        {
            iPos = iCount;
        }
        iCount++;
        First = First -> next;
    }
    return iPos;
}

template <class T>
void DoublyLL<T>::SumDigits()
{
    T iDigit = 0;
    T iSum = 0;
    T iNo = 0;

    while(First != NULL)
    {
        iNo = First -> data;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iSum = iSum + iDigit;
            iNo = iNo / 10;
        }
        cout<<iSum<<endl;
        iSum = 0;

        First = First -> next;    
    }   
}

template <class T>
T DoublyLL<T>::FactorsAddition(T iNo)
{
    int i = 0;
    T iSum = 0;

        for(i = 1; i <= iNo/2; i++)
        {
            if((iNo % i) == 0)
            {
                iSum = iSum + i;
            }
        }
       return iSum;
}

template <class T>
void DoublyLL<T>::SumFactors()
{
    while(First != NULL)
    {
       if(FactorsAddition(First -> data) == true)
        {
            cout<<First -> data<<endl;
        }
        First = First -> next;
        
    }
}

template <class T>
bool DoublyLL<T>::CheckPerfect(T iNo)
{
    int i = 0;
    T iSum = 0;

        for(i = 1; i <= iNo/2; i++)
        {
            if((iNo % i) == 0)
            {
                iSum = iSum + i;
            }
        }
       
       if(iSum == iNo)
       {
            return true;
       }
       else
       {
            return false;
       }
}

template <class T>
void DoublyLL<T>::DisplayPerfect()
{
    while(First != NULL)
    {
        if(CheckPerfect(First -> data) == true)
        {
            cout<<"Perfect number of LL is : "<<First -> data<<endl;
        }
    
        First = First -> next;   
    }
}

template <class T>
int DoublyLL<T>::MiddleElement()
{
    int iCnt = 0;
    struct nodeDL<T> * temp = First;
    int iPos = 0;
    int i = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp -> next;
    }
    iPos = iCnt/2;

    for(i = 1; i <= iPos; i++)
    {
        First = First -> next;
    }
    return First -> data;
}

template <class T>
int DoublyLL<T>::MiddleElementX()
{
    struct nodeDL<T> * Teacher = First;
    struct nodeDL<T> * Student = First;

    while((Teacher !=NULL) && (Teacher -> next != NULL))
    {
        Teacher = Teacher -> next->next;
        Student = Student -> next;
    }

    return (Student -> data);
}




//////////////////////////////////////////////////////////////////////////
//
//Generic code of Doubly Circular LL
//
/////////////////////////////////////////////////////////////////////////

template<class T>
struct nodeDC
{
    T data;
    struct nodeDC<T> *next;
    struct nodeDC<T> *prev;
};

template<class T>
class DoublyCL
{
    private:
        struct nodeDC<T> * First;
        struct nodeDC<T> * Last;
        int iCount;

    public:
        DoublyCL(); 

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        T Addition();
        int EvenCount();
        int OddCount();
        int Frequency(T No);
        bool Search(T No);
        int FirstOccurance(T No);
        int LastOccurance(T No);
        void SumDigits();
        T FactorsAddition(T iNo);
        void SumFactors();
        bool CheckPerfect(T iNo);
        void DisplayPerfect();
        int MiddleElement();
        int MiddleElementX();
};

template<class T>
DoublyCL<T>::DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
} 

template<class T>
void DoublyCL<T>::Display()
{
    if((First == NULL) & (Last == NULL))
    {
        cout<<"Linked list is empty\n";
        return;
    }

    cout<<"<=>";
    do
    {
        cout<<"|"<<First -> data<<"|<=>";
        First = First -> next;
    }while(Last -> next != First);

    cout<<"\n";
    


}

template<class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template<class T>
void DoublyCL<T>::InsertFirst(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
        
    }
    else
    {
        newn -> next = First;
        First -> prev = newn;
        First = newn;
    }
    Last -> next = First;
    First -> prev = Last;
    iCount++;
}

template<class T>
void DoublyCL<T>::InsertLast(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
        
    }
    else
    {
        Last -> next = newn;
        newn -> prev = Last;
        Last = newn;   
    }
    Last -> next = First;
    First -> prev = Last;
    iCount++;
}

template<class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDC<T> * temp = NULL;
    struct nodeDC<T> * newn = NULL;
    int i = 0;


    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeDC<T>;

        newn -> data = No;
        newn -> next = NULL;
        newn -> prev = NULL;

        temp = First;

        for(i = 1; i< iPos-1; i++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next -> prev = newn;

        temp -> next = newn;
        newn -> prev = temp;
    
        iCount++;
    }
}

template<class T>
void DoublyCL<T>::DeleteFirst()
{
    if(First == NULL && Last == NULL)           //Empty LL
    {
        return;
    }
    else if(First == Last)          //single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else                        //more than one node
    {
        First = First -> next;
        delete Last -> next;
        First -> prev = Last;
        Last -> next = First;

    }
    iCount--;

}

template<class T>
void DoublyCL<T>::DeleteLast()
{
    if(First == NULL && Last == NULL)           //Empty LL
    {
        return;
    }
    else if(First == Last)          //single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else                        //more than one node
    {
        Last = Last -> prev;
        delete First -> prev;

        Last -> next = First;
        First -> prev = Last;

    }
    iCount--;
}

template<class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    struct nodeDC<T> * temp = NULL;
    int i = 0;


    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {

        temp = First;

        for(i = 1; i< iPos-1; i++)
        {
            temp = temp -> next;
        }

        temp -> next = temp -> next -> next;
        delete temp -> next -> prev;
        temp -> next -> prev = temp;
        
    
        iCount--;
    }
}

template <class T>
T DoublyCL<T>::Addition()
{
    T iSum = 0;

    while(First != NULL)
    {
        iSum = iSum + (First -> data);
        First = First -> next;
    }
    return iSum;
}

template <class T>
int DoublyCL<T>::EvenCount()
{
    int iCount = 0;

    while(First != NULL)
    {
        if((First -> data) % 2 == 0)
        {
            iCount++;
        }
         First = First -> next;
    }
    return iCount;
} 

template <class T>
int DoublyCL<T>::OddCount()
{
    int iCount = 0;

    while(First != NULL)
    {
        if((First -> data) % 2 != 0)
        {
            iCount++;
        }
         First = First -> next;
    }
    return iCount;
} 

template <class T>
int DoublyCL<T>::Frequency(T No)
{
    int iCount = 0;

    while(First != NULL)
    {
        if(First -> data == No)
        {
            iCount++;
        }
        First = First -> next;
    }
    return iCount;
}

template <class T>
bool DoublyCL<T>::Search(T No)
{
    bool bFlag = false;

    while(First != NULL)
    {
        if((First -> data) == No)
        {
            bFlag = true;
            break;
        }
        First = First -> next;
    }
    return bFlag;
}

template <class T>
int DoublyCL<T>::FirstOccurance(T No)
{
    int iCount = 1;
    int iPos = -1;

    while(First != NULL)
    {
        if((First -> data) == No)
        {
            iPos = iCount;
            break;
        }
        iCount++;
        First = First -> next;
    }
    return iPos;
}

template <class T>
int DoublyCL<T>::LastOccurance(T No)
{
    int iCount = 1;
    int iPos = -1;

    while(First != NULL)
    {
        if((First -> data) == No)
        {
            iPos = iCount;
        }
        iCount++;
        First = First -> next;
    }
    return iPos;
}

template <class T>
void DoublyCL<T>::SumDigits()
{
    T iDigit = 0;
    T iSum = 0;
    T iNo = 0;

    while(First != NULL)
    {
        iNo = First -> data;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iSum = iSum + iDigit;
            iNo = iNo / 10;
        }
        cout<<iSum<<endl;
        iSum = 0;

        First = First -> next;    
    }   
}

template <class T>
T DoublyCL<T>::FactorsAddition(T iNo)
{
    int i = 0;
    T iSum = 0;

        for(i = 1; i <= iNo/2; i++)
        {
            if((iNo % i) == 0)
            {
                iSum = iSum + i;
            }
        }
       return iSum;
}

template <class T>
void DoublyCL<T>::SumFactors()
{
    while(First != NULL)
    {
       if(FactorsAddition(First -> data) == true)
        {
            cout<<First -> data<<endl;
        }
        First = First -> next;
        
    }
}

template <class T>
bool DoublyCL<T>::CheckPerfect(T iNo)
{
    int i = 0;
    T iSum = 0;

        for(i = 1; i <= iNo/2; i++)
        {
            if((iNo % i) == 0)
            {
                iSum = iSum + i;
            }
        }
       
       if(iSum == iNo)
       {
            return true;
       }
       else
       {
            return false;
       }
}

template <class T>
void DoublyCL<T>::DisplayPerfect()
{
    while(First != NULL)
    {
        if(CheckPerfect(First -> data) == true)
        {
            cout<<"Perfect number of LL is : "<<First -> data<<endl;
        }
    
        First = First -> next;   
    }
}

template <class T>
int DoublyCL<T>::MiddleElement()
{
    int iCnt = 0;
    struct nodeDC<T> * temp = First;
    int iPos = 0;
    int i = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp -> next;
    }
    iPos = iCnt/2;

    for(i = 1; i <= iPos; i++)
    {
        First = First -> next;
    }
    return First -> data;
}

template <class T>
int DoublyCL<T>::MiddleElementX()
{
    struct nodeDC<T> * Teacher = First;
    struct nodeDC<T> * Student = First;

    while((Teacher !=NULL) && (Teacher -> next != NULL))
    {
        Teacher = Teacher -> next->next;
        Student = Student -> next;
    }

    return (Student -> data);
}




/////////////////////////////////////////////////////////////
//
// Generic Code of Stack
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeSTACK
{
    T data;
    struct nodeSTACK *next;
};

template <class T>
class Stack
{
    private:
        struct nodeSTACK<T> * First;
        int iCount;

    public:
        Stack();
        void Display();
        int Count();
        void Push(T No);          //InsertFirst()
        int Pop();                  //DeleteFirst()

};

template <class T>
Stack<T>::Stack()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void Stack<T>::Display()
{
    cout<<"Elements of stack are : \n";
    struct nodeSTACK<T> * temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\n";
        temp = temp -> next;
    }
    cout<<"\n";
}

template <class T>
int Stack<T>::Count()
{
    return iCount;
}

template <class T>
void Stack<T>::Push(T No)
{
    struct nodeSTACK<T> * newn = NULL;

    newn = new nodeSTACK<T>;

    newn -> data = No;
    newn -> next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn -> next = First;
        First = newn;
    }
    iCount++;
}   

template <class T>
int Stack<T>::Pop()
{
    int iValue = 0;
    struct nodeSTACK<T> * temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to pop the element as stack is empty\n";
        return -1;
    }
    else
    {
        temp = First;

        iValue = First -> data;
        First = First -> next;
        delete temp;

        iCount--;
    }
    return iValue;
}


/////////////////////////////////////////////////////////////
//
// Code of Queue
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeQUEUE
{
    T data;
    struct nodeQUEUE<T> *next;
};

template <class T>
class Queue
{
    private:
        struct nodeQUEUE<T> * First;
        int iCount;

    public:
        Queue();
        void Display();
        int Count();
        void EnQueue(T No);               //InsertLast()
        int DeQueue();                  //DeleteFirst()

};

template <class T>
Queue<T>::Queue()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void Queue<T>::Display()
{
    cout<<"Elements of stack are : \n";
    struct nodeQUEUE<T> * temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp -> next;
    }
    cout<<"\n";
}

template <class T>
int Queue<T>::Count()
{
    return iCount;
}

template <class T>
void Queue<T>::EnQueue(T No)
{
    struct nodeQUEUE<T> * newn = NULL;
    struct nodeQUEUE<T> * temp = NULL;

    newn = new nodeQUEUE<T>;

    newn -> data = No;
    newn -> next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}   

template <class T>
int Queue<T>::DeQueue()
{
    int iValue = 0;
    struct nodeQUEUE<T> * temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to pop the element as stack is empty\n";
        return -1;
    }
    else
    {
        temp = First;

        iValue = First -> data;
        First = First -> next;
        delete temp;

        iCount--;
    }
    return iValue;
}

/////////////////////////////////////////////////////////////
//
// Code of Searching and sorting Algorithm
//
/////////////////////////////////////////////////////////////

template <class T>
class ArrayX
{
    public:
        T *Arr;
        int iSize;

        ArrayX(int Value);
        ~ArrayX();

        void Accept();
        void Display();
        
        bool LinearSearch(T Value);
        bool BiDirectionalSearch(T Value);
        bool BinarySearch(T Value);

        void BubbleSort();
        void BubbleSortEfficient();

        void SelectionSort();
};

template <class T>
ArrayX<T>::ArrayX(int Value)
{
    this->iSize = Value;
    this->Arr = new T[iSize];
}

template <class T>
ArrayX<T>::~ArrayX()
{
    delete []Arr;
}

template <class T>
void ArrayX<T>::Accept()
{
    int i = 0;

    cout<<"Enter the elements : \n";
    for(i = 0; i < iSize; i++)
    {
        cin>>Arr[i];
    }
}

template <class T>
void ArrayX<T>::Display()
{
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\t";
    }
}

template <class T>
bool ArrayX<T>::LinearSearch(T Value)
{
    bool flag = false;
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] == Value)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

template <class T>
bool ArrayX<T>::BiDirectionalSearch(T Value)
{
    int iStart = 0, iEnd = 0;
    bool flag = false;

    for(iStart = 0, iEnd = iSize-1; iStart <= iEnd; iStart++, iEnd--)
    {
        if(Arr[iStart] == Value || Arr[iEnd] == Value)
        {
                flag = true;
                break;
        }
    }
    return flag;
}

template <class T>
bool ArrayX<T>::BinarySearch(T Value)
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool flag = false;

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if((Arr[iMid] == Value) || (Arr[iStart] == Value) || (Arr[iEnd] == Value))
        {
            flag = true;
            break;
        }
        else if(Value < Arr[iMid])
        {
            iStart = iMid + 1;
        }
        else if(Value > Arr[iMid])
        {
            iEnd = iMid -1;
        }
    }

    return flag;
}

template <class T>
void ArrayX<T>::BubbleSort()
{
    T temp;
    int i = 0, j = 0;

    //     1        2      3  
    for(i = 0; i < iSize -1; i++)  // Outer
    {   //    1         2         3  
        for(j = 0; j< iSize - 1 - i; j++)   // Inner
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
        cout<<"\nArray after pass : "<<i+1<<"\n";
        Display();
    }
}   

template <class T>
void ArrayX<T>::BubbleSortEfficient()
{
    T temp;
    int i = 0, j = 0;
    bool flag = true;

    //     1        2      3  
    for(i = 0; (i < iSize -1) && (flag == true) ; i++)  // Outer
    {
        flag = false;
           //    1         2         3  
        for(j = 0; j< iSize - 1 - i; j++)   // Inner
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                flag = true;
            }
        }
    
        cout<<"\nArray after pass : "<<i+1<<"\n";
        Display();
    }
}  

template <class T>
void ArrayX<T>::SelectionSort()
{
    int i = 0, j = 0, min_index = 0;
    T temp;

    for(i = 0; i < iSize -1; i++)
    {
        min_index = i;

        for(j = i + 1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j; 
            }
        }
        temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }
}  


int main()
{
    
    return 0;
}