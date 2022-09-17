Основываясь на тестах с сайта
В1 >= B2 > B3 (сравнение по скорости и памяти)
/*
1й Вариант решения через очередь, хранящая эл из nums1 который меньше nums2 - в худшем случае будет иметь n 
  - работает чуть-чуть медленнее
  + экономичнее по памяти, чем второй вариант
 
*/
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int a = 0, b = 0;
    queue<int> q;

    for(int i = 0; i < m; ++i){
        if(b < n && nums2[b] < nums1[i]){
            if(!q.empty()){
                if( nums2[b] < q.front()){
                    q.push(nums1[i]);
                    nums1[i] = nums2[b];
                    b++;
                }
                else{
                    q.push(nums1[i]);
                    nums1[i] = q.front();
                    q.pop();
                }
            }
            else{
                q.push(nums1[i]);
                nums1[i] = nums2[b];
                b++;
            }
        }
        else if(!q.empty() && q.front() < nums1[i]){
            q.push(nums1[i]);
            nums1[i] = q.front();
            q.pop();
        }

    }
    //first part end
    for(int i = m; i < m+n; ++i){
        if(!q.empty()){
            if(b < n) {
                if (q.front() < nums2[b]) {
                    nums1[i] = q.front();
                    q.pop();
                } else {
                    nums1[i] = nums2[b];
                    b++;
                }
            }
            else{
                nums1[i] = q.front();
                q.pop();
            }
        }
        else if(b < n){
            nums1[i] = nums2[b];
            b++;
        }
    }


    //nums1 = answ;
    //end
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
2й Вариант решения через доп вектор размера m+n 
  + работает чуть быстрее
  - затратно по памяти
*/
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> answ(n + m);
        int a = 0, b = 0, i = 0;
        while(true){
            if((a < m) && (b < n) ){
                if(nums1[a] < nums2[b]){
                    answ[i] = nums1[a];
                    ++i;
                    ++a;
                }
                else{
                    answ[i] = nums2[b];
                    ++i; 
                    ++b;
                }
            }
            else if((a >= m) && (b >= n)){
                break;
            }
                else{
                    if(a < m ){
                        answ[i] = nums1[a];
                        ++i;
                        ++a;
                    }
                    if(b < n){
                        answ[i] = nums2[b];
                        ++i; 
                        ++b;
                    } 
                }
    
        }
        nums1 = answ;
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 (3й вариант)так же есть возможность добавить nums2 в nums1 и отсортировать
 - может быть не самым эффективном по памяти при вызове рекурсии
 + как показали результаты тестов не самый эффективный по скорости
class Solution {
public:
    template <class T>
void quick_sort(T & arr, size_t L, size_t R ){ //
    if(R - L < 2){return;}
    int base = arr[ (R + L) / 2];
    size_t x = L, y = L;
    for(size_t i = L; i < R; ++i){
        if(arr[i] < base){
            swap(arr[x], arr[i]);
            if(x != y){
                swap(arr[y], arr[i]);
            }
            ++x; ++y;
        }
        else{
            if(arr[i] == base){
                swap(arr[y],arr[i]);
                ++y;
            }
        }
    }
    quick_sort(arr, L, x);
    quick_sort(arr, y, R);
}
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m; i < n+m; ++i ){
            nums1[i] = nums2[i - m];
        }
        quick_sort(nums1, 0, n+m);
    //nums1 = answ;
    //end
}
};
