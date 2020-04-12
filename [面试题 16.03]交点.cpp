//给定两条线段（表示为起点start = {X1, Y1}和终点end = {X2, Y2}），如果它们有交点，请计算其交点，没有交点则返回空值。 
//
// 要求浮点型误差不超过10^-6。若有多个交点（线段重叠）则返回 X 值最小的点，X 坐标相同则返回 Y 值最小的点。 
//
// 
//
// 示例 1： 
//
// 输入：
//line1 = {0, 0}, {1, 0}
//line2 = {1, 1}, {0, -1}
//输出： {0.5, 0}
// 
//
// 示例 2： 
//
// 输入：
//line1 = {0, 0}, {3, 3}
//line2 = {1, 1}, {2, 2}
//输出： {1, 1}
// 
//
// 示例 3： 
//
// 输入：
//line1 = {0, 0}, {1, 1}
//line2 = {1, 0}, {2, 1}
//输出： {}，两条线段没有交点
// 
//
// 
//
// 提示： 
//
// 
// 坐标绝对值不会超过 2^7 
// 输入的坐标均是有效的二维坐标 
// 
// Related Topics 几何 数学


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:


    void Change(vector<int> origin,vector<double>& now){
        now.push_back(double(origin[0]));
        now.push_back(double(origin[1]));
    }

    /* 返回false表示这条直线垂直于x轴*/

    bool Cal(double& k,double& b,vector<double>& start,vector<double>& end){

        if(start[0] > end[0]){   // 规范一下坐标的格式
            swap(start,end);
        }else if(start[0] == end[0] && start[1] > end[1]){
            swap(start,end);
        }

        if(start[0] == end[0]){    // 注意此时线段垂直于x轴.k为无穷大
            return false;
        }

        k = (start[1] - end[1]) / (start[0] - end[0]);
        if(abs(k) <= 1 / 1E6){
            k = 0;
        }

        b = start[1] - k * start[0];
        return true;
    }

    // 用于判断一个点是否在一条线段上
    bool Judge(double x,double y,vector<double> start,vector<double> end){
        if(x >= start[0] && x <= end[0]){
            if((y - start[1]) * (x - end[0]) == (y - end[1]) * (x - start[0])){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }

    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        double k1,b1;
        double k2,b2;
        vector<double> res;

        vector<double> Start1;
        vector<double> End1;
        vector<double> Start2;
        vector<double> End2;

        Change(start1,Start1);
        Change(end1,End1);
        Change(start2,Start2);
        Change(end2,End2);

        // 这里保证了两条线段不会有一条垂直于x轴
        bool bol1 = Cal(k1,b1,Start1,End1);
        bool bol2 = Cal(k2,b2,Start2,End2);

        if(bol1 && bol2){  // 保证两个都不垂直于x轴

            // 平行但不重合的情况
            if(k1 == k2 && b1 != b2){
                return res;
            }

            // 在一条直线上的情况
            if(k1 == k2 && b1 == b2){   // 有多个交点，返回x较小的一个
                // 首先排除没有交点的情况
                bool tmp1 = Judge(Start1[0],Start1[1],Start2,End2);
                bool tmp2 = Judge(Start2[0],Start2[1],Start1,End1);
                cout<<tmp1<<"++++"<<tmp2<<endl;
                if(!tmp1 && !tmp2){     // 虽然在一条直线上，但是没有相交
                    return res;
                }
                if(tmp1){
                    return Start1;
                }else{
                    return Start2;
                }
            }

            // 不平行，求出交点
            if(k1 != k2) {
                double x = (b2 - b1) / (k1 - k2);
                double y = k1 * x + b1;
                // 交点不再两个线段上
                if ((x >= Start1[0] && x <= End1[0]) && (x >= Start2[0] && x <= End2[0])) {
                    res.push_back(x);
                    res.push_back(y);
                    return res;
                } else {
                    return res;
                }
            }
        }

        if(!bol1 && bol2){   // 第一条线段是垂直于x轴的
            double x = Start1[0];
            double y = k2 * x + b2;

            // 交点没在第一条直线上
            if(y > end1[1] || y < start1[1]){
                return res;
            }else{
                if(Judge(x,y,Start2,End2)){
                    res.push_back(x);
                    res.push_back(y);
                    return res;
                }
            }
        }

        if(bol1 && !bol2){   // 第一条线段是垂直于x轴的
            double x = Start2[0];
            double y = k1 * x + b1;

            // 交点没在第一条直线上
            if(y > end2[1] || y < start2[1]){
                return res;
            }else{
                if(Judge(x,y,Start1,End1)){
                    res.push_back(x);
                    res.push_back(y);
                    return res;
                }
            }
        }


        // 两条都垂直于x轴
        if(!bol1 && !bol2){
            if(Start1[0] != Start2[0]){
                return res;
            }

            // 虽然在一条直线上但没有交点的情况
            if(Start1[1] >= Start2[1] && Start1[1] <= End2[1]){
                return Start1;
            }

            if(Start2[1] >= Start1[1] && Start2[1] <= End1[1]){
                return Start2;
            }

            return res;
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
