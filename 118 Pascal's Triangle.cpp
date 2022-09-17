// run time best of 100%
vector<vector<int>> generate(int numRows) {
        // создание вектора чтоб не копировать при расширении;
        vector< vector<int> > answ(numRows);
        
        
            
        long long tab[numRows][numRows];
        for(int i = 0; i < numRows; ++i){
            tab[0][i] = 1;
            tab[i][0] = 1;
        }
        
        for(int i = 1; i < numRows; ++i){
            for(int j = 1; j < numRows; ++j){
                tab[i][j] = tab[i - 1][j] + tab[i][j - 1];
            }
        }
        
        for(int i = 0; i < numRows; ++i){
            for(int j = 0; j <= i; ++j){
                answ[i].push_back(tab[i-j][j]);
                //cout << i - j << ":" << j<<" ";
            }
        //cout << endl;
        }
        return answ;
    }
