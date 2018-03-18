#pragma once
template <typename T>
class HEAP
{

public:                       ////////////////////////
	HEAP(int);               //  HEAP的构造函数    //
	virtual ~HEAP();        //   HEAP的析构函数   //
		                   ////////////////////////
	void CIN();      //为堆输入数据（O(n)）

	void COUT(int);//显示堆内数据排列（按顺序O(n)）

	void MAX_HEAPIFY(int);     //维护最大堆性质（O(lgn)）

	void BUILD_MAX_HEAP();    //建立一个最大堆（O(n)）

	void HEAPSORT();         //堆排序<原址排序>（O(nlgn)）

protected:
    int HeapSize;      //数组中该堆元素的个数//           
    int length;       //     数组长度       //           
    T* HeapArray;    //   指向数组的指针   //

	inline  int PARENT(int i) noexcept { return (i + 1) / 2 - 1; }
	//返回i的父节点
	inline  int LEFT(int i) noexcept { return 2 * (i + 1) - 1; }
	//返回i的左子节点
	inline  int RIGHT(int i) noexcept { return 2 * (i + 1); }
	//返回i的右子节点
};
										   /*___________________________________________*/
										  /*                                           */
										 /*    下面是利用堆排序建立一个最大优先队列   */
										/*                                           */
									   /*___________________________________________*/
	
template <typename T>
class MaxPriorityQueue: protected HEAP<T>
{
	protected:
		MaxPriorityQueue(int);

		~MaxPriorityQueue();
		                                            ///////////////////////////////////////////////
		void MAX_HEAP_INSERT(T key);              //           将x插入到队列中（O(lgn)）         /
										         //                                             /
	    T HEAP_EXTRACT_MAX();                   //返回并去掉队列中具有最大关键词的元素（O(lgn) //
		                                       //                                             //
	    T HEAP_MAXIMUM()const;                //            返回堆最大元素（O(1)）           //
		                                     //                                             //
	    bool HEAP_INCREASE_KEY(int, T key);  //将队列中下标为i的元素关键词增加到key（O(lgn)）
										    //////////////////////////////////////////////// 
};
template <typename T>
HEAP<T>::HEAP(int i)
{
	HeapSize = length = i;
	HeapArray = new T[i];
}

template <typename T>
HEAP<T>::~HEAP()
{
	delete[] HeapArray;
}

template <typename T>
void HEAP<T>::MAX_HEAPIFY(int i)
{
	int left = LEFT(i);
	int right =RIGHT(i);
	int largest;
	if (left < HeapSize && HeapArray[left] > HeapArray[i])
		largest = left;
	else
		largest = i;
	if (right < HeapSize && HeapArray[right] > HeapArray[largest])
		largest = right;
	if (largest != i)
	{
		auto exchange = HeapArray[i];
		HeapArray[i] = HeapArray[largest];
		HeapArray[largest] = exchange;
		MAX_HEAPIFY(largest);
	}
}

template <typename T>
void HEAP<T>::BUILD_MAX_HEAP()
{
	for (int i = length / 2 - 1; i >= 0; i--)
		MAX_HEAPIFY(i);
	return;
}

template <typename T>
void HEAP<T>::HEAPSORT()
{
	for (int i = length - 1; i > 0; i--)
	{
		auto exchange = HeapArray[i];
		HeapArray[i] = HeapArray[0];
		HeapArray[0] = exchange;
		HeapSize--;
		MAX_HEAPIFY(0);
	}
}

template<typename T>
MaxPriorityQueue<T>::MaxPriorityQueue(int i) :HEAP(i) {}

template<typename T>
MaxPriorityQueue<T>::~MaxPriorityQueue() {}

template <typename T>
T MaxPriorityQueue<T>::HEAP_MAXIMUM() const
{
	return HeapArray[0];
}

template <typename T>
T MaxPriorityQueue<T>::HEAP_EXTRACT_MAX()
{
	try
	{
		if (HeapSize < 1)
			throw("heap underflow");
	}
	catch (const char*)
	{
		std::cout << "heap underflow\n";
		std::abort();
	}
	auto max = HeapArray[0];
	HeapArray[0] = HeapArray[--HeapSize];
	MAX_HEAPIFY(heap, 0);
	return max;
}
template <typename T>
bool MaxPriorityQueue<T>::HEAP_INCREASE_KEY(int i, T key)
{
	i--;
	try
	{
		if (key <  HeapArray[i])
			throw("new key is smaller than current key");
	}
	catch (const char*)
	{
		std::cout << "new key is smaller than current key\n";
		std::abort();
	}
	HeapArray[i] = key;
	while (i > 0 && HeapArray[PARENT(i)] <  HeapArray[i])
	{
		auto exchange = HeapArray[i];
		HeapArray[i] = HeapArray[PARENT(i)];
		HeapArray[PARENT(i)] = exchange;
		i = PARENT(i);
	}
	return true;
}
template <typename T>
void MaxPriorityQueue<T>::MAX_HEAP_INSERT(T key)
{
	int i = HeapSize++;
	HeapArray[i] = key;
	while (i > 0 && HeapArray[PARENT(i)] <  HeapArray[i])
	{
		auto exchange = HeapArray[i];
		HeapArray[i] = HeapArray[PARENT(i)];
		HeapArray[PARENT(i)] = exchange;
		i = PARENT(i);
	}
}
template <typename T>
void HEAP<T>::CIN()
{
	for (int i = 0; i < HeapSize; i++)
		std::cin >> HeapArray[i];
}
template <typename T>
void HEAP<T>::COUT(int flag) 
{
	for (int i = 0; i < flag; i++)
		std::cout << HeapArray[i] << " ";
	std::cout << std::endl;
}
