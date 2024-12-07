// nums = [1,2,4,6,8,9,14,19]
#include <iostream>
#include <vector>
int main()
{
    int nums[] = {1, 2, 4, 6, 8, 9, 14, 19};
    int left = 0;
    int right = sizeof(nums) - 1;
    int target = 13;
    while (left < right)
    {
        int curr = nums[left] + nums[right];
        if (curr == target)
            std::cout << "Target acheived";

        if (curr > target)
            right--;
        if (curr < target)
            left++;
    }
}