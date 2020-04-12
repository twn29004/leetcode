//设计并实现最不经常使用（LFU）缓存的数据结构。它应该支持以下操作：get 和 put。 
//
// get(key) - 如果键存在于缓存中，则获取键的值（总是正数），否则返回 -1。 
//put(key, value) - 如果键不存在，请设置或插入值。当缓存达到其容量时，它应该在插入新项目之前，使最不经常使用的项目无效。在此问题中，当存在平
//局（即两个或更多个键具有相同使用频率）时，最近最少使用的键将被去除。 
//
// 进阶： 
//你是否可以在 O(1) 时间复杂度内执行两项操作？ 
//
// 示例： 
//
// 
//LFUCache cache = new LFUCache( 2 /* capacity (缓存容量) */ );
//
//cache.put(1, 1);
//cache.put(2, 2);
//cache.get(1);       // 返回 1
//cache.put(3, 3);    // 去除 key 2
//cache.get(2);       // 返回 -1 (未找到key 2)
//cache.get(3);       // 返回 3
//cache.put(4, 4);    // 去除 key 1
//cache.get(1);       // 返回 -1 (未找到 key 1)
//cache.get(3);       // 返回 3
//cache.get(4);       // 返回 4 
// Related Topics 设计


//leetcode submit region begin(Prohibit modification and deletion)

/*
 * 我们需要记录每一个数据得使用情况。然后每次根据这个来删除元素。没更新一次的话，都把他插入到左边。这样每次就找到最后的就好了
 * 即使是两个的应用的次数是一样的，但是删除的一定是最近最少引用的，因为刚引用的再前面
 *
 */
/*
class LFUCache {

    struct node{
        int key;
        int value;
        int cnt;        //引用的次数
        node(){}
        node(int k,int v){
            key = k;
            value = v;
        }
    };
    vector<node> Cache;
    int Capacity;
    int now_cnt;      //现在占有的体积

public:
    LFUCache(int capacity) {
        Capacity = capacity;
        now_cnt = 0;
    }

    void Update(int i,node tmp){
        while(i < now_cnt && tmp.cnt >= Cache[i].cnt){
            i ++;
        }
        if(i == now_cnt){
            Cache.push_back(tmp);
        }else{
            Cache.insert(Cache.begin() + i,tmp);
        }
    }

    int get(int key) {      //get之后是不是要更新一下cnt啊，现在的引用次数
        if(Capacity == 0){
            return -1;
        }
        int i;
        for(i = 0;i < now_cnt;i ++){
            if(Cache[i].key == key){
                break;
            }
        }
        if(i >= now_cnt){
            return -1;
        }
        //然后将cnt更新到合适的位置，由于cnt一直是有序的排列的。我们可能不需要使用二分查找来插入
        node tmp = Cache[i];
        Cache.erase(Cache.begin() + i);   //先将找到的结点删除，更新cnt后插入到新的位置，cnt以升序的方法排列，每次移除可以移除最前端的结点
        tmp.cnt ++;
        Update(i,tmp);
        return tmp.value;
    }

    void put(int key, int value) {
        if(Capacity == 0){
            return;
        }
        //插入之前先看是否存在，但是不能直接使用get,因为get会更新cnt
        int i;
        for(i = 0;i < now_cnt;i ++){
            if(Cache[i].key == key){
                break;
            }
        }
        if(i >= now_cnt){  //说明不存在
            node tmp(key,value);
            tmp.cnt = 1;
            if(now_cnt == Capacity){   //如果已经满了，则需要将最前面的那个干掉
                Cache.erase(Cache.begin());
                now_cnt --;
            }
            int j = 0;
            Update(j,tmp);
            now_cnt ++;
        }else{
            node tmp = Cache[i];
            Cache.erase(Cache.begin() + i); //先删除，更新cnt,再插入
            //先更新value,再更新cnt
            tmp.value = value;
            tmp.cnt ++;
            Update(i,tmp);
        }
    }

 */
    /*
     * 			解答成功:
			执行耗时:1412 ms,击败了5.39% 的C++用户
			内存消耗:35.9 MB,击败了100.00% 的C++用户p
     */

    //写的真是tuoshi,不过感觉Udate那里是可以优化一下，使用二分查找的方式。来提高插入的效率


    //看了官网的题解，为了解决想用引用次数，删除最近最少引用的问题，再node中加入了时间这个个数，当引用次数一样的时候，删除时间较近的。同样典型的空间换时间

    //关于官网使用set的方法，这个应该说是一个非常好的办法，使用双关键字排序。一个关键字是cnt,另一个是time.哎，终究还是菜啊


    //官方题解1，使用STL中的map。至于set我们需要知道的是，这个其实就需要我们对map的实现有一些认识和了解，同时应该还要具备一些关于红黑树的知识

struct Node {
    int cnt, time, key, value;

    Node(int _cnt, int _time, int _key, int _value):cnt(_cnt), time(_time), key(_key), value(_value){}

    bool operator < (const Node& rhs) const {   // 关于这个符号重载还要再加深一下认识
        return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
    }
};
class LFUCache {
    // 缓存容量，时间戳
    int capacity, time;
    unordered_map<int, Node> key_table;
    set<Node> S;
public:
    LFUCache(int _capacity) {
        capacity = _capacity;
        time = 0;
        key_table.clear();
        S.clear();
    }

    int get(int key) {
        if (capacity == 0) return -1;
        auto it = key_table.find(key);
        // 如果哈希表中没有键 key，返回 -1
        if (it == key_table.end()) return -1;
        // 从哈希表中得到旧的缓存
        Node cache = it -> second;
        // 从平衡二叉树中删除旧的缓存
        S.erase(cache);
        // 将旧缓存更新
        cache.cnt += 1;
        cache.time = ++time;
        // 将新缓存重新放入哈希表和平衡二叉树中
        S.insert(cache);
        it -> second = cache;
        return cache.value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = key_table.find(key);
        if (it == key_table.end()) {
            // 如果到达缓存容量上限
            if (key_table.size() == capacity) {
                // 从哈希表和平衡二叉树中删除最近最少使用的缓存
                key_table.erase(S.begin() -> key);
                S.erase(S.begin());
            }
            // 创建新的缓存
            Node cache = Node(1, ++time, key, value);
            // 将新缓存放入哈希表和平衡二叉树中
            key_table.insert(make_pair(key, cache));
            S.insert(cache);
        }
        else {
            // 这里和 get() 函数类似
            Node cache = it -> second;
            S.erase(cache);
            cache.cnt += 1;
            cache.time = ++time;
            cache.value = value;
            S.insert(cache);
            it -> second = cache;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)
