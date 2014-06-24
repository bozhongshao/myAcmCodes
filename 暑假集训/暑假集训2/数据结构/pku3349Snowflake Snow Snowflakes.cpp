/*hash�����⣬��Ȼ�м���hash��ģ�壬������ϵ�Լ�д�£��Ա����Ҹ�����������ϵˮ���ˡ�

����������һ������Ҫ��Ұ����cin cout ��ʱ��� scanf printf ��������1000ms ����TLE�󼸴ζ���֪����

�������£�
*/
 

#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
const int N = 9997;//�㹻�������

typedef struct {
    int a[6];
    long sum;
} Node;
vector<Node> vec[N];//hash�ڵ������vector����һ��������

int Compare(Node n1, Node n2) {
    int i, j;
    for (i = 0; i < 6; i++) {
        if (n1.a[0] == n2.a[i]) {
            for (j = 1; j < 6; j++) {
                if (n1.a[j] != n2.a[(i + j) % 6])
                    break;
            }
            if (j == 6) return 1;
            for (j = 1; j < 6; j++) {
                if (n1.a[6 - j] != n2.a[(i + j) % 6])
                    break;
            }
            if (j == 6) return 1;
        }
    }
    return 0;
}

int check() {
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < vec[i].size(); j++) {
            for (k = j + 1; k < vec[i].size(); k++) {
                if (vec[i][j].sum == vec[i][k].sum && Compare(vec[i][j], vec[i][k]))
                    return 1;
            }
        }
    }
    return 0;
}

int main() {
    int n, i;
    Node node;
    scanf("%d", &n);
    while (n--) {
        node.sum = 0;
        for (i = 0; i < 6; i++) {
            scanf("%d", node.a + i);
            node.sum += node.a[i];
        }
        vec[node.sum % N].push_back(node);
    }
    puts(check() ? "Twin snowflakes found." : "No two snowflakes are alike.");
    return 0;
}
