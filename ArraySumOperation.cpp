#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'performOperations' function below.
 *
 * The function is expected to return a LONG_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER N
 *  2. INTEGER_ARRAY op
 */


vector<long> performOperations(int N, vector<int> op) {
    vector<long> sum_array;
    int head_tail[2] = {1, N};
    long middle_sum = 0.5 * (N-2) * (2+(N-1)) ;
    int second_last = N-1;
    int swap = 0; 
    for(auto i=op.begin();i!=op.end();++i){
        // case when the op is within the range
        if(*i>=2 && *i<=second_last) {
            // swap first and last
            swap = head_tail[0];
            head_tail[0] = head_tail[1];
            head_tail[1] = swap;
            // add to the middle_sum
            // append to sum_array
            sum_array.push_back(middle_sum + head_tail[0] + head_tail[1]);

            continue;
        } else if(*i==head_tail[0] || *i==head_tail[1]) {
            // swap first and last
            swap = head_tail[0];
            head_tail[0] = head_tail[1];
            head_tail[1] = swap;
            // add to the middle_sum
            // append to sum_array
            sum_array.push_back(middle_sum + head_tail[0] + head_tail[1]);

            continue;
        }
        // case when the op is not within the range
        else {
            // remove the last elem
            // push op
            // add the sum to middle_sum
            // append sum_array
            head_tail[1] = *i;
            sum_array.push_back(middle_sum + head_tail[0] + head_tail[1]);
        }
    }
    return sum_array;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int N = stoi(first_multiple_input[0]);

    int M = stoi(first_multiple_input[1]);

    vector<int> op(M);

    for (int i = 0; i < M; i++) {
        string op_item_temp;
        getline(cin, op_item_temp);

        int op_item = stoi(ltrim(rtrim(op_item_temp)));

        op[i] = op_item;
    }

    vector<long> result = performOperations(N, op);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];
        cout << result[i] << " ";

        if (i != result.size() - 1) {
            fout << "\n";
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
