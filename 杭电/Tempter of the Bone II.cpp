/*���͵�һ���Թ������⣬

�������뵽BFS�������ѵ��������Թ���״̬�ı����δ�������⣬

������ҵ��뷨���ȴ���㿪ʼDFS,Ȼ�󵱸ı��Թ���ʱ���Ȳ����������ǽ��ı����Թ�״̬����У��������굱Ȼ�Թ���ʱ���ٳ�����һ�ű仯��ĵ�ͼ����BFS+DFS�ı�����������ͼ��״̬���ö�����ѹ��������ı��λ�ã�Ȼ������״̬̫�࣬MLE��TLE�����ɱ��⡣

����������ţ�㲦���뷨���£�

ֱ��BFS��Ȼ��ֱ�ӴӶ�����ѹ���Թ���״̬��������ǽ�ں�ըҩ�Ĵ�����Ϣ���ڶ�ÿ��״̬����BFS��ʱ��ͬʱ���ݵ�Ȼ�Թ���״̬��������ǽ�ں�ըҩ�Ĵ�����Ϣ��Ȼ������ά��hash����״̬���أ�hash[x][y][ըҩ��]��

31MS ac�ˣ�Ч�����������������㲻��
*/
#include <iostream>
#include <queue>
using namespace std;

struct node
{
    __int64 x, y, step;
    __int64 bomb, flag;
}in, out;

char map[10][10];
__int64 hash[10][10][10];
__int64 r, c;
__int64 finish;

queue<node> all;

int main()
{
    bool find;
    __int64 i, j;
    while (scanf("%I64d %I64d", &r, &c) == 2)
    {
        if (r == 0 && c == 0)
        {
            break;
        }
        memset (hash, 0, sizeof(hash));

        find = false;
        finish = 0x7fffffffff;

        for (i = 0; i < r; i++)
        {
            scanf("%s", map[i]);
            for (j = 0; j < c && !find; j++)
            {
                if (map[i][j] == 'S')
                { 
                    in.x = i;
                    in.y = j;
                    find = true;
                }
            }
        }

        in.step = 0;
        in.bomb = 0;
        in.flag = 0;
        all.push(in);
        while (!all.empty())
        {
            out = all.front();
            all.pop();
            if (out.x < 0 || out.x >= r || out.y < 0 || out.y >= c)
            {
                continue;
            }

            if (hash[out.x][out.y][out.bomb] != 0 && hash[out.x][out.y][out.bomb] < out.step)
            {
                continue;
            }

            hash[out.x][out.y][out.bomb] = out.step;

            if (map[out.x][out.y] == 'D')
            {
                if (out.step < finish)
                {
                    finish = out.step;
                }
                continue;
            }
            else if (map[out.x][out.y] == 'X')
            {
                __int64 pos = __int64(1) << (out.x * c + out.y);
                if ((out.flag & pos) == 0)
                {
                    if (out.bomb == 0)
                    {
                        continue;
                    }
                    out.bomb --;
                    out.step ++;
                    out.flag += pos;
                }
            }
            else if (map[out.x][out.y] > '0' && map[out.x][out.y] <= '9')
            {
                __int64 pos = __int64(1) << (out.x * c + out.y);
                if ((out.flag & pos) == 0)
                {
                    out.bomb += map[out.x][out.y] - '0';
                    out.flag += pos;
                }
            }
            in = out;
            in.x = out.x + 1;
            in.step++;
            all.push(in);

            in = out;
            in.x = out.x - 1;
            in.step++;
            all.push(in);

            in = out;
            in.y = out.y + 1;
            in.step++;
            all.push(in);

            in = out;
            in.y = out.y - 1;
            in.step++;
            all.push(in);
        }
        if (finish == 0x7fffffffff)
        {
            printf("-1\n");
        }
        else
        {
            printf("%I64d\n", finish);
        }
    }    
    return 0;
}
 
