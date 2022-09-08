// стандарное решение предполагало сортировку, я попытался решить без нее 
class Solution {
public:
vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector<int> answ(k);
    int row_size = mat.size();   // кол-во строк
    int col_size = mat[0].size();// кол-во столбцов
    // arr
    int ** m_a = new int * [col_size + 1];
    for(int i =0; i < col_size+1; i++){
        m_a[i] = new int [row_size];
        for(int j = 0; j < row_size; ++j){
            m_a[i][j] = 0;
        }
    }
    // main arr check

    int co;
    for(int i = 0; i < row_size; i++){
        co = 0;
        for(int j = 0; j < col_size; j++){
            if(mat[i][j] == 0)
                break;
            co++;
        }
        //cout << "c_s " << col_size+1 << " r " << row_size<<endl;
        //cout << "co " << co << " i " << i<<endl;
        m_a[co][i] = 1;
    }
    /*
    for(int i =0; i < col_size+1; i++){
        for(int j = 0; j < row_size; ++j){
            cout << m_a[i][j]<<" ";
        }
        cout << endl;
    }
    */

    int co_ind = 0;

    for(int i = 0; i < col_size+1; i++){
        for(int j = 0; j < row_size; j++){
            if(m_a[i][j] == 1){
                answ[co_ind] = j;
                co_ind ++;
                if(co_ind == k){
                    i = col_size+2;
                    j = row_size +1;
                }
            }
        }
    }

    return answ;
}
};
