// change this to your id
static const char* student_id = "0211261" ;

//
// do your homework here
//
//


int index(int n)//2的次方
{
	int num = 1;
	if (n == 0)
	{
		return num;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			num = num * 2;
		}
		return num;
	}
}
int level(int pos)//pos的階層
{
	
	int i = 0,num=0;
	while (true)
	{
		num = num + index(i);
			if (num > pos)
			{
				return i;
				break;
			}
			else
				i++;
	}
}
int sum(int level)//不包括本階層
{
	int num = 0;
	
		for (int i = 0; i < level; i++)
		{
			num = num + index(i);
		}
		return num;
	
}
int left(int pos)
{
	return 2 * pos + 1;
}
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int parent(int pos)
{
	return (pos - 1) / 2;
}
void min_heapify(int * input_array, int size, int position) {
	// I'll give you an array without ordered
	// please adjust the subtree which root is position
	//
	// Example:
	//      input : { 7, 14, 6, 5, 1, 3, 8 } ,7, 2
	//   expected : { 7, 14, 3, 5, 1, 6, 8 }
	
	int l = left(position);
	int r = l + 1;
	int min;
	if (l < size && input_array[l] < input_array[position])
		min = l;
	else
		min = position;
	if (r < size && input_array[r] < input_array[min])
		min = r;
	if (min != position)
	{
		swap(input_array+position, input_array+min);
		min_heapify(input_array, size, min);
	}
		
		

}

void min_heap_build(int * input_array, int size) {
	// I'll give you an array without ordered
	// please make this whole array as a min-heap tree
	//
	// Example:
	//      input : { 7, 14, 6, 5, 1, 3, 8 } ,7
	//   expected : { 1, 5, 3, 7, 14, 6, 8 }
	for (int a = size / 2; a >= 0; a--)
	{
		min_heapify(input_array, size, a);
	
	}

}

void min_heap_insert(int * input_heap, int size, int key) {
	// I'll give you an array which is a min heap has one more space
	// (finally value 999 is not a true value)
	// please change the 999 into key
	// and make this array as a min-heap tree
	//
	// Example:
	//      input : { 1, 5, 3, 7, 14, 6, 8, 999 }, 8, 4
	//   expected : { 1, 4, 3, 5, 14, 6, 8 ,7}
	int position = size - 1;
	input_heap[position] = key;
	while (position > 0 && input_heap[parent(position)] > input_heap[position])
	{
		swap(input_heap+position, input_heap+parent(position));
		position = parent(position);
	}
}

void min_heap_minimum(int * input_heap, int size, int * output_key) {
	// I'll give you an array which is a min heap
	// please show the smallest value
	//
	// Example:
	//      input : { 1, 4, 3, 5, 14, 6, 8 ,7} , 8, &output_key
	//   expected : output_key == 1
		* output_key = input_heap[0];
	
}

void min_heap_extract(int * input_heap, int size, int * output_key) {
	// I'll give you an array which is a min heap
	// please tell me which is the smallest value
	// and delete that value , then adjust as heap
	// (make the final value 999 as fake)
	//
	// Example:
	//      input : { 1, 4, 3, 5, 14, 6, 8 ,7} , 8, &output_key
	//   expected : { 3, 4, 6, 5, 14, 7, 8, 999} ,output_key == 1
	* output_key = input_heap[0];
	int min= input_heap[0];
	input_heap[0] = input_heap[size - 1];
	input_heap[size - 1] = 999;
	min_heapify(input_heap, size-1, 0);
		
}

void min_heap_sort(int* input_heap, int size) {
	//
	// you cannot use library sort function!
	//
	// I'll give you an array which is a min heap
	// please sort it
	//
	// Example:
	//      input : { 1, 4, 3, 5, 14, 6, 8 ,7} ,8
	//   expected : { 1, 3, 4, 5, 6, 7, 8, 14} 
	min_heap_build(input_heap, size);
	int length = size;
	for (int i = size-1; i >= 1; i--)
	{
		swap(input_heap+0, input_heap+i);
		length--;
		min_heapify(input_heap, length, 0);
	}
	int i = 0,j=size-1;
	while (true)
	{
		if (i < j)
		{
			swap(input_heap+i, input_heap+j);
			i++;
			j--;
			continue;
		}
		else
		{
			break;
		}
	}
		
}


void min_heap_decrease_key(int * input_heap, int size, int position, int decrease) {
	// I'll give you an array which is a min heap
	// the position need to be decrease by a value
	// please adjust the result as a min-heap
	//
	// Example:
	//      input : { 1, 4, 3, 5, 14, 6, 8, 7}, 8, 3, 5
	//   expected : { 0, 1, 3, 4, 14, 6, 8, 7}

		input_heap[position] = input_heap[position]-decrease;
		while (position > 0 && input_heap[parent(position)] > input_heap[position])
		{
			swap(input_heap + position, input_heap + parent(position));
			position = parent(position);
		}

	

}
