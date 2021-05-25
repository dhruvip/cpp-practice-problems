#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countCups' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY balls
 *  3. 2D_INTEGER_ARRAY swaps
 *  4. 2D_INTEGER_ARRAY queries
 */

vector<int> countCups(int n, vector<int> balls, vector<vector<int>> swaps, vector<vector<int>> queries) {
    vector <int> res_set;
    vector <bool> cups_with_balls[n];
    for(int i=0; i < balls.size();i++){
        cups_with_balls[balls[i]] = 1;
    }
    for(int i = 0; i < swaps.size(); i++){
        int from_i = swaps[i][0];
        int to_i = swaps[i][1];
        int swap_temp = cups_with_balls[from_i - 1];
        cups_with_balls[from_i - 1] = cups_with_balls[to_i - 1];
        cups_with_balls[to_i - 1] = swap_temp;
    }

    for(int i = 0; i < queries.size(); i++){
        int from = queries[i][0] - 1;
        int to = queries[i][1] - 1;
        for(int j = from;j<=to;j++){

        }

    }
    return res_set;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    int s = stoi(first_multiple_input[2]);

    int q = stoi(first_multiple_input[3]);

    string balls_temp_temp;
    getline(cin, balls_temp_temp);

    vector<string> balls_temp = split(rtrim(balls_temp_temp));

    vector<int> balls(m);

    for (int i = 0; i < m; i++) {
        int balls_item = stoi(balls_temp[i]);

        balls[i] = balls_item;
    }

    vector<vector<int>> swaps(s);

    for (int i = 0; i < s; i++) {
        swaps[i].resize(2);

        string swaps_row_temp_temp;
        getline(cin, swaps_row_temp_temp);

        vector<string> swaps_row_temp = split(rtrim(swaps_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int swaps_row_item = stoi(swaps_row_temp[j]);

            swaps[i][j] = swaps_row_item;
        }
    }

    vector<vector<int>> query(q);

    for (int i = 0; i < q; i++) {
        query[i].resize(2);

        string query_row_temp_temp;
        getline(cin, query_row_temp_temp);

        vector<string> query_row_temp = split(rtrim(query_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int query_row_item = stoi(query_row_temp[j]);

            query[i][j] = query_row_item;
        }
    }

    vector<int> result = countCups(n, balls, swaps, query);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
