class Sums {
public:
//*********************************solution 1****************************//
//暴力解法：遍历数组，求出数组中和为固定值的两数的索引id；                        //
//时间复杂度：O(n2),双层遍历数组                                             //
//空间复杂度：O(1)，未开辟新的内存                                            //
//***********************************************************************//
    vector<int> twoSum_1(vector<int>& nums, int target)
    {
        std::vector<int> solution(2,0);
        for(int i=0; i< nums.size(); ++i)
        {
            for(int j=i+1; j<nums.size(); ++j)
            {
                if(target == (nums[i] + nums[j]))
                   {
                       solution[0] = i;
                       solution[1] = j;
                        return solution;
                   }
            }   
        }
    }
//*********************************solution 2***************************//
//哈希表解法：遍历数组，求出数组中和为固定值的两数的索引id；                      //
//时间复杂度：O(n),只需遍历一次数组                                          //
//空间复杂度：O(n)，开辟新的map内存                                          //
//**********************************************************************//
     vector<int> twoSum_2(vector<int>& nums, int target)
    {
        std::vector<int> solution(2,0);
        std::unordered_map<int, int> hash;
        for(int i=0; i< nums.size(); ++i)
        {
            int component = target - nums[i];
            if(hash.find(component)==hash.end())
            {
                hash[nums[i]]=i;
            }
            else
            {
                if(hash[component]==i)
                continue;
                else
                {
                    solution[0]=i;
                    solution[1]=hash[component];
                    return solution;
                }
            }
        }
    }
};
