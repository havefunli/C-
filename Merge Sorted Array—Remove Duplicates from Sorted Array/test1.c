#define  _CRT_SECURE_NO_WARNINGS 1
int removeDuplicates(int* nums, int numsSize)
{
    int* left = nums;
    int* right = nums + 1;
    int k = 0;

    while (right <= nums + numsSize - 1)
    {
        if (*left == *right)
        {
            right++;
        }
        else
        {
            left++;
            *left = *right;
            right++;
            k++;
        }
    }

    return k + 1;
}