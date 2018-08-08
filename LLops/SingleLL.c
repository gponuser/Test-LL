#include <stdio.h>



int main()
{
	int Sorted = -1;
	int Option = 0;
	
	while((Sorted != 0) && (Sorted != 1))
		Sorted = getSortTypeOption();
	
	while(Option != 10)
	{
		if(!Sorted)
		{
			Option = getMenuOption();	
			performOperation(Option);
		}
		else
		{
			Option = getSortedMenuOperation();
			performSortedOperation(Option);
		}
		
	}

	return 0;
}
