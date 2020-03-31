//给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, 
//ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。 
//
// 说明：你不能倾斜容器，且 n 的值至少为 2。 
//
// 
//
// 
//
// 图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。 
//
// 
//
// 示例： 
//
// 输入：[1,8,6,2,5,4,8,3,7]
//输出：49 
// Related Topics 数组 双指针


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxArea(vector<int>& height) {
       //*显然n^2的复杂度T了
       /*
        int res = 0;
        for(int i = 0;i < height.size();i ++){
            for(int j = i + 1;j < height.size();j ++){
                res = max(min(height[i],height[j]) * (j - i),res);
            }
        }
        return res;
        */
       /*介绍双指针的解法,由于容量取决于两端高较小的那个和两端的距离.因此可以采用双指针的方法.
        * 首先将两个指针至于数组的左右两端.
        * 怎么移动呢,由于容量取决于距离和较小的那个,距离已经无法改变了,必须要移动一个,那么怎么才能使结果更大,因此应该将较小的那个边舍掉
        */
       int start = 0;
       int end = height.size() - 1;  //注意不要越界grass
       int res = min(height[start],height[end]) * (end - start);
       int tmp;
       while (start != end){
           //高较小的一边向着大的一边移动
           if(height[start] < height[end]){
               res = max(res,height[start] * (end - start));
               start ++;
           }else{
               res = max(res,height[end] * (end - start));
               end --;
           }
       }
        return  res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

/*对于while循环中语句的优化
 * first: {
 *          res = max(res,min(height[start],height[end]) * (end -start));
 *          if(height[start] < height[end]) start ++;
 *          else end --;
 * }
 * 以上代码的运行结果为
 *          解答成功:
			执行耗时:28 ms,击败了36.85% 的C++用户
			内存消耗:9.1 MB,击败了100.00% 的C++用户

 *对该代码端再次进行优化,由于 res = 部分消耗的资源较大,每次都要调用max函数,
 * 将其加入判断语句进行修改,只有大于的时候才进行赋值,运行的结果为:
 * 解答成功:
			执行耗时:24 ms,击败了43.46% 的C++用户
			内存消耗:9.1 MB,击败了100.00% 的C++用户
 *emmm,这个优化好像还是不太理想,再改
 *  if(height[start] < height[end]){
               res = max(res,height[start] * (end - start));
               start ++;
           }else{
               res = max(res,height[end] * (end - start));
               end --;
           }
 *这样可以较少一次判断大小的次数,优化非常的冥想
 * 解答成功:
			执行耗时:12 ms,击败了98.13% 的C++用户
			内存消耗:9 MB,击败了100.00% 的C++用户

 * 从这我们可以看出,即使同一个算法,采用不同的写法,效率的差距还是比较大的
 */
