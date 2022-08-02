class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 1) {
      return 0;
    }

    int start_index = 0;
    int end_index = 0;
    int product_so_far = nums[0];
    int number_of_products = 0;

    while (start_index < nums.size() && end_index < nums.size()) {
      if (product_so_far < k) {
        number_of_products += end_index - start_index + 1;
        ++end_index;
        if (end_index < nums.size()) {
          product_so_far *= nums[end_index];
        }
      } else {
        product_so_far /= nums[start_index];
        ++start_index;
        if (start_index > end_index) {
          end_index = start_index;
          if (end_index < nums.size()) {
            product_so_far = nums[start_index];
          }
        }
      }
    }

    return number_of_products;
  }
};
