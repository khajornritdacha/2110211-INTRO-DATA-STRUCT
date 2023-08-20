// Task: CUCAS Rating
// Tag: sorting, vector
// Date: 20/08/23
// Note: Map is not fast enough even though O(nlogn) seems feasible, so we use vector instead.

#include <bits/stdc++.h>
using namespace std;

void get_ans(const vector<pair<string, int>> &vec)
{
    int sum = 0, cnt = 0;
    for (size_t i = 0; i < vec.size(); i++)
    {
        cnt++;
        sum += vec[i].second;
        if (i + 1 == vec.size() || vec[i].first != vec[i + 1].first)
        {
            cout << vec[i].first << " " << 1.0 * sum / cnt << "\n";
            cnt = 0;
            sum = 0;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<string, int>> courses, teachers;
    cout << setprecision(2) << fixed;
    for (int i = 1; i <= n; i++)
    {
        string course_code, teacher_name;
        int score;
        cin >> course_code >> teacher_name >> score;
        courses.push_back({course_code, score});
        teachers.push_back({teacher_name, score});
    }

    sort(courses.begin(), courses.end());
    sort(teachers.begin(), teachers.end());

    get_ans(courses);
    get_ans(teachers);
}
