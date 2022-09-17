/*
1й Вариант решения через очередь, хранящая эл из nums1 который меньше nums2 - в худшем случае будет иметь n 
  - работает чуть-чуть медленнее
  + экономичнее по памяти, чем второй вариант
  ((3й вариант)так же есть возможность добавить nums2 в nums1 и отсортировать - самый эффективный вариант по памяти, но может быть дольше по времени)
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
