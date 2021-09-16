#include <vector>
#include <unordered_map>

using namespace std;

bool isValidSudoku(vector<vector<char> > &board)
{
    
    //step1:因为有三种情况，所以考虑创建三个无序哈希表
    unordered_map<int,int>row[9];
    unordered_map<int,int>cloumn[9];
    unordered_map<int,int>box[9];

    //开始遍历数组
    int i,j,num,box_idx;
    for(i = 0;i<9;i++)
    {
        for(j = 0;j<9;j++)
        {
            num = board[i][j] - '0';//把符号数字化，因为我定义的哈希表类型为int类型
            box_idx = (i/3)*3+j/3;//这里确定每个九宫格的顺序，很有意思
            if(board[i][j] != '.')//从第一个数字开始遍历
            {
             if(row[i].find(num) != row[i].end()||
                cloumn[j].find(num) != cloumn[j].end()||
                box[box_idx].find(num) != box[box_idx].end())//如果找到重复的
                return false;
             else//如果找不到，就写进进去
             {
                 row[i][num] = 1;//在第 i 行 ，num 出现了 1 次
                 cloumn[j][num] = 1;
                 box[box_idx][num] = 1;
             }
            }
        }
    }
    return true;
}