#include <iostream>
#include <string>
using namespace std;


void max_heapify(string &a,int index,int size)
{
    int left = 2*index + 1;
    int right = 2*index + 2;
    int smallest=0;
    if (left<size && a[left]<a[index])
    {
	//cout <<a[left]<< "is smaller than"<<a[index]<<" \n";
    smallest=left;
	auto temp = a[index];
	a[index]=a[left];
	a[left]=temp;
	max_heapify(a,smallest,size);
	}
    if (right<size && a[right]<a[index])
	{
	smallest=right;
	//cout <<a[right]<< "is smaller than"<<a[index]<<" \n";
	auto temp = a[index];
	a[index]=a[right];
	a[right]=temp;
	}



}

void create_heap(string &a,int size)
{
//cout << "Starting from:"<<size/2-1<<". index;Value:"<<a[size/2-1]<<"\n";
for (int i=size/2-1;i>=0;i-=1)
{
max_heapify(a,i,size);

}
}

void heap_sort(string &a)
{
int newsize=a.size();
create_heap(a,newsize);
for (int i=a.size()-1;i>=0;i--)
{
	auto newroot= a[0];
	a[0]=a[i];
	a[i]=newroot;
	newsize-=1;
	create_heap(a,newsize);
	cout<<newroot<<"\n";
}
}









int main()
{
string input;
cout << "Enter input without spaces: ";
    getline (cin, input);

for (auto n : input)
{
	cout<<n<<" ";
}
cout<<"\n";
heap_sort(input);
for (auto n : input)
{
	cout<<n<<" ";
}
cout<<"\n";



cout<<"\n";
    return 0;
}