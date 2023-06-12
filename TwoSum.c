void sort(int* arr, int size)
{
  int didSort = 0;
  do
    {
      didSort = 0;
      for(int i=0; i < size-1; i++)
	{
	  if(arr[i] > arr[i+1])
	    {
	      int temp = arr[i];
	      arr[i] = arr[i+1];
	      arr[i+1] = temp;
	      didSort = 1;
	    }
	}
    }while(didSort == 1);
}

int binary_search(int min, int max, int target, int* arr)
{
  while(1)
    {
      int mid = round((max+min)/2);
      //printf("BS: %d %d %d %d %d\n", min, max, mid, arr[mid], target);
      if(arr[mid] == target)
	return mid;
      else if(arr[mid] < target)
	min = mid+1;
      else
	max = mid;
      if(min == max)
	return -1;
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
  int* numCopy = malloc(sizeof(int)*numsSize);
  for(int i=0; i < numsSize; i++)
    numCopy[i] = nums[i];
  *returnSize = 2;
  int* done = malloc(sizeof(int)*(*returnSize));
  sort(nums, numsSize);
  for(int i=0; i < numsSize-1; i++)
    {
      int v = binary_search(i+1, numsSize, (target-nums[i]), nums);
      if(v != -1)
	{
	  int n1 = -1;
	  int n2 = -1;
	  for(int j=0; j < numsSize; j++)
	    {
	      if(nums[i] == numCopy[j] && n1 == -1)
		{
		  n1 = j;
		}
	      else if(nums[v] == numCopy[j] && n2 == -1)
		n2 = j;
	    }
	  done[0] = n1;
	  done[1] = n2;
	  break;
	}
    }
  free(numCopy);
  return done;
}
